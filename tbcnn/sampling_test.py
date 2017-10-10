import os
import logging
import pickle
import numpy as np
import tensorflow as tf
import network
import sampling
from sklearn.metrics import classification_report, confusion_matrix, accuracy_score



with open("./data/fast_algorithms_trees.pkl", 'rb') as fh:
    _, trees, labels = pickle.load(fh)

with open("./data/fast_pretrained_vectors.pkl", 'rb') as fh:
    embeddings, embed_lookup = pickle.load(fh)

    # print embeddings
    # print embed_lookup
    num_feats = len(embeddings[0])
    # print num_feats

# print sampling.gen_samples(trees, labels, embeddings, embed_lookup).next()
count = 0
for batch in sampling.batch_samples(sampling.gen_fast_samples(trees, labels, embeddings, embed_lookup), 1):  
    
    nodes, children, batch_labels = batch
    if count == 0:
    	# print nodes
    	print batch_labels
    	print len(nodes)
    	break