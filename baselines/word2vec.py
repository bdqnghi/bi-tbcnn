import gensim
import os
import codecs
from sklearn.manifold import TSNE
from gensim.models.keyedvectors import KeyedVectors
import numpy as np
import matplotlib.pyplot as plt
import re
ROOT_URL = "./code/"


def load_embeddings(file_name):
	with codecs.open(file_name,"r","utf-8") as f:
		next(f)
		vocabulary, wv = zip(*[line.strip().split(" ",1) for line in f])
	wv = np.loadtxt(wv)
	return wv,vocabulary

def removeComments(string):
    string = re.sub(re.compile("/\*.*?\*/",re.DOTALL ) ,"" ,string) # remove all occurance streamed comments (/*COMMENT */) from string
    string = re.sub(re.compile("//.*?\n" ) ,"" ,string) # remove all occurance singleline comments (//COMMENT\n ) from string
    return string
all_cpp = []
all_java = []
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
            splits = [x.strip() for x in splits if x.strip()]

            print len(splits)

        if len(splits) > 30:
        	# data = " ".join(splits)
        	# print data
        	if lang == "java":
        		all_java.append(splits)
        	if lang == "cpp":
        		all_cpp.append(splits)

print "all cpp : " + str(len(all_cpp))
print "all java : " + str(len(all_java))

print "Building Word2Vec model......."
# cpp_model = gensim.models.Word2Vec(all_cpp,min_count=10,size=100,workers=6,iter=15,sg=1,window=7)
# cpp_model.save("./baselines/cpp2vec")
# cpp_model = gensim.models.Word2Vec.load("./baselines/cpp2vec")
# cpp_model.wv.save_word2vec_format("./baselines/cpp2vec.txt",binary=False)
# word_vectors = KeyedVectors.load_word2vec_format("cpp2vec",binary=True)

# print word_vectors

# java_model = gensim.models.Word2Vec(all_java,min_count=10,size=100,workers=6,iter=15,sg=1,window=7)
# java_model.save("./baselines/java2vec")
java_model = gensim.models.Word2Vec.load("./baselines/java2vec")
java_model.wv.save_word2vec_format("./baselines/java2vec.txt",binary=False)
# word_vectors = KeyedVectors.load_word2vec_format("cpp2vec",binary=True)
