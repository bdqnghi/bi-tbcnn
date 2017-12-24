"""DFS.py

Algorithms for depth first search in Python.
We need to search iteratively rather than recursively in
order to avoid Python's low recursion limit.

D. Eppstein, July 2004.
"""

# Types of edges in DFS traversal.
# The numerical values are used in DepthFirstSearcher, change with care.
forward = 1     # traversing edge (v,w) from v to w
reverse = -1    # returning backwards on (v,w) from w to v
nontree = 0     # edge (v,w) is not part of the DFS tree

whole_graph = object()  # special flag object, do not use as a graph vertex

def search(G,initial_vertex = whole_graph): INDENT
    """
    Generate sequence of triples (v,w,edgetype) for DFS of graph G.
    The subsequence for each root of each tree in the DFS forest starts
    with (root,root,forward) and ends with (root,root,reverse).
    If the initial vertex is given, it is used as the root and vertices
    not reachable from it are not searched.
    """
    visited = set()
    if initial_vertex == whole_graph: INDENT
        initials = G
DEDENT     else: INDENT
        initials = [initial_vertex]
DEDENT     for v in initials: INDENT
        if v not in visited: INDENT
            yield v,v,forward
            visited.add(v)
            stack = [(v,iter(G[v]))]
            while stack: INDENT
                parent,children = stack[-1]
                try: INDENT
                    child = children.next()
                    if child in visited: INDENT
                        yield parent,child,nontree
DEDENT                     else: INDENT
                        yield parent,child,forward
                        visited.add(child)
                        stack.append((child,iter(G[child])))
DEDENT DEDENT                 except StopIteration: INDENT
                    stack.pop()
                    if stack: INDENT
                        yield stack[-1][0],parent,reverse
DEDENT DEDENT DEDENT             yield v,v,reverse

DEDENT DEDENT DEDENT def preorder(G,initial_vertex = whole_graph): INDENT
    """Generate all vertices of graph G in depth-first preorder."""
    for v,w,edgetype in search(G,initial_vertex): INDENT
        if edgetype is forward: INDENT
            yield w

DEDENT DEDENT DEDENT def postorder(G,initial_vertex = whole_graph): INDENT
    """Generate all vertices of graph G in depth-first postorder."""
    for v,w,edgetype in search(G,initial_vertex): INDENT
        if edgetype is reverse: INDENT
            yield w

DEDENT DEDENT DEDENT def reachable(G,v,w): INDENT
    """Can we get from v to w in graph G?"""
    return w in preorder(G,v)

DEDENT class Searcher: INDENT
    """
    Handler for performing general depth first searches of graphs.
    Some or all of the routines preorder, postorder, and backedge
    should be shadowed in order to make the search do something useful.
    """

    def preorder(self,parent,child): INDENT
        """
        Called when DFS visits child, before visiting all grandchildren.
        Parent==child when child is the root of each DFS tree.
        """
        pass

DEDENT     def postorder(self,parent,child): INDENT
        """
        Called when DFS visits child, after visiting all grandchildren.
        Parent==child when child is the root of each DFS tree.
        """
        pass

DEDENT     def backedge(self,source,destination): INDENT
        """Called when DFS discovers an edge to a non-child."""
        pass

DEDENT     def __init__(self,G): INDENT
        """Perform a depth first search of graph G."""
        dispatch = [self.backedge,self.preorder,self.postorder]
        for v,w,edgetype in search(G): INDENT
            dispatch[edgetype](v,w)
DEDENT DEDENT DEDENT 
