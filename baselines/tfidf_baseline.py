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
# from sklearn.datasets import fetch_20newsgroups
# np.set_printoptions(threshold=np.nan)
corpus = ["hero zero","This are dog"]

tfidf_vectorizer = TfidfVectorizer(min_df=1)
# count_vectorizer = CountVectorizer()
# X_train_count = count_vectorizer.fit_transform(corpus)
# X_train_tfidf = tfidf_vectorizer.fit_transform(corpus)

# print count_vectorizer.get_feature_names()
# print X_train_count.toarray()

# categories = ['alt.atheism', 'soc.religion.christian','comp.graphics', 'sci.med']

# twenty_train = fetch_20newsgroups(subset='train',categories=categories, shuffle=True, random_state=42)

# print twenty_train.data

# X_train_counts = count_vectorizer.fit_transform(twenty_train.data)
ROOT_URL = "./code/"

algos = ["bfs","bubblesort","knapsack","linkedlist","mergesort","quicksort","heap","dfs","stack","queue"]
langs = ["cpp","java"]
# all_train_cpp_dict = []
# all_train_java_dict = []
# all_test_cpp_dict = []
# all_test_java_dict = []

all_cpp_dict = []
all_java_dict = []

for a in algos:
   
    cpp_docs_list = []
    cpp_labels_list = []
    java_docs_list = []
    java_labels_list = []

    for lang in langs:
        algo_directory = os.path.join(ROOT_URL,a,lang)
        # print algo_directory
        for file in os.listdir(algo_directory):
          
            path = os.path.join(algo_directory,file)
            # print path
            splits = path.split("/")
            label = splits[2]
            lang = splits[3]
            if lang == "java":
                with open(path,"rb") as java_f:
                    data = java_f.read()
                    data = str(data)           
                    data= " ".join(data.split())
                    java_docs_list.append(data)
                    java_labels_list.append(label)
            if lang == "cpp":
                with open(path,"rb") as cpp_f:
                    data = cpp_f.read()
                    data = str(data)           
                    data= " ".join(data.split())
                    cpp_docs_list.append(data)
                    cpp_labels_list.append(label)
    # print cpp_labels_list

    cpp_dict = list(zip(cpp_docs_list,cpp_labels_list))
    java_dict = list(zip(java_docs_list,java_labels_list))
    
    all_cpp_dict.extend(cpp_dict)
    all_java_dict.extend(java_dict)
   
    # train_cpp_percentage = (len(cpp_dict)/10)*8
    # train_cpp_dict = cpp_dict[:train_cpp_percentage]
    # test_cpp_dict = cpp_dict[train_cpp_percentage:len(cpp_dict)]
    # print len(cpp_dict)
    # all_train_cpp_dict.extend(train_cpp_dict)
    # all_test_cpp_dict.extend(test_cpp_dict)

    # train_java_percentage = (len(java_dict)/10)*8
    # train_java_dict = java_dict[:train_java_percentage]
    # test_java_dict = java_dict[train_java_percentage:len(java_dict)]

    # all_train_java_dict.extend(train_java_dict)
    # all_test_java_dict.extend(test_java_dict)

print "Length of train cpp : " + str(len(all_cpp_dict))
print "Length of train java : " + str(len(all_java_dict))

print "Finish preparing training and testing pairs........"

all_cpp_dict = random.sample(all_cpp_dict,300)
all_java_dict = random.sample(all_java_dict,300)

all_cpp_train, all_cpp_label = zip(*all_cpp_dict)
all_java_train, all_java_label = zip(*all_java_dict)



# all_cpp_test, all_cpp_label = zip(*all_train_cpp_dict)
# all_java_test, all_java_label = zip(*all_train_java_dict)



# cpp_count_vectorizer = CountVectorizer()
# java_count_vectorizer = CountVectorizer()

cpp_weighted_vectorizer = TfidfVectorizer()
java_weighted_vectorizer = TfidfVectorizer()

# cpp_train_count_matrix = cpp_count_vectorizer.fit_transform(all_cpp_train).toarray()
# java_train_count_matrix = java_count_vectorizer.fit_transform(all_java_train).toarray()


cpp_weighted_matrix = cpp_weighted_vectorizer.fit_transform(all_cpp_train)
java_weighted_matrix = java_weighted_vectorizer.fit_transform(all_java_train)

# print cpp_train_weighted_matrix.todense()
# print len(cpp_train_count_matrix[0])
# print len(java_train_count_matrix[0])
cpp_weighted_matrix = cpp_weighted_matrix.toarray()
java_weighted_matrix =java_weighted_matrix.toarray()

print "shape of cpp weighted : " + str(cpp_weighted_matrix.shape)


train_cpp_percentage = (cpp_weighted_matrix.shape[0]/10)*9
cpp_train_weighted_matrix = cpp_weighted_matrix[:train_cpp_percentage]
train_java_percentage = (java_weighted_matrix.shape[0]/10)*9
java_train_weighted_matrix = java_weighted_matrix[:train_java_percentage]

train_cpp_labels = all_cpp_label[:train_cpp_percentage]
train_java_labels = all_java_label[:train_java_percentage]

