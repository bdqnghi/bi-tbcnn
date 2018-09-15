import sys
import pickle
import sampling
import random

# "./data/cpp_algorithms_trees.pkl"
with open(sys.argv[1], 'rb') as fh:
 	#left_trees, _, left_algo_labels = pickle.load(fh)
 	_, left_trees, left_algo_labels = pickle.load(fh)

#"./data/java_algorithms_trees.pkl"
with open(sys.argv[2], 'rb') as fh:
	# right_trees, _, right_algo_labels = pickle.load(fh)
	_, right_trees, right_algo_labels = pickle.load(fh)

all_1_pairs, all_0_pairs = sampling.get_all_pairs_for_training(left_trees,right_trees)
print("1 pairs:" + str(len(all_1_pairs)) + " 0 pairs:" + str(len(all_0_pairs)))

random.shuffle(all_1_pairs)
random.shuffle(all_0_pairs)


random_1_pairs = random.sample(all_1_pairs,200)
random_0_pairs = random.sample(all_0_pairs,200)



all_testing_random_pairs = random_1_pairs + random_0_pairs
random.shuffle(all_testing_random_pairs)
#"./data/4000_testing_pairs.pkl"

with open(sys.argv[3], 'wb') as file_handler:
	pickle.dump(all_testing_random_pairs, file_handler)
	file_handler.close()


