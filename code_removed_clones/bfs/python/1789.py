def bfs(graph,start):
	visited = set()
	queue = [start]

	while (queue):
		vertex = queue.pop(0)
		if vertex not in visited:
			visited.add(vertex)
			queue.extend(graph[vertex] - visited)
	return visited

#def bfsPaths(graph,start,goal):

def bfsRecursion(graph,start,visited = None):
	if visited == None:
		visited = set()

	visited.add(start)

	for next in graph[start] - visited:
		bfsRecursion(graph[start],next,visited)

def bfs_paths(graph, start, goal):
    queue = [(start, [start])]
    while queue:
        (vertex, path) = queue.pop(0)
        for next in graph[vertex] - set(path):
            if next == goal:
                yield path + [next]
            else:
                queue.append((next, path + [next]))

def main():
	graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}

	print (bfs(graph,'A'))
	#print (bfsRecursion(graph,'A'))
	print(list(bfs_paths(graph, 'A', 'F'))) # [['A', 'C', 'F'], ['A', 'B', 'E', 'F']]

main()