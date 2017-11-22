import os
import ast
import pickle
import sys

def main():
    with open(sys.argv[1], "r") as f:
        file_data = f.read()
    script = str(file_data)
    with open(sys.argv[2], 'wb') as file_handler:
        pickle.dump(ast.parse(script), file_handler)

if __name__ == "__main__": 
    main()
