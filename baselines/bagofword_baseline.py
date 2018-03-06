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
from sklearn.metrics import recall_score
from sklearn.decomposition import PCA
ROOT_URL = "./code/"

with open("./corpus/pairs2.csv", "r") as f:
    data = f.readlines()

all_cpp = list()
all_java = list()
all_label = list()
for line in data:
    splits = line.split(",")
    all_cpp.append(splits[0])
    all_java.append(splits[1])
    all_label.append(int(splits[2]))

# print all_java

cpp_vectorizer = CountVectorizer()
java_vectorizer =  CountVectorizer()

cpp_matrix = cpp_vectorizer.fit_transform(all_cpp)
java_matrix = java_vectorizer.fit_transform(all_java)

cpp_matrix = cpp_matrix.toarray()
java_matrix =java_matrix.toarray()

print "shape of cpp matrix : " + str(cpp_matrix.shape)
print "shape of java matrix : " + str(java_matrix.shape)

train_percentage = (cpp_matrix.shape[0]/10)*9
cpp_train_matrix = cpp_matrix[:train_percentage]
train_java_percentage = (java_matrix.shape[0]/10)*9
java_train_matrix = java_matrix[:train_percentage]

train_labels = all_label[:train_percentage]

train_labels = np.array(train_labels)
all_training_pairs = []
for i,cpp_ele in tqdm(enumerate(cpp_train_matrix)):
    java_ele = java_train_matrix[i]
    
    concatenate_vector = cpp_ele.tolist()
    concatenate_vector.extend(java_ele.tolist())
    all_training_pairs.append(concatenate_vector)


all_training_pairs = np.array(all_training_pairs)

pca = PCA(n_components=2000)
print "shape of training pairs : " + str(all_training_pairs.shape)

print "target shape : " + str(train_labels.shape)

from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier


# print "Reducing dimension........."
# train_features = pca.fit_transform(all_training_pairs)

train_features = all_training_pairs
print "Fitting classifier.............."
# clf = linear_model.LogisticRegression()
# # clf = SVC()
clf = RandomForestClassifier(n_estimators=100, max_depth=10, random_state=0)
# clf = GaussianNB()
clf.fit(train_features, train_labels)


cpp_test_matrix = cpp_matrix[train_percentage:(cpp_matrix.shape[0])]
java_test_matrix = java_matrix[train_percentage:(java_matrix.shape[0])]

test_labels = all_label[train_percentage:(cpp_matrix.shape[0])]
test_labels = np.array(test_labels)

all_testing_pairs = []
for i,cpp_ele in tqdm(enumerate(cpp_test_matrix)):
    java_ele = java_test_matrix[i]
    
    concatenate_vector = cpp_ele.tolist()
    concatenate_vector.extend(java_ele.tolist())
    all_testing_pairs.append(concatenate_vector)

all_testing_pairs = np.array(all_testing_pairs)

print "shape of testing pairs pairs : " + str(all_testing_pairs.shape)

# test_features = pca.transform(all_testing_pairs)
test_features = all_testing_pairs
y_pred = clf.predict(test_features)

print y_pred

print "precision : " + str(precision_score(test_labels, y_pred, average='macro'))
print "recall : " + str(recall_score(test_labels, y_pred, average='macro'))

