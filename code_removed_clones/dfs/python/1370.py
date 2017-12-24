graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E','F'])
         }
def dfs(graph, start): INDENT
    visited, stack = set(), [start]
    while stack: INDENT
        vertex = stack.pop()
        if vertex not in visited: INDENT
            visited.add(vertex)
            stack.extend(graph[vertex] - visited)
DEDENT DEDENT     return visited

DEDENT def dfs_paths(graph, start, goal): INDENT
    stack = [(start, [start])]
    while stack: INDENT
        (vertex, path) = stack.pop()
        for next in graph[vertex] - set(path): INDENT
            if next == goal: INDENT
                yield path + [next]
DEDENT             else: INDENT
                stack.append((next, path + [next]))

# print dfs(graph, 'A') # {'E', 'D', 'F', 'A', 'C', 'B'}
#print list(dfs_paths(graph, 'A', 'F')) [['A', 'B', 'E', 'F'], ['A', 'C', 'F']]


########################BFS##############################

DEDENT DEDENT DEDENT DEDENT def bfs(graph, start): INDENT
    visited, queue = set(), [start]
    while queue: INDENT
        vertex = queue.pop(0)
        if vertex not in visited: INDENT
            visited.add(vertex)
            queue.extend(graph[vertex] - visited)
DEDENT DEDENT     return visited

#bfs(graph, 'A') # {'B', 'C', 'A', 'F', 'D', 'E'}




DEDENT def bfs_paths(graph, start, goal): INDENT
    queue = [(start, [start])]
    while queue: INDENT
        (vertex, path) = queue.pop(0)
        for next in graph[vertex] - set(path): INDENT
            if next == goal: INDENT
                yield path + [next]
DEDENT             else: INDENT
                queue.append((next, path + [next]))

#list(bfs_paths(graph, 'A', 'F')) # [['A', 'C', 'F'], ['A', 'B', 'E', 'F']]

########################Edges of Graphs##############################
#List all edges of Graphs
DEDENT DEDENT DEDENT DEDENT def list_all_edges(graph): INDENT

        for every in graph.items(): INDENT
                for each in every[1]: INDENT
                        print "{}-->{}".format(every[0],each)
#list_all_edges(graph)

#The generate_edges does the same thing
DEDENT DEDENT DEDENT def generate_edges(graph): INDENT
    edges = []
    for node in graph: INDENT
        for neighbour in graph[node]: INDENT
            edges.append((node, neighbour))

DEDENT DEDENT     return edges

#list isoldated nodes
DEDENT def isolated_nodes(graph): INDENT
        for every in graph.items(): INDENT
                if len(every[1]) == 0: INDENT
                        yield every[0]
#print list(isolated_nodes(graph))

#remove self loops
DEDENT DEDENT DEDENT def remove_self_loops(graph): INDENT
        for every in graph: INDENT
                if  every in graph[every]: INDENT
                        graph[every] = graph[every] - set([every])
DEDENT DEDENT         return graph




########################Degree sequence##############################

DEDENT def degree_sequence(graph): INDENT
        """ calculates the degree sequence """
        seq = []
        for vertex in graph: INDENT
            seq.append(self.vertex_degree(vertex))
DEDENT         seq.sort(reverse=True)
        return tuple(seq)

########################ISconnected##############################


DEDENT def traverse(self, start): INDENT
                stack = [start]
                self.visited = set()
                while stack:                         INDENT
                        node = stack.pop()
                        self.visited.add(node)
                        stack.extend(self.graph[node] - self.visited)
DEDENT                 return self.visited

DEDENT def isConnected(self):         INDENT# Call after .traverse() is called
        return True if len(self.visited) == len(self.graph) else False        







DEDENT if __name__ == '__main__': INDENT
        printremove_self_loops(graph)
DEDENT 
