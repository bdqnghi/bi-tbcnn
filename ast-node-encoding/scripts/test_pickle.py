import pickle

with open("./data/algorithm_trees.pkl", 'rb') as f:
    nodes = pickle.load(f)

# print len(vectors[0])
print nodes[5]