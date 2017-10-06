import pickle

with open("./data/algorithms.pkl", 'rb') as f:
    nodes = pickle.load(f)

# print len(vectors[0])
print len(nodes)