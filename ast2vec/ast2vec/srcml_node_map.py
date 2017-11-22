SRCML_NODE_MAP = {}
with open("/input/srcml_node_map.tsv","r") as f:
    lines = f.readlines()

for line in lines:
    splits = line.split("=")
    SRCML_NODE_MAP[str(splits[1].strip())] = splits[0].strip()
