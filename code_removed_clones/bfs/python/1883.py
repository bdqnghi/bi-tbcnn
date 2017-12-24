# bfs.py
# Breadth first search with a queue
# Afnan Enayet
#
# Graph is represented as a map where key is the node, and value is a set 
# of adjacent nodes

def bfs(graph, src, target):
    """ breadth first search, assumes graph has no duplicates
    :type graph: dict
    :type src: int
    :type target: int 
    :type visited: set """
    q = []
    visited = set()

    q.append(src)

    while len(q) > 0:
        node = q.pop(0)
        visited.add(node)

        # Or do whatever you need to do to process the node here
        if node == target:
            print("Found")
            return

        for neighbor in graph[node]:
            if neighbor not in visited:
                q.append(neighbor)


# Test
g = dict()
g[1] = set([2, 4])
g[2] = set([1, 5])
g[3] = set([2, 5])
g[4] = set([1, 5])
g[5] = set([2, 3, 4])

bfs(g, 1, 3)

