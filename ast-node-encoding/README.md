# Encoding the AST Tree using a strategy similar to word2vec, but applied to the context of AST's

This works is an attempt to learn vector representation for AST nodes. The original paper is: https://arxiv.org/abs/1409.3358 Since this paper is difficult to understand and implement, I applied the strategy similar to word2vec to learned embeddings of AST nodes. 

* Vectors are learned by a variation of word2vec instead of the proposed method.
* Adam is used instead of gradient descent.
* The dataset used in this implementation is smaller than in the original paper. I crawled Python algorithms from Github by myself since using the built in Python AST parser for Python code is more convenient and less time-consuming than writing the AST Parser for the C++ code in the original dataset, thus the node type is a little bit different.

The list of learned token vectors can be found here:
https://github.com/bdqnghi/siamese-tbcnn/blob/master/data/vectors.txt

End-to-end instruction to train AST vectors:
----------------
* Extract raw.7z in the data directory. This zip file contain the raw training data for this project. After extracting, we can see that there is 6 sub-directories for 6 algorithms. Under each sub-directory, there will be raw Python code crawled from Github API.
* Go to ast-node-encoding/scripts, execute:
    
    ```python
    python parse_raw_data_to_pickle.py
    ```
  This step is to convert the raw data to pickle file, which can be found in data/algorithms.pkl. The pickle is nothing but just a list of ast trees with label, an example tree in the list is like:
  ```
  {'tree': <_ast.Module object at 0x7f84c52f9210>, 'metadata': {'label': 'mergesort'}}
  ```
 Note that this is not the format we're going to use to train the TBCNN, this step is just to store data for some archive purpose instead of reloading the heavy raw data all the time.
 
 
* Go to ast-node-encoding/scripts, execute:
    
    ```python
    python parse_pickle_file_to_nodes.py
    ```
  This step is to convert the ast trees in pickle file a list of nodes, each node will have the following format:
  
  ```
  {'node': 'Module', 'children': ['FunctionDef', 'FunctionDef', 'FunctionDef', 'Print'], 'parent': None}
  
  {'node': 'arguments', 'children': ['Name'], 'parent': 'FunctionDef'}
  ```
  After executing the script, we can find the pickle to store all the nodes in data/algorithm_nodes.pkl

* Once we get the ```algorithm_nodes.pkl```, go to ast-node-encoding execute:

  ```python
    python train.py
    ```
  The main() function in this file will open the ```algorithm_nodes.pkl``` and output the pickle ```pretrained_vectors.pkl``` into the data directory.
  
A visualization of learned token
--------------------------
![](../figure/ast_nodes_visualization.png)
