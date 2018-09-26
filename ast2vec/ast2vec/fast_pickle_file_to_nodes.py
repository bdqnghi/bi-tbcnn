"""Parse nodes from a given data source."""

import os
import ast
import pickle
import sys
from collections import defaultdict, OrderedDict
import pyarrow

def parse_raw_data_to_pickle(infile,outfile):
    """Parse nodes with the given args."""
    print ('Loading pickle file')

    basename, extname = os.path.splitext(infile)
    basename, lang = os.path.splitext(basename)
    print (lang)
    
    with open(infile, 'rb') as file_handler:
        data_source = pickle.load(file_handler)

    print ('Pickle load finished')

    node_counts = defaultdict(int)
    samples = []

    maps = {}
    map_filename = 'maps%s.pa' % lang
    if os.path.exists(map_filename):
       with open(map_filename, 'rb') as f:
           buf = f.read()
           maps = pyarrow.deserialize(buf)
           f.close()
    OrderedDict(sorted(maps.items(), key=lambda t: t[0]))
    #for key, value in maps.items() :
    #    print("%s<=%s" % (value, key))
    #print (map_filename)

    has_capacity = lambda x: -1 < 0 or node_counts[x] < -1
    can_add_more = lambda: 10000 < 0 or len(samples) < -1

    for item in data_source:
        root = item['tree']
        if root.HasField("element"):
            element = root.element
            new_samples = [
                {
                    'node': element.kind,
                    'parent': None,
                    'children': [int(maps[str(x.kind)]) for x in element.child]
                }
            ]
            gen_samples = lambda x: new_samples.extend(_create_samples(x, maps, map_filename))
            _traverse_tree(element, gen_samples)
            for sample in new_samples:
                if has_capacity(sample['node']):
                    samples.append(sample)
                    node_counts[sample['node']] += 1
                if not can_add_more:
                    break
        if not can_add_more:
            break
    print ('dumping sample')

    with open(outfile, 'wb') as file_handler:
        pickle.dump(samples, file_handler)
        file_handler.close()

    print('Total: %d' % sum(node_counts.values()))

def _create_samples(node, maps, map_filename):
    """Convert a node's children into a sample points."""
    samples = []
    for child in node.child:
        for x in child.child:
            if not str(x.kind) in maps:
                maps[str(x.kind)] = str(len(maps)+1)
                with open(map_filename, 'wb') as f:
                    pickle.dump(maps, f, pickle.HIGHEST_PROTOCOL)
                    f.close()
        sample = {
            "node": child.kind,
            "parent": node.kind,
            'children': [int(maps[str(x.kind)]) for x in child.child]
            #"children": [x.kind for x in child.child]
        }
        samples.append(sample)

    return samples

def _traverse_tree(tree, callback):
    """Traverse a tree and execute the callback on every node."""

    queue = [tree]
    while queue:
        current_node = queue.pop(0)
        children = list(current_node.child)
        queue.extend(children)
        callback(current_node)

def _name(node):
    """Get the name of a node."""
    return type(node).__name__


def main():

    parse_raw_data_to_pickle(sys.argv[1], sys.argv[2])

if __name__ == "__main__": 
    main()


    
