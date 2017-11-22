# This script can be used to parse files to ast trees and save into a pickle

import os
import ast
import pickle
import sys

def build_tree(script):
    """Builds an AST from a script."""
   
    with open(script, 'rb') as file_handler:
        data_source = pickle.load(file_handler)
      
        return data_source
    return "error"
#   return ast.parse(script)

def parse_raw_data_to_pickle(data_directory, lang, outfile):
    result = []

    for root,directories,files in os.walk(data_directory):
        for file in files:
            try:
                file_path = os.path.join(root,file)
                splits = file_path.split("/")
		l = splits[len(splits)-2]
		if l == lang:
			label = splits[len(splits)-3]
			ast_representation = build_tree(file_path)
			result.append({
			    'tree': ast_representation, 'metadata': {'label': label}
			})
            except Exception as err:
                print err
            
    # print('Dumping scripts')
    with open(outfile, 'wb') as file_handler:
        pickle.dump(result, file_handler)

def main():
    parse_raw_data_to_pickle(sys.argv[1], sys.argv[2], sys.argv[3])

if __name__ == "__main__": 
    main()
