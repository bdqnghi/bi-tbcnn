from time import time
import pandas as pd
import numpy as np
from gensim.models import KeyedVectors
import re
from nltk.corpus import stopwords
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import seaborn as sns

import itertools
import datetime

from keras.preprocessing.sequence import pad_sequences
from keras.models import Model
from keras.layers import Input, Embedding, LSTM, Merge
import keras.backend as K
from keras.optimizers import Adadelta
from keras.callbacks import ModelCheckpoint
from sklearn.model_selection import train_test_split
# File paths
DATA = './corpus/pairs2.csv'
# TEST_CSV = '..../test.csv'
CPP_EMBEDDING_FILE = './baselines/cpp2vec'
JAVA_EMBEDDING_FILE = './baselines/java2vec'
MODEL_SAVING_DIR = '/./baselines/logs/ma_lstm/'

# Load training and test set
df = pd.read_csv(DATA)


train_df, test_df = train_test_split(df, test_size=0.2)

# Prepare embedding
vocabulary = dict()
inverse_vocabulary = ['<unk>']  # '<unk>' will never be used, it is only a placeholder for the [0, 0, ....0] embedding
cpp_word2vec = KeyedVectors.load(CPP_EMBEDDING_FILE)
java_word2vec = KeyedVectors.load(JAVA_EMBEDDING_FILE)

questions_cols = ['question1', 'question2']

# Iterate over the questions only of both training and test datasets
for dataset in [train_df, test_df]:
    for index, row in dataset.iterrows():

        # Iterate through the text of both questions of the row
        for question in questions_cols:

        	if question == "questions1":
        		word2vec = cpp_word2vec
        	else:
        		word2vec = java_word2vec

        	q2n = []
        	for word in row[question]:
        		# Check for unwanted words
        		if word not in word2vec.wv.vocab:
        			continue
        		if word not in vocabulary:
        			vocabulary[word] = len(inverse_vocabulary)
        			q2n.append(len(inverse_vocabulary))
        			inverse_vocabulary.append(word)
        		else:
        			q2n.append(vocabulary[word])
        	dataset.set_value(index, question, q2n)
            
cpp_embedding_dim = 100
cpp_embeddings = 1 * np.random.randn(len(vocabulary) + 1, cpp_embedding_dim)  # This will be the embedding matrix
cpp_embeddings[0] = 0  # So that the padding will be ignored

java_embedding_dim = 100
java_embeddings = 1 * np.random.randn(len(vocabulary) + 1, java_embedding_dim)  # This will be the embedding matrix
java_embeddings[0] = 0  # So that the padding will be ignored

# Build the embedding matrix
for word, index in vocabulary.items():
    if word in cpp_word2vec.wv.vocab:
        cpp_embeddings[index] = cpp_word2vec[word]

for word, index in vocabulary.items():
    if word in java_word2vec.wv.vocab:
        java_embeddings[index] = java_word2vec[word]
# del word2vec

max_seq_length = max(train_df.question1.map(lambda x: len(x)).max(),
                     train_df.question2.map(lambda x: len(x)).max(),
                     test_df.question1.map(lambda x: len(x)).max(),
                     test_df.question2.map(lambda x: len(x)).max())

# Split to train validation
validation_size = 300
training_size = len(train_df) - validation_size

X = train_df[questions_cols]
Y = train_df['is_duplicate']

X_train, X_validation, Y_train, Y_validation = train_test_split(X, Y, test_size=validation_size)

# Split to dicts
X_train = {'left': X_train.question1, 'right': X_train.question2}
X_validation = {'left': X_validation.question1, 'right': X_validation.question2}
X_test = {'left': test_df.question1, 'right': test_df.question2}

# Convert labels to their numpy representations
Y_train = Y_train.values
Y_validation = Y_validation.values

# Zero padding
for dataset, side in itertools.product([X_train, X_validation], ['left', 'right']):
    dataset[side] = pad_sequences(dataset[side], maxlen=max_seq_length)

# Make sure everything is ok
assert X_train['left'].shape == X_train['right'].shape
assert len(X_train['left']) == len(Y_train)

# Model variables
n_hidden = 50
gradient_clipping_norm = 1.25
batch_size = 5
n_epoch = 50

def exponent_neg_manhattan_distance(left, right):
    ''' Helper function for the similarity estimate of the LSTMs outputs'''
    return K.exp(-K.sum(K.abs(left-right), axis=1, keepdims=True))

# The visible layer
left_input = Input(shape=(max_seq_length,), dtype='int32')
right_input = Input(shape=(max_seq_length,), dtype='int32')

cpp_embedding_layer = Embedding(len(cpp_embeddings), cpp_embedding_dim, weights=[cpp_embeddings], input_length=max_seq_length, trainable=False)


java_embedding_layer = Embedding(len(java_embeddings), java_embedding_dim, weights=[java_embeddings], input_length=max_seq_length, trainable=False)

# Embedded version of the inputs
encoded_left = cpp_embedding_layer(left_input)
encoded_right = java_embedding_layer(right_input)

# Since this is a siamese network, both sides share the same LSTM
shared_lstm = LSTM(n_hidden)

left_output = shared_lstm(encoded_left)
right_output = shared_lstm(encoded_right)

# Calculates the distance as defined by the MaLSTM model
malstm_distance = Merge(mode=lambda x: exponent_neg_manhattan_distance(x[0], x[1]), output_shape=lambda x: (x[0][0], 1))([left_output, right_output])

# Pack it all up into a model
malstm = Model([left_input, right_input], [malstm_distance])

# Adadelta optimizer, with gradient clipping by norm
optimizer = Adadelta(clipnorm=gradient_clipping_norm)

malstm.compile(loss='mean_squared_error', optimizer=optimizer, metrics=['accuracy'])

# Start training
training_start_time = time()

malstm_trained = malstm.fit([X_train['left'], X_train['right']], Y_train, batch_size=batch_size, nb_epoch=n_epoch,
                            validation_data=([X_validation['left'], X_validation['right']], Y_validation))

print("Training time finished.\n{} epochs in {}".format(n_epoch, datetime.timedelta(seconds=time()-training_start_time)))

# Plot accuracy
plt.plot(malstm_trained.history['acc'])
plt.plot(malstm_trained.history['val_acc'])
plt.title('Model Accuracy')
plt.ylabel('Accuracy')
plt.xlabel('Epoch')
plt.legend(['Train', 'Validation'], loc='upper left')
plt.show()

# Plot loss
plt.plot(malstm_trained.history['loss'])
plt.plot(malstm_trained.history['val_loss'])
plt.title('Model Loss')
plt.ylabel('Loss')
plt.xlabel('Epoch')
plt.legend(['Train', 'Validation'], loc='upper right')
plt.show()