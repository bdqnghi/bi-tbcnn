FAST_NODE_MAP = {}
with open("./data/fast_node_map.tsv","r") as f:
    lines = f.readlines()


for line in lines:
    splits = line.split("=")
    # FAST_NODE_MAP[splits[0].strip()] = int(splits[1].strip())
    FAST_NODE_MAP[int(splits[1].strip())] = splits[0].strip()