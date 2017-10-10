# Siamese Neural Network based on Tree-based Convolutional Neural Networks (TBCNN)

Tensorflow Implementation of the Siamese-TBCNN on top of TBCNN, which is the following paper:

["Convolutional Neural Networks over Tree Structures for Programming Language Processing" Lili Mou, et al.](https://arxiv.org/pdf/1409.5718.pdf)

Differences from the paper
--------------------------

* Since I found it difficult to implement the original paper to learn the pretrained vector (https://arxiv.org/abs/1409.3358) , the pretrained vectors are learned by a variation of word2vec instead of the proposed method. 
* Adam Optimizer is used instead of gradient descent.


Current state
----------------
* Reimplemented the TBCNN paper
* The dataset used in this implementation is smaller than in the original paper (3000 programs, 6 classess compare to 52000 programs, 104 classes in the original paper). I crawled Python programs from Github by myself since using the built-in Python AST parser for Python code is more convenient and less time-consuming than writing the AST Parser for the C++ code from the original dataset, thus the node type is a little bit different.

To do list
----------------

* Building the first version of siamese neural network (SNN), each side of the SNN is a TBCNN, input of each side is the AST presentation of code in different languages. 

Illustration of the propose model : 
![Propose model for the siamese tbcnn](../figure/propose_model.png)


First time setup
----------------

This will install neccessary requirements to run this project.

    $ pip install -r requirements.txt
   

The recommended Python version is 2 because many of the scripts parsed
by the AST parser are written in Python 2.


Dataset details
----------------
The raw data is in data/raw.7z, feels free to extract to examine. The data I used to train the model is in data/algorithm_trees.pkl, which is nothing but just the list of AST trees after the processing step from the raw data. A sample of a tree will be sth like:
```
{'tree': {'node': 'Module', 'children': [{'node': 'FunctionDef', 'children': [{'node': 'arguments', 'children': [{'node': 'Name', 'children': [{'node': 'Param', 'children': []}]}]}, {'node': 'If', 'children': [{'node': 'Compare', 'children': [{'node': 'Call', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}, {'node': 'LtE', 'children': []}, {'node': 'Num', 'children': []}]}, {'node': 'Return', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}]}, {'node': 'Assign', 'children': [{'node': 'Name', 'children': [{'node': 'Store', 'children': []}]}, {'node': 'Subscript', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Index', 'children': [{'node': 'BinOp', 'children': [{'node': 'Call', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}, {'node': 'Div', 'children': []}, {'node': 'Num', 'children': []}]}]}, {'node': 'Load', 'children': []}]}]}, {'node': 'Assign', 'children': [{'node': 'Name', 'children': [{'node': 'Store', 'children': []}]}, {'node': 'ListComp', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'comprehension', 'children': [{'node': 'Name', 'children': [{'node': 'Store', 'children': []}]}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Compare', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Lt', 'children': []}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}]}]}]}, {'node': 'Assign', 'children': [{'node': 'Name', 'children': [{'node': 'Store', 'children': []}]}, {'node': 'ListComp', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'comprehension', 'children': [{'node': 'Name', 'children': [{'node': 'Store', 'children': []}]}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Compare', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Eq', 'children': []}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}]}]}]}, {'node': 'Assign', 'children': [{'node': 'Name', 'children': [{'node': 'Store', 'children': []}]}, {'node': 'ListComp', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'comprehension', 'children': [{'node': 'Name', 'children': [{'node': 'Store', 'children': []}]}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Compare', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Gt', 'children': []}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}]}]}]}, {'node': 'Return', 'children': [{'node': 'BinOp', 'children': [{'node': 'BinOp', 'children': [{'node': 'Call', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}, {'node': 'Add', 'children': []}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}, {'node': 'Add', 'children': []}, {'node': 'Call', 'children': [{'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}, {'node': 'Name', 'children': [{'node': 'Load', 'children': []}]}]}]}]}]}]}, 'label': 'quicksort'}
```
The above tree will be corresponding to a file in the raw training set. Execute this file [dataset_sample](https://github.com/bdqnghi/siamese-tbcnn/blob/master/tbcnn/scripts/test_pickle.py) for more details.

Train and test the model
----------------

Simply run this command to train the network, the data to train is in data/algorithm_trees.pkl, the pretrained_vectors is in data/pretrained_vectors:

    $ python train.py
    
After training, we can test the model easily by running:

    $ python test.py
    
Example output
--------------

The classification task was to classify 6 different kinds of data structures
and argorithms. The original dataset is divided 7/3 for training/testing

### After training

    ('Accuracy:', 0.9924924924924925)
                precision    recall  f1-score   support

      mergesort       1.00      1.00      1.00       413
     linkedlist       1.00      1.00      1.00       368
      quicksort       1.00      1.00      1.00       401
            bfs       0.95      1.00      0.98       313
     bubblesort       1.00      1.00      1.00       185
       knapsack       1.00      0.95      0.98       318

    avg / total       0.99      0.99      0.99      1998

    [[413   0   0   0   0   0]
     [  0 368   0   0   0   0]
     [  0   0 401   0   0   0]
     [  0   0   0 313   0   0]
     [  0   0   0   0 185   0]
     [  0   0   0  15   0 303]]


### After testing

    ('Accuracy:', 0.99300699300699302)
                precision    recall  f1-score   support

      mergesort       1.00      1.00      1.00       154
     linkedlist       1.00      1.00      1.00       157
      quicksort       1.00      1.00      1.00       166
            bfs       0.96      1.00      0.98       128
     bubblesort       1.00      1.00      1.00       109
       knapsack       1.00      0.96      0.98       144

    avg / total       0.99      0.99      0.99       858

    [[154   0   0   0   0   0]
     [  0 157   0   0   0   0]
     [  0   0 166   0   0   0]
     [  0   0   0 128   0   0]
     [  0   0   0   0 109   0]
     [  0   0   0   6   0 138]]




