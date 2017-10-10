import pickle

with open("./data/fast_algorithms_trees.pkl", 'rb') as f:
    nodes = pickle.load(f)

# print len(vectors[0])
# print nodes[0]["tree"]
print nodes[0]