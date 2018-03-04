import re
import os
import random
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_extraction.text import CountVectorizer
from tqdm import *
from sklearn.datasets import fetch_20newsgroups

count_vectorizer = CountVectorizer()
categories = ['alt.atheism', 'soc.religion.christian','comp.graphics', 'sci.med']

twenty_train = fetch_20newsgroups(subset='train',categories=categories, shuffle=True, random_state=42)

print twenty_train.data
print twenty_train.target
X_train_counts = count_vectorizer.fit_transform(twenty_train.data)