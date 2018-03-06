import re
import os
import random
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import GaussianNB
from tqdm import *
from sklearn.metrics import precision_score
from sklearn import linear_model
import re


ROOT_URL = "./code/"

algos = ["bfs","bubblesort","knapsack","linkedlist","mergesort","quicksort","heap","dfs","stack","queue"]
index = [i for i in range(0,10)]
langs = ["cpp","java"]


bfs_cpps = []
bubblesort_cpps = []
knapsack_cpps = []
linkedlist_cpps = []
mergesort_cpps = []
quicksort_cpps = []
heap_cpps = []
dfs_cpps = []
stack_cpps = []
queue_cpps = []

cpps_collection = []
cpps_collection.append(bfs_cpps)
cpps_collection.append(bubblesort_cpps)
cpps_collection.append(knapsack_cpps)
cpps_collection.append(linkedlist_cpps)
cpps_collection.append(mergesort_cpps)
cpps_collection.append(quicksort_cpps)
cpps_collection.append(heap_cpps)
cpps_collection.append(dfs_cpps)
cpps_collection.append(stack_cpps)
cpps_collection.append(queue_cpps)

bfs_javas = []
bubblesort_javas = []
knapsack_javas = []
linkedlist_javas = []
mergesort_javas = []
quicksort_javas = []
heap_javas = []
dfs_javas = []
stack_javas = []
queue_javas = []

javas_collection = []
javas_collection.append(bfs_javas)
javas_collection.append(bubblesort_javas)
javas_collection.append(knapsack_javas)
javas_collection.append(linkedlist_javas)
javas_collection.append(mergesort_javas)
javas_collection.append(quicksort_javas)
javas_collection.append(heap_javas)
javas_collection.append(dfs_javas)
javas_collection.append(stack_javas)
javas_collection.append(queue_javas)


def get_corresponding_java_list(index):
    return javas_collection[index]

def get_non_corresponding_java_list(index):
	temp = []
	for i,collection in enumerate(javas_collection):
		if i != index:
			temp.extend(collection)
	print len(temp)
	return temp

def removeComments(string):
    string = re.sub(re.compile("/\*.*?\*/",re.DOTALL ) ,"" ,string) # remove all occurance streamed comments (/*COMMENT */) from string
    string = re.sub(re.compile("//.*?\n" ) ,"" ,string) # remove all occurance singleline comments (//COMMENT\n ) from string
    return string

for root, subdirs, files in os.walk(ROOT_URL):
    for file in files:
    	path = os.path.join(root,file)
    	splits = path.split("/")
    	label = splits[2]
    	lang = splits[3]
    	with open(path,"rb") as f:
            data = f.read()
            data = str(data)
            
            data = removeComments(data)
            data = re.sub('\W+',' ', data )
            data = re.sub("[0-9]+"," ", data)
            data = data.lower()
            data = data.replace(",","").replace(";","")
            splits = data.split()
            splits = [ x for x in splits if not x.isdigit() ]
            splits = [ x.replace("_"," ") for x in splits ]
            print len(splits)

        if len(splits) > 30:
        	data = " ".join(splits)
        	if lang == "java":
        		if label == "bfs":
        			bfs_javas.append(data)
        		if label == "bubblesort":
        			bubblesort_javas.append(data)
        		if label == "knapsack":
        			knapsack_javas.append(data)
        		if label == "linkedlist":
        			linkedlist_javas.append(data)
        		if label == "mergesort":
        			mergesort_javas.append(data)
        		if label == "quicksort":
        			quicksort_javas.append(data)
        		if label == "heap":
        			heap_javas.append(data)
        		if label == "dfs":
        			dfs_javas.append(data)
        		if label == "stack":
        			stack_javas.append(data)
        		if label == "queue":
        			queue_javas.append(data)
	    	if lang == "cpp":
	    		if label == "bfs":
	    			bfs_cpps.append(data)
	    		if label == "bubblesort":
	    			bubblesort_cpps.append(data)
	    		if label == "knapsack":
	    			knapsack_cpps.append(data)
	    		if label == "linkedlist":
	    			linkedlist_cpps.append(data)
	    		if label == "mergesort":
	    			mergesort_cpps.append(data)
	    		if label == "quicksort":
	    			quicksort_cpps.append(data)
	    		if label == "heap":
	    			heap_cpps.append(data)
	    		if label == "dfs":
	    			dfs_cpps.append(data)
	    		if label == "stack":
	    			stack_cpps.append(data)
	    		if label == "queue":
	    			queue_cpps.append(data)

NUM_SAMPLE = 3
records = []

for i, cpps_list  in enumerate(cpps_collection):
	corresponding_java_lists = get_corresponding_java_list(i)
	non_corresponding_java_list = get_non_corresponding_java_list(i)
	for c in cpps_list:
		random_corresponding_javas = random.sample(corresponding_java_lists,1)
		for j in random_corresponding_javas:
			r = []
			r.append(str(c))
			r.append(str(j))
			r.append("1")
			records.append(r)
		random_non_corresponding_javas = random.sample(non_corresponding_java_list,1)
		for j2 in random_non_corresponding_javas:
			r = []
			r.append(str(c))
			r.append(str(j2))
			r.append("0")
			records.append(r)
for r in records:
	with open("./corpus/pairs2.csv","a") as f:
		# print r
		line = ",".join(r)
		f.write(line +"\n")

# for c in random_bfs_cpps:
# 	random_bfs_javas = random.sample(bfs_javas,NUM_SAMPLE)
# 	for j in random_bfs_javas:
# 		r = []
# 		r.append(c)
# 		r.append(j)
# 		r.append("1")
# 		records.append(r)

# 	random_bublesort_javas = random.sample(bubblesort_javas,NUM_SAMPLE)
# 	for j2 in random_bublesort_javas:
# 		r = []
# 		r.append(c)
# 		r.append(j2)
# 		r.append("0")
# 		records.append(r)


# random_bublesort_cpps = random.sample(bubblesort_cpps,NUM_SAMPLE)
# for c in random_bublesort_cpps:
# 	random_bubblesort_javas = random.sample(bubblesort_javas,NUM_SAMPLE)
# 	for j in random_bubblesort_javas:
# 		r = []
# 		r.append(c)
# 		r.append(j)
# 		r.append("1")
# 		records.append(r)

# 	random_dfs_javas = random.sample(dfs_javas,NUM_SAMPLE)
# 	for j2 in random_dfs_javas:
# 		r = []
# 		r.append(c)
# 		r.append(j2)
# 		r.append("0")
# 		records.append(r)



# random_knapsack_cpps = random.sample(knapsack_cpps,NUM_SAMPLE)
# for c in random_knapsack_cpps:
# 	random_knapsack_javas = random.sample(knapsack_javas,NUM_SAMPLE)
# 	for j in random_bubblesort_javas:
# 		r = []
# 		r.append(c)
# 		r.append(j)
# 		r.append("1")
# 		records.append(r)

# 	random_dfs_javas = random.sample(dfs_javas,NUM_SAMPLE)
# 	for j2 in random_dfs_javas:
# 		r = []
# 		r.append(c)
# 		r.append(j2)
# 		r.append("0")
# 		records.append(r)











