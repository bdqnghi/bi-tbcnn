import pickle
import sampling
import random

with open("./data/cpp_algorithms_trees.pkl", 'rb') as fh:
 	# left_trees, _, left_algo_labels = pickle.load(fh)
 	_, left_trees, left_algo_labels = pickle.load(fh)


with open("./data/java_algorithms_trees.pkl", 'rb') as fh:
	# right_trees, _, right_algo_labels = pickle.load(fh)
	_, right_trees, right_algo_labels = pickle.load(fh)


random_left_trees = random.sample(left_trees,1000)

right_merge_sort, right_linked_list, right_quick_sort, right_bfs, right_bubble_sort, right_knapsack = [],[],[],[],[],[]

for inp in right_trees:
	if inp["label"] == "mergesort":
	    right_merge_sort.append(inp)
	if inp["label"] == "linkedlist":
	    right_linked_list.append(inp)
	if inp["label"] == "quicksort":
	    right_quick_sort.append(inp)
	if inp["label"] == "bfs":
	    right_bfs.append(inp)
	if inp["label"] == "bubblesort":
	    right_bubble_sort.append(inp)
	if inp["label"] == "knapsack":
	    right_knapsack.append(inp)

with open("./data/test_cluster.pkl", 'wb') as file_handler:
	pickle.dump((random_left_trees,(random.sample(right_merge_sort,10),random.sample(right_linked_list,10),random.sample(right_quick_sort,10),random.sample(right_bfs,10),random.sample(right_bubble_sort,10),random.sample(right_knapsack,10))), file_handler)
	file_handler.close()

 
