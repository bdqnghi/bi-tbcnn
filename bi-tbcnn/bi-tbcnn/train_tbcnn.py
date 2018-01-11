# This file is just another version to test with 2 different AST tree on each side of the Bi-TBCNN
import os
import logging
import pickle
import tensorflow as tf
import numpy as np
import network as network
import sampling as sampling
from parameters import LEARN_RATE, EPOCHS, CHECKPOINT_EVERY, BATCH_SIZE, DROP_OUT
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
import random
import sys
import json

# os.environ['CUDA_VISIBLE_DEVICES'] = '0,1,2,3,4,5,6,7'
#os.environ['CUDA_VISIBLE_DEVICES'] = "-1"

# device = "/cpu:0"
# device = "/device:GPU:0"
def get_one_hot_similarity_label(left_labels, right_labels):
    sim_labels = []
    sim_labels_num = []
    for i in range(0,len(left_labels)):
        #print left_labels[i] + "," + right_labels[i]
        if left_labels[i] == right_labels[i]:    
            sim_labels.append([0.0,1.0])
            sim_labels_num.append(1)
        else:
            sim_labels.append([1.0,0.0])
            sim_labels_num.append(0)
    return sim_labels, sim_labels_num


def get_trees_from_pairs(label_1_pairs,labeL_0_pairs):
    all_pairs = label_1_pairs + labeL_0_pairs
    random.shuffle(all_pairs)
    left_trees = []
    right_trees = []
    for pair in all_pairs:
        left_trees.append(pair[0])
        right_trees.append(pair[1])
    return left_trees, right_trees

def generate_random_batch(iterable,size):
    l = len(iterable)
    for ndx in range(0, l, n):
        yield iterable[ndx:min(ndx + n, l)]


