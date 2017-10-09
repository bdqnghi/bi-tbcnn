"""Helper functions for sampling in ast2vec."""

import ast
from node_map import FAST_NODE_MAP

# NODE_MAP = {i: i for i in range(0,449)}



def batch_samples_for_fast(samples, batch_size):
    """Batch samples and return batches in a generator."""
    batch = ([], [])
    count = 0
    index_of = lambda x: FAST_NODE_MAP[x]

    for sample in samples:
        # print sample
        if sample['parent'] is not None:
            # print sample['node']
            batch[0].append(sample['node'])
            batch[1].append(sample['parent'])
            count += 1
            if count >= batch_size:
                yield batch
                batch, count = ([], []), 0
