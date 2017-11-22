"""Parse nodes from a given data source."""

import ast
import cPickle as pickle
import sys
from collections import defaultdict

def parse_raw_data_to_pickle(infile,outfile):
    """Parse nodes with the given args."""
    print ('Loading pickle file')
    
    with open(infile, 'rb') as file_handler:
        data_source = pickle.load(file_handler)

    print ('Pickle load finished')

    node_counts = defaultdict(int)
    samples = []

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
                    'children': [x.kind for x in element.child]
                }
            ]
            gen_samples = lambda x: new_samples.extend(_create_samples(x))
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

def _create_samples(node):
    """Convert a node's children into a sample points."""
    samples = []
    for child in node.child:
        sample = {
            "node": child.kind,
            "parent": node.kind,
            "children": [x.kind for x in child.child]
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


    
