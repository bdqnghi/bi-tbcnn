import os
import logging
import pickle
import tensorflow as tf
import numpy as np
import siamese_network as network
import sampling as sampling
from parameters import LEARN_RATE, EPOCHS, CHECKPOINT_EVERY, TEST_BATCH_SIZE, DROP_OUT
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score
import operator

def get_one_hot_similarity_label(left_labels, right_labels):
    sim_labels = []
    sim_labels_num = []
    for i in range(0,len(left_labels)):
       
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

def generate_trees_from_cluster(left_trees,right_clusters):
    temp_left_trees = []
    temp_right_trees = []
    for left_tree in left_trees:
        for cluster in right_clusters:
            temp_left_trees.append(left_tree)
            temp_right_trees.append(cluster[0])

    return temp_left_trees, temp_right_trees

def train_model(logdir, inputs, embedfile, epochs=EPOCHS):
    """Train a classifier to label ASTs"""


    n_classess = 2
    left_algo_labels = ['mergesort', 'linkedlist', 'quicksort', 'bfs', 'bubblesort', 'knapsack']
    right_algo_labels = ['mergesort', 'linkedlist', 'quicksort', 'bfs', 'bubblesort', 'knapsack']
  

    with open(inputs, "rb") as fh:
        left_trees, right_clusters = pickle.load(fh)


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
   
    left_trees, right_trees = generate_trees_from_cluster(left_trees,right_clusters)

    correct_labels = []
    predictions = []
    print('Computing training accuracy...')
    for left_gen_batch, right_gen_batch in sampling.batch_siamese_random_samples(left_trees, left_algo_labels, right_trees, right_algo_labels, embeddings, embed_lookup, 6):
        left_nodes, left_children, left_labels_one_hot, left_labels = left_gen_batch


        right_nodes, right_children, right_labels_one_hot, right_labels = right_gen_batch
        sim_labels, _ = get_one_hot_similarity_label(left_labels,right_labels)
        print "############"
        print left_labels
        print right_labels
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
        list_label = []
        for label in output[0]:
            list_label.append(label[1])
        print list_label
        index, value = max(enumerate(list_label), key=operator.itemgetter(1))
        print index
        cluster_name = decide_cluster_by_index(index)

        if left_labels[0] == cluster_name:
            predictions.append(1)
        else:
            predictions.append(0)

    correct = 0
    for pred in predictions:
        if pred == 1:
            correct+=1

    # target_names = ["0","1"]
    print('Accuracy:', float(correct)/float(len(predictions)))
    # print(classification_report(correct_labels, predictions, target_names=target_names))
    # print(confusion_matrix(correct_labels, predictions))

def decide_cluster_by_index(index):
    cluster = ""
    if index == 0:
        cluster = "mergesort"
    if index == 1:
        cluster = "linkedlist"
    if index == 2:
        cluster = "quicksort"
    if index == 3:
        cluster = "bfs"
    if index == 4:
        cluster = "bubblesort"
    if index == 5:
        cluster = "knapsack"
    return cluster

def main():
    logdir = "./tbcnn/logs/5"
  

    embeddings = "./data/fast_pretrained_vectors.pkl"

    test_inputs = "./data/test_clusters.pkl"

    train_model(logdir,test_inputs, embeddings) 

    # train_model(logdir,cpp_inputs, java_inputs, embeddings) 


if __name__ == "__main__":
    main()