from graph import *

def DFS(graph, start, end, path = [], shortest = None): INDENT
    #assumes graph is a Digraph
    #assumes start and end are nodes in graph
    path = path + [start]
    print 'Current dfs path:', printPath(path)
    if start == end: INDENT
        return path
DEDENT     for node in graph.childrenOf(start): INDENT
        if node not in path:  INDENT#avoid cycles
            newPath = DFS(graph,node,end,path,shortest)
            if newPath != None: INDENT
                return newPath

DEDENT DEDENT DEDENT DEDENT def DFSShortest(graph, start, end, path = [], shortest = None): INDENT
    #assumes graph is a Digraph
    #assumes start and end are nodes in graph
    path = path + [start]
    print 'Current dfs path:', printPath(path)
    if start == end: INDENT
        return path
DEDENT     for node in graph.childrenOf(start): INDENT
        if node not in path:  INDENT#avoid cycles
            if shortest == None or len(path)<len(shortest): INDENT
                newPath = DFSShortest(graph,node,end,path)
                if newPath != None: INDENT
                    shortest = newPath
DEDENT DEDENT DEDENT DEDENT     return shortest



DEDENT def testSP(): INDENT
    nodes = []
    for name in range(6): INDENT
        nodes.append(Node(str(name)))
DEDENT     g = Digraph()
    for n in nodes: INDENT
        g.addNode(n)
DEDENT     g.addEdge(Edge(nodes[0],nodes[1]))
    g.addEdge(Edge(nodes[1],nodes[2]))
    g.addEdge(Edge(nodes[2],nodes[3]))
    g.addEdge(Edge(nodes[2],nodes[4]))
    g.addEdge(Edge(nodes[3],nodes[4]))
    g.addEdge(Edge(nodes[3],nodes[5]))
    g.addEdge(Edge(nodes[0],nodes[2]))
    g.addEdge(Edge(nodes[1],nodes[0]))
    g.addEdge(Edge(nodes[3],nodes[1]))
    g.addEdge(Edge(nodes[4],nodes[0]))
    sp = DFS(g, nodes[0], nodes[5])
    print 'Shortest path found by DFS:', printPath(sp)
DEDENT 
