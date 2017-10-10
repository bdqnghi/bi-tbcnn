"""Functions to help with sampling trees."""

import pickle
import numpy as np
import random

def gen_samples(trees, labels, vectors, vector_lookup):
    """Creates a generator that returns a tree in BFS order with each node
    replaced by its vector embedding, and a child lookup table."""

    print "number of trees : "  + str(len(trees))
    # encode labels as one-hot vectors
    label_lookup = {label: _onehot(i, len(labels)) for i, label in enumerate(labels)}
    # print vector_lookup

    for tree in trees:

        nodes = []
        children = []
        label = label_lookup[tree['label']]

        queue = [(tree['tree'], -1)]
        # print queue
        while queue:
            # print "############"
            node, parent_ind = queue.pop(0)
            # print node
            # print parent_ind
            node_ind = len(nodes)
            # print "node ind : " + str(node_ind)
            # add children and the parent index to the queue
            queue.extend([(child, node_ind) for child in node['children']])
            # create a list to store this node's children indices
            children.append([])
            # add this child to its parent's child list
            if parent_ind > -1:
                children[parent_ind].append(node_ind)
            
            node = str(node['node'])
            print "node : " + node

            look_up_vector = vector_lookup[int(node)]
            print "vector look up : " + str(look_up_vector)
            nodes.append(vectors[str(vector_lookup[str(node['node'])])])
        # print "children list length: " + str(len(children))
        yield (nodes, children, label)


def gen_fast_samples(trees, labels, vectors, vector_lookup):
    """Creates a generator that returns a tree in BFS order with each node
    replaced by its vector embedding, and a child lookup table."""

    print "number of trees : "  + str(len(trees))
    # encode labels as one-hot vectors
    label_lookup = {label: _onehot(i, len(labels)) for i, label in enumerate(labels)}
    # print vector_lookup
    # print vectors
    for tree in trees:

        nodes = []
        children = []
        label = label_lookup[tree['label']]

        queue = [(tree['tree'], -1)]
        # print queue
        while queue:
            # print "############"
            node, parent_ind = queue.pop(0)
            # print node
            # print parent_ind
            node_ind = len(nodes)
            # print "node ind : " + str(node_ind)
            # add children and the parent index to the queue
            queue.extend([(child, node_ind) for child in node['children']])
            # create a list to store this node's children indices
            children.append([])
            # add this child to its parent's child list
            if parent_ind > -1:
                children[parent_ind].append(node_ind)
            
            node_index = int(node['node'])
            # print "node : " + str(node_index)

            # print vectors[node_index]
            # look_up_vector = vector_lookup[int(node)]
            # print "vector look up : " + str(look_up_vector)
            nodes.append(vectors[node_index])
        # print "children list length: " + str(len(children))
        yield (nodes, children, label)


def batch_samples(gen, batch_size):
    """Batch samples from a generator"""
    nodes, children, labels = [], [], []
    samples = 0
    for n, c, l in gen:
        # print n
        # print c
        # print l
        nodes.append(n)
        children.append(c)
        labels.append(l)
        samples += 1
        if samples >= batch_size:
            yield _pad_batch(nodes, children, labels)
            nodes, children, labels = [], [], []
            samples = 0

    if nodes:
        yield _pad_batch(nodes, children, labels)

def _pad_batch(nodes, children, labels):
    if not nodes:
        return [], [], []
    max_nodes = max([len(x) for x in nodes])
    max_children = max([len(x) for x in children])
    feature_len = len(nodes[0][0])
    child_len = max([len(c) for n in children for c in n])

    nodes = [n + [[0] * feature_len] * (max_nodes - len(n)) for n in nodes]
    # pad batches so that every batch has the same number of nodes
    children = [n + ([[]] * (max_children - len(n))) for n in children]
    # pad every child sample so every node has the same number of children
    children = [[c + [0] * (child_len - len(c)) for c in sample] for sample in children]

    return nodes, children, labels

def _onehot(i, total):
    return [1.0 if j == i else 0.0 for j in range(total)]
