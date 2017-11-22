"""Helper functions for sampling in ast2vec."""

import ast
from srcml_node_map import SRCML_NODE_MAP

def batch_samples(samples, batch_size):
    """Batch samples and return batches in a generator."""
    batch = ([], [])
    count = 0
    index_of = lambda x: SRCML_NODE_MAP[x]
    for sample in samples:
        # print sample
        if sample['parent'] is not None:
            batch[0].append(sample['node'])
            batch[1].append(sample['parent'])
            count += 1
            if count >= batch_size:
                yield batch
                batch, count = ([], []), 0
