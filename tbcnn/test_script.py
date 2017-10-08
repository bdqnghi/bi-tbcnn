import os
import logging
import pickle
import numpy as np
import tensorflow as tf
import network
import sampling
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score


"""Test a classifier to label ASTs"""
logdir = "./tbcnn/logs/1"
with open("./data/algorithm_trees.pkl", 'rb') as fh:
    _, trees, labels = pickle.load(fh)

with open("./data/pretrained_vectors.pkl", 'rb') as fh:
    embeddings, embed_lookup = pickle.load(fh)
    num_feats = len(embeddings[0])

# build the inputs and outputs of the network
nodes_node, children_node, pooling_node, hidden_node = network.init_net(
    num_feats,
    len(labels)
)
print hidden_node
out_node = network.out_layer(hidden_node)

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

correct_labels = []
# make predicitons from the input
predictions = []
step = 0
for batch in sampling.batch_samples(
    sampling.gen_samples(trees, labels, embeddings, embed_lookup), 1
):  
    
    nodes, children, batch_labels = batch
    # hidden_output = sess.run([hidden_node],
    #     feed_dict={
    #         nodes_node: nodes,
    #         children_node: children,
    #     }
    # )
    # print "##################"
    # print hidden_output
    # output = sess.run([out_node],
    #     feed_dict={
    #         nodes_node: nodes,
    #         children_node: children,
    #     }
    # )
    # print output

    pooling_output = sess.run([pooling_node],
        feed_dict={
            nodes_node: nodes,
            children_node: children,
        }
    )
    print len(pooling_output[0][0])
    print pooling_output
    # print np.argmax(output)
    # correct_labels.append(np.argmax(batch_labels))
    # predictions.append(np.argmax(output))
    # print predictions