print "cpp train matrix shape : " + str(cpp_train_weighted_matrix.shape)
print "java train matrix shape : " + str(java_train_weighted_matrix.shape)
all_1_pairs = []
all_0_pairs = []
targets_1 = []
targets_0 = []
for i,cpp_ele in tqdm(enumerate(cpp_train_weighted_matrix)):
    
    java_tuple = list(zip(java_train_weighted_matrix,train_java_labels))
    random_java_tuple = random.sample(java_tuple,100)

    sample_java_train_weighted_matrix, sample_train_java_labels = zip(*random_java_tuple)
    for j,java_ele in tqdm(enumerate(sample_java_train_weighted_matrix)):

        # print java_ele.tolist()
        # concatenate_vector =  np.hstack([cpp_ele,java_ele])
        concatenate_vector = cpp_ele.tolist()
        concatenate_vector.extend(java_ele.tolist())
        # print concatenate_vector
        if train_cpp_labels[i] == sample_train_java_labels[j]:         
            all_1_pairs.append(concatenate_vector)
            targets_1.append(1)
        else:
            all_0_pairs.append(concatenate_vector)
            targets_0.append(0)

all_1_pairs_np = np.array(all_1_pairs)
# all_0_pairs_np = np.array(all_0_pairs)

tuple_0 = list(zip(all_0_pairs,targets_0))
balance_0_pairs = random.sample(tuple_0,len(all_1_pairs))
all_0_pairs, targets_0 = zip(*balance_0_pairs)
all_0_pairs_np = np.array(all_0_pairs)

all_training_pairs_np = np.append(all_1_pairs_np,all_0_pairs_np,axis=0)
print "all 0 pairs shape : " + str(all_0_pairs_np.shape)
print "all 1 pairs shape : " + str(all_1_pairs_np.shape)
print "all training pairs shape : " + str(all_training_pairs_np.shape)
# all_training_pairs_np = np.array(all_training_pairs)

# print "FUCK"
print all_training_pairs_np


targets_1_np = np.array(targets_1)
targets_0_np = np.array(targets_0)
targets_np = np.append(targets_1_np,targets_0_np,axis=0)


print "target shape : " + str(targets_np.shape)

from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier

print "Fitting classifier.............."
clf = linear_model.LogisticRegression()
# clf = SVC()
# clf = RandomForestClassifier(max_depth=10, random_state=0)
# clf = GaussianNB()
clf.fit(all_training_pairs_np, targets_np)


cpp_test_weighted_matrix = cpp_weighted_matrix[train_cpp_percentage:(cpp_weighted_matrix.shape[0])]
java_test_weighted_matrix = java_weighted_matrix[train_java_percentage:(java_weighted_matrix.shape[0])]

test_cpp_labels = all_cpp_label[train_cpp_percentage:(cpp_weighted_matrix.shape[0])]
test_java_labels = all_java_label[train_java_percentage:(java_weighted_matrix.shape[0])]

all_test_1_pairs = []
all_test_0_pairs = []
test_targets = []

print "Preparing test pairs..........."
for i,cpp_ele in tqdm(enumerate(cpp_test_weighted_matrix)):
    
    for j,java_ele in tqdm(enumerate(java_test_weighted_matrix)):

        concatenate_vector = cpp_ele.tolist()
        concatenate_vector.extend(java_ele.tolist())
        # print concatenate_vector.shape
        # print concatenate_vector.shape
        # print concatenate_vector
        # print all_cpp_label[i], all_java_label[i]
        if test_cpp_labels[i] == test_java_labels[j]:         
            all_test_1_pairs.append(concatenate_vector)
            test_targets.append(1)
        else:
            all_test_0_pairs.append(concatenate_vector)
            test_targets.append(0)
# print clf.predict(cpp_test_weighted_matrix)

all_test_1_pairs_np = np.array(all_test_1_pairs)
all_test_0_pairs_np = np.array(all_test_0_pairs)

all_test_pairs_np = np.append(all_test_1_pairs_np,all_test_0_pairs_np,axis=0)

y_pred = clf.predict(all_test_pairs_np)
print test_targets
print y_pred

print precision_score(test_targets, y_pred, average='macro')  

# print all_1_pairs

# print cpp_labels_list
# # import ast
# import pickle
# import sys

# def build_tree(script):
#     """Builds an AST from a script."""
   
#     with open(script, 'rb') as file_handler:
#         print script
#         data_source = pickle.load(file_handler)
#         # print data_source
#         return data_source
#     return "error"
# #   return ast.parse(script)

# # Only for PKU dataset

# def parse_raw_data_to_pickle(data_directory, lang, outfile):
#     result = []
#     count = 0
#     for root,directories,files in os.walk(data_directory):

#         for file in files:
#             try:
#                 # if "new" not in file:
#                 file_path = os.path.join(root,file)
#                 splits = file_path.split("/")

              
#                 l = splits[len(splits)-2]

#                 if l == lang:
#                     label = splits[len(splits)-3]
#                     ast_representation = build_tree(file_path)
                    
#                     result.append({
#                         'tree': ast_representation, 'metadata': {'label': label}
#                         })
#                     count +=1
#             except Exception as err:
#                 print err
#     print "count : " + str(count)        
#     # print('Dumping scripts')
#     with open(outfile, 'wb') as file_handler:
#         pickle.dump(result, file_handler)

# if __name__ == "__main__": 