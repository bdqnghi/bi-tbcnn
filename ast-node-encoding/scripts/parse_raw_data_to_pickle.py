# This script can be used to parse files to ast trees and save into a pickle

import os
import ast
import pickle
def build_tree(script):
    """Builds an AST from a script."""
    return ast.parse(script)

def parse_raw_data_to_pickle(data_directory,outfile):
    result = []

    for root,directories,files in os.walk(data_directory):
        for file in files:
            try:
                file_path = os.path.join(root,file)
                splits = file_path.split("/")

                label = splits[len(splits)-2]
                

                with open(file_path, "r") as f:
                    file_data = f.read()

                file_data = str(file_data)
                print file_data
                ast_representation = build_tree(file_data)

                result.append({
                    'tree': ast_representation, 'metadata': {'label': label}
                })
            except Exception as err:
                print err
            
    print('Dumping scripts')
    with open(outfile, 'wb') as file_handler:
        pickle.dump(result, file_handler)

def main():
    parse_raw_data_to_pickle("./data/raw","./data/algorithms2.pkl")

if __name__ == "__main__": 
    main()