import os
import logging
import pickle
import tensorflow as tf
import numpy as np
import siamese_network as network
import sampling as sampling
from parameters import LEARN_RATE, EPOCHS, CHECKPOINT_EVERY, TEST_BATCH_SIZE, DROP_OUT
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score

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

def get_trees_from_pairs(all_pairs):

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
    #     _, left_trees, left_algo_labels = pickle.load(fh)


    # with open(right_inputs, 'rb') as fh:
    #     _, right_trees, right_algo_labels = pickle.load(fh)

    with open(inputs, "rb") as fh:
        testing_pairs = pickle.load(fh)


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
        ckpt = tf.train.get_checkpoint_state(logdir)
        if ckpt and ckpt.model_checkpoint_path:
            saver.restore(sess, ckpt.model_checkpoint_path)
        else:
            raise 'Checkpoint not found.'

    checkfile = os.path.join(logdir, 'cnn_tree.ckpt')
    steps = 0

    print "Preparing data..."
    # temp_zip = sampling.produce_test_pairwise_data(left_trees,right_trees)

    # left_trees, right_trees = zip(*temp_zip)
    left_trees, right_trees = get_trees_from_pairs(testing_pairs)

    correct_labels = []
    predictions = []
    print('Computing training accuracy...')
    for left_gen_batch, right_gen_batch in sampling.batch_siamese_random_samples(left_trees, left_algo_labels, right_trees, right_algo_labels, embeddings, embed_lookup, TEST_BATCH_SIZE):
        left_nodes, left_children, left_labels_one_hot, left_labels = left_gen_batch

        right_nodes, right_children, right_labels_one_hot, right_labels = right_gen_batch
        sim_labels, _ = get_one_hot_similarity_label(left_labels,right_labels)
           
        output = sess.run([out_node],
            feed_dict={
                left_nodes_node: left_nodes,
                left_children_node: left_children,
                right_nodes_node: right_nodes,
                right_children_node: right_children,
                labels_node: sim_labels
            }
        )
        print('Out:', output)
        correct_labels.append(np.argmax(sim_labels[0]))
        predictions.append(np.argmax(output[0]))

    target_names = ["0","1"]
    print('Accuracy:', accuracy_score(correct_labels, predictions))
    print(classification_report(correct_labels, predictions, target_names=target_names))
    print(confusion_matrix(correct_labels, predictions))

   
def main():
    logdir = "./tbcnn/logs/5"
    # cpp_inputs = "./data/cpp_algorithms_trees.pkl"

    # java_inputs = "./data/java_algorithms_trees.pkl"

    embeddings = "./data/fast_pretrained_vectors.pkl"

    test_inputs = "./data/4000_testing_pairs.pkl"

    train_model(logdir,test_inputs, embeddings) 

    # train_model(logdir,cpp_inputs, java_inputs, embeddings) 


if __name__ == "__main__":
    main()