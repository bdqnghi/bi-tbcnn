import pickle
with open("/vec/fast_algorithms_trees.pkl", 'rb') as f:
    nodes = pickle.load(f)
print nodes[0]
