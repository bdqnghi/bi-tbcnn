import pickle
import gensim
import os
import codecs
from sklearn.manifold import TSNE
from gensim.models.keyedvectors import KeyedVectors
import matplotlib.pyplot as plt

VECTOR_PICKLE = "/vec/fast_pretrained_vectors.pkl"
VECTOR_WORD2VEC = "/vec/fast_pretrained_vectors.txt"

with open(VECTOR_PICKLE, "rb") as sample_file:
	samples = pickle.load(sample_file)


words = list()
for key, value in samples[1].items():
	words.append(value)


vectors = KeyedVectors.load_word2vec_format(VECTOR_WORD2VEC,binary=False)


tsne = TSNE(n_components=2, random_state=0)


Y = tsne.fit_transform(samples[0])

plt.scatter(Y[:,0],Y[:,1])
for label, x, y in zip(words,Y[:,0],Y[:,1]):
	
	
	plt.annotate(label,xy=(x,y),xytext=(0,0),textcoords="offset points",color="blue")


plt.show()
