import pickle

with open("./data/algorithm_trees.pkl","r") as f:
	trees = pickle.load(f)



print "A sample tree : " + str(trees[1][0])

print "total number of trees : " + str(len(trees[0]) + len(trees[1]))
print "training trees : " + str(len(trees[1]))
print "testing trees : " + str(len(trees[0]))
print "number of classes : " + str(len(trees[2])) 