def train_model(logdir, inputs, left_embedfile, right_embedfile, epochs=EPOCHS, with_drop_out=1,device="-1"):
    os.environ['CUDA_VISIBLE_DEVICES'] = device
    
    print("Using device : " + device)
    
    if int(with_drop_out) == 1:
        print("Training with drop out rate : " + str(DROP_OUT))
    n_classess = 2
    # left_algo_labels = ["bfs","bubblesort","knapsack","linkedlist","mergesort","quicksort","heap","dfs","stack","queue"]
    # right_algo_labels = ["bfs","bubblesort","knapsack","linkedlist","mergesort","quicksort","heap","dfs","stack","queue"]

    left_algo_labels = ["bfs","bubblesort","knapsack","linkedlist","mergesort","quicksort"]
    right_algo_labels = ["bfs","bubblesort","knapsack","linkedlist","mergesort","quicksort"]
    # with open(left_inputs, 'rb') as fh:
    #     left_trees, _, left_algo_labels = pickle.load(fh)


    # with open(right_inputs, 'rb') as fh:
    #     right_trees, _, right_algo_labels = pickle.load(fh)
    print("Loading training data....")
    # print "Using device : " + device
    with open(inputs, "rb") as fh:
        all_1_pairs, all_0_pairs = pickle.load(fh)

    # print "Shuffling training data"
    # random.shuffle(all_1_pairs)
    # random.shuffle(all_0_pairs)

    print("Loading embdding vectors....")
    with open(left_embedfile, 'rb') as fh:
        left_embeddings, left_embed_lookup = pickle.load(fh)
        
    with open(right_embedfile, 'rb') as fh:
        right_embeddings, right_embed_lookup = pickle.load(fh)

    num_feats = len(left_embeddings[0])

    # build the inputs and outputs of the network
    left_nodes_node, left_children_node, left_pooling_node = network.init_net_for_siamese(
        num_feats
    )

    right_nodes_node, right_children_node, right_pooling_node = network.init_net_for_siamese(
        num_feats
    )
    # with tf.device(device):
    merge_node = tf.concat([left_pooling_node, right_pooling_node], -1)

    hidden_node = network.hidden_layer(merge_node, 200, 200)
    if int(with_drop_out) == 1:
        hidden_node = tf.layers.dropout(hidden_node, rate=DROP_OUT, training=True)

    hidden_node = network.hidden_layer(hidden_node, 200, 200)

    if int(with_drop_out) == 1:
        hidden_node = tf.layers.dropout(hidden_node, rate=DROP_OUT, training=True)

    hidden_node = network.hidden_layer(hidden_node, 200, n_classess)

    if int(with_drop_out) == 1:
        hidden_node = tf.layers.dropout(hidden_node, rate=DROP_OUT, training=True)

    out_node = network.out_layer(hidden_node)

    labels_node, loss_node = network.loss_layer(hidden_node, n_classess)

    optimizer = tf.train.AdamOptimizer(LEARN_RATE)
    train_step = optimizer.minimize(loss_node)

    # tf.summary.scalar('loss', loss_node)

    # correct_prediction = tf.equal(tf.argmax(out_node,1), tf.argmax(labels_node,1))
    # accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

    ### init the graph
    # config = tf.ConfigProto(allow_soft_placement=True)
    # config.gpu_options.allocator_type = 'BFC'
    # config.gpu_options.per_process_gpu_memory_fraction = 0.9

    # sess = tf.Session(config = config)

    sess = tf.Session()
    sess.run(tf.global_variables_initializer())

    with tf.name_scope('saver'):
        saver = tf.train.Saver()
        summaries = tf.summary.merge_all()
        writer = tf.summary.FileWriter(logdir, sess.graph)
        ckpt = tf.train.get_checkpoint_state(logdir)
        if ckpt and ckpt.model_checkpoint_path:
            print("Continue training with old model")
            saver.restore(sess, ckpt.model_checkpoint_path)
        # else:
        #     raise 'Checkpoint not found.'

    checkfile = os.path.join(logdir, 'cnn_tree.ckpt')
    steps = 0   

    using_vector_lookup_left = False
    if os.path.isfile("/input/config.json"):
        file_handler = open(config_file, 'r')
        contents = json.load(file_handler)
        using_vector_lookup_left = contents['using_vector_lookup_left'] == "false"

    print("Begin training....")

    # with tf.device(device):
    for epoch in range(1, epochs+1):
        sample_1_pairs = random.sample(all_1_pairs,1000)
        sample_0_pairs = random.sample(all_0_pairs,1000)
        shuffle_left_trees, shuffle_right_trees = get_trees_from_pairs(sample_1_pairs,sample_0_pairs)
        print("Left left:",len(shuffle_left_trees),"Len right:",len(shuffle_right_trees))
        for left_gen_batch, right_gen_batch in sampling.batch_random_samples_2_sides(shuffle_left_trees, left_algo_labels, shuffle_right_trees, right_algo_labels, left_embeddings, left_embed_lookup, right_embeddings, right_embed_lookup, using_vector_lookup_left, False, BATCH_SIZE):
            print("----------------------------------------------------")
            left_nodes, left_children, left_labels_one_hot, left_labels = left_gen_batch

            right_nodes, right_children, right_labels_one_hot, right_labels = right_gen_batch

            sim_labels, sim_labels_num = get_one_hot_similarity_label(left_labels,right_labels)
            print(sim_labels)

                
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
            print('Epoch:', epoch,'Steps:', steps,'Loss:', err, "True Label vs Predicted Label:", zip(labs,out))
         

            if steps % CHECKPOINT_EVERY == 0:
                # save state so we can resume later
                saver.save(sess, os.path.join(checkfile), steps)
                print('Checkpoint saved.')

    
            steps+=1
        steps = 0

def main():
        
    # example params : 
        # argv[1] = ./bi-tbcnn/bi-tbcnn/logs/1
        # argv[2] = ./sample_pickle_data/all_training_pairs.pkl
        # argv[3] = ./sample_pickle_data/python_pretrained_vectors.pkl
        # argv[4] = ./sample_pickle_data/fast_pretrained_vectors.pkl
        # argv[5] = 1
    train_model(sys.argv[1],sys.argv[2],sys.argv[3], sys.argv[4],EPOCHS, sys.argv[5],sys.argv[6])
    


if __name__ == "__main__":
    main()
