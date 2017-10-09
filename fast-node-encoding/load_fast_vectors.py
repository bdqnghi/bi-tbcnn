import pickle
import gensim
import os
import codecs
from sklearn.manifold import TSNE
from gensim.models.keyedvectors import KeyedVectors
import matplotlib.pyplot as plt

VECTOR_PICKLE = "./data/fast_pretrained_vectors.pkl"
VECTOR_WORD2VEC = "./data/fast_pretrained_vectors.txt"

with open(VECTOR_PICKLE, "rb") as sample_file:
	samples = pickle.load(sample_file)

print samples[0]

def search_dict_by_value(value,node_map):
	result = None
	print "value : " + str(value)
	for index, word in node_map.iteritems():

		if value == index:
			result = word
	return result

def convert_to_word2vec_format(outfile):
	vectors = outfile[0]
	node_map = outfile[1]
	
	with open(VECTOR_WORD2VEC,"a") as f:
		f.write(str(len(node_map)) + " " + str(30) + "\n")

	index = 0
	for vector in vectors:

		
		word = search_dict_by_value(index, node_map)
			
		vector_list = list()
		for feature in vector.ravel():
			# vector_str += str(feature) + " "
			vector_list.append(str(feature))

		row = word + " " + " ".join(vector_list)

		with open(VECTOR_WORD2VEC,"a") as f:
			f.write(row + "\n")
		index += 1

words = list()
for key, value in samples[1].items():
	words.append(value)

words = tuple(words)
convert_to_word2vec_format(samples)	

