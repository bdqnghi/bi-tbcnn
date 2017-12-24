def dfs(adjList, start): INDENT
    visited = {}
    pred = {}
    for key in adjList: INDENT
        visited[key] = False
        pred[key] = None
DEDENT     visited[start] = True
    rdfs(adjList, start, visited, pred)
    return pred


DEDENT def rdfs(adjList, vertex, visited, pred): INDENT
    edges = adjList[vertex]
    for edge in edges: INDENT
        if visited[edge] is False: INDENT
            visited[edge] = True
            pred[edge] = vertex
            rdfs(adjList, edge, visited, pred)


DEDENT DEDENT DEDENT def dfsPath(pred, dest): INDENT
    prev = pred[dest]
    path = []
    while prev is not None: INDENT
        path.append(prev)
        prev = pred[prev]
DEDENT     path.reverse()
    return path


DEDENT def main(): INDENT
    pass


DEDENT if __name__ == '__main__': INDENT
    main()
DEDENT 
