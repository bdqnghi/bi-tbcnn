import os
import logging
import pickle
import tensorflow as tf
import numpy as np
import network as network
import sampling as sampling
from parameters import LEARN_RATE, EPOCHS, CHECKPOINT_EVERY, BATCH_SIZE
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score

def train_model(logdir, infile, embedfile, epochs=EPOCHS):
    """Train a classifier to label ASTs"""


    n_classess = 2

    with open(infile, 'rb') as fh:
        trees, _, labels = pickle.load(fh)

    with open(embedfile, 'rb') as fh:
        embeddings, embed_lookup = pickle.load(fh)
        num_feats = len(embeddings[0])

    # build the inputs and outputs of the network
    left_nodes_node, left_children_node, left_pooling_node = network.init_net_for_siamese(
        num_feats, "left_inputs", "left_network"
    )

    right_nodes_node, right_children_node, right_pooling_node = network.init_net_for_siamese(
        num_feats, "right_inputs", "right_network"
    )

    merge_node = tf.concat([left_pooling_node, right_pooling_node], -1)


    hidden_node = network.hidden_layer(merge_node, 200, n_classess)


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

    for epoch in range(1, epochs+1):
        for i, left_batch in enumerate(sampling.batch_samples(sampling.gen_samples(trees, labels, embeddings, embed_lookup), BATCH_SIZE)):
            left_nodes, left_children, left_labels = left_batch
            _, err, out = sess.run(
                [train_step, loss_node, out_node],
                feed_dict={
                    left_nodes_node: left_nodes,
                    left_children_node: left_children,
                    right_nodes_node: left_nodes,
                    right_children_node: left_children,
                    labels_node: [[0.0,1.0]]
                }
            )
            # print "hidden : " + str(loss)
            print('Epoch:', epoch,
                  'Loss:', err,                  
            )

   
def main():
    logdir = "./tbcnn/logs/2"
    inputs = "./data/algorithm_trees.pkl"
    embeddings = "./data/pretrained_vectors.pkl"
    train_model(logdir,inputs,embeddings) 


if __name__ == "__main__":
    main()