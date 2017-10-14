import os
import logging
import pickle
import tensorflow as tf
import numpy as np
import siamese_network as network
import sampling as sampling
from parameters import LEARN_RATE, EPOCHS, CHECKPOINT_EVERY, BATCH_SIZE, DROP_OUT
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
import random
import sys
def get_one_hot_similarity_label(left_labels, right_labels):
    sim_labels = []
    sim_labels_num = []
    for i in range(0,len(left_labels)):
        print left_labels[i] + "," + right_labels[i]
        if left_labels[i] == right_labels[i]:
            sim_labels.append([0.0,1.0])
            sim_labels_num.append(1)
        else:
            sim_labels.append([1.0,0.0])
            sim_labels_num.append(0)
    return sim_labels, sim_labels_num


# def get_one_hot_similarity_label(left_labels, right_labels):
#     sim_labels = []
#     sim_labels_num = []
#     for left in left_labels:
#         for right in right_labels:
#             if left == right:
#                 sim_labels.append([0.0,1.0])
#                 sim_labels_num.append(1)
#             else:
#                 sim_labels.append([1.0,0.0])
#                 sim_labels_num.append(0)
#     return sim_labels, sim_labels_num

def get_trees_from_pairs(label_1_pairs,labeL_0_pairs):
    all_pairs = label_1_pairs + labeL_0_pairs
    random.shuffle(all_pairs)
    left_trees = []
    right_trees = []
    for pair in all_pairs:
        left_trees.append(pair[0])
        right_trees.append(pair[1])
    return left_trees, right_trees


def train_model(logdir, inputs, embedfile, epochs=EPOCHS):

    """Train a classifier to label ASTs"""


    n_classess = 2
    left_algo_labels = ['mergesort', 'linkedlist', 'quicksort', 'bfs', 'bubblesort', 'knapsack']
    right_algo_labels = ['mergesort', 'linkedlist', 'quicksort', 'bfs', 'bubblesort', 'knapsack']
    # with open(left_inputs, 'rb') as fh:
    #     left_trees, _, left_algo_labels = pickle.load(fh)


    # with open(right_inputs, 'rb') as fh:
    #     right_trees, _, right_algo_labels = pickle.load(fh)

    with open(inputs, "rb") as fh:
        all_1_pairs, all_0_pairs = pickle.load(fh)

    with open(embedfile, 'rb') as fh:
        embeddings, embed_lookup = pickle.load(fh)
        num_feats = len(embeddings[0])

    # build the inputs and outputs of the network
    left_nodes_node, left_children_node, left_pooling_node = network.init_net_for_siamese(
        num_feats
    )

    right_nodes_node, right_children_node, right_pooling_node = network.init_net_for_siamese(
        num_feats
    )

    merge_node = tf.concat([left_pooling_node, right_pooling_node], -1)

    hidden_node = network.hidden_layer(merge_node, 200, 200)
    hidden_node = tf.layers.dropout(hidden_node, rate=DROP_OUT, training=False)

    hidden_node = network.hidden_layer(hidden_node, 200, 200)
    hidden_node = tf.layers.dropout(hidden_node, rate=DROP_OUT, training=False)

    hidden_node = network.hidden_layer(hidden_node, 200, n_classess)


    out_node = network.out_layer(hidden_node)

    labels_node, loss_node = network.loss_layer(hidden_node, n_classess)

    optimizer = tf.train.AdamOptimizer(LEARN_RATE)
    train_step = optimizer.minimize(loss_node)

    # tf.summary.scalar('loss', loss_node)

    ### init the graph
    sess = tf.Session()#config=tf.ConfigProto(device_count={'GPU':0}))
    sess.run(tf.global_variables_initializer())

    with tf.name_scope('saver'):
        saver = tf.train.Saver()
        summaries = tf.summary.merge_all()
        writer = tf.summary.FileWriter(logdir, sess.graph)
        ckpt = tf.train.get_checkpoint_state(logdir)
        if ckpt and ckpt.model_checkpoint_path:
            print "Continue training with old model"
            saver.restore(sess, ckpt.model_checkpoint_path)
        # else:
        #     raise 'Checkpoint not found.'

    checkfile = os.path.join(logdir, 'cnn_tree.ckpt')
    steps = 0

    print "Preparing data..."
    # temp_zip = sampling.produce_train_pairwise_data(left_trees,right_trees)
   

    print "Finish prepraring....."
    for epoch in range(1, epochs+1):
        sample_1_pairs = random.sample(all_1_pairs,1000)
        sample_0_pairs = random.sample(all_0_pairs,1000)
        shuffle_left_trees, shuffle_right_trees = get_trees_from_pairs(sample_1_pairs,sample_0_pairs)
        print("Left left:",len(shuffle_left_trees),"Len right:",len(shuffle_right_trees))
        for left_gen_batch, right_gen_batch in sampling.batch_siamese_random_samples(shuffle_left_trees, left_algo_labels, shuffle_right_trees, right_algo_labels, embeddings, embed_lookup, BATCH_SIZE):
            
            left_nodes, left_children, left_labels_one_hot, left_labels = left_gen_batch

            right_nodes, right_children, right_labels_one_hot, right_labels = right_gen_batch

            sim_labels, sim_labels_num = get_one_hot_similarity_label(left_labels,right_labels)
            _, err, out, merge, labs, left_pooling = sess.run(
                [train_step, loss_node, out_node, merge_node, labels_node, left_pooling_node],
                feed_dict={
                    left_nodes_node: left_nodes,
                    left_children_node: left_children,
                    right_nodes_node: right_nodes,
                    right_children_node: right_children,
                    labels_node: sim_labels
                }
            )
            # print "hidden : " + str(loss)
            print('Epoch:', epoch,'Steps:', steps,'Loss:', err, "True Label:", labs, "Predicted Label:", out)
         

            if steps % CHECKPOINT_EVERY == 0:
                # save state so we can resume later
                saver.save(sess, os.path.join(checkfile), steps)
                print('Checkpoint saved.')

    
            steps+=1
        steps = 0
   
def main():
    logdir = "./tbcnn/logs/yijun"
  
    embeddings = "./data/fast_pretrained_vectors.pkl"

    all_pairs_input = "./data/all_training_pairs.pkl"

    # train_model(logdir,all_pairs_input, embeddings) 

    train_model(sys.argv[0],sys.argv[1],sys.argv[2])
    


if __name__ == "__main__":
    main()