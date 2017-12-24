#!/usr/bin/python

class Vertex(object): INDENT
    def __init__(self, name): INDENT
        self.name = name
DEDENT     def __str__(self): INDENT
        return self.name
DEDENT     def getName(self): INDENT
        return self.name    

DEDENT DEDENT class Edge(object): INDENT
    def __init__(self, src, dst, weight=5): INDENT
        self.src = src
        self.dst = dst
        self.weight = weight
DEDENT     def __str__(self): INDENT
        return "{} -> {}".format(self.src.getName(), self.dst.getName())
DEDENT     def getSrc(self): INDENT
        return self.src
DEDENT     def getDst(self): INDENT
        return self.dst

DEDENT DEDENT class Graph(object): INDENT
    def __init__(self): INDENT
        self.edges = {}
        self.nodes = set()
DEDENT     def addVertex(self, node): INDENT
        if node.getName() in nodes: INDENT
            raise ValueError("Node already exists")
DEDENT         self.edges[node] = []
        self.nodes.add(node)
DEDENT     def addEdge(self, edge): INDENT
        if edge.getSrc() not in self.nodes: INDENT
            raise ValueError("src node not real")
DEDENT         if edge.getDst() not in self.nodes: INDENT
            raise ValueError("dst node not real")
DEDENT         self.edges[edge.getSrc()].append(edge.getDst())

DEDENT DEDENT def test(): INDENT
    pass

DEDENT if __name__ == "__main__": INDENT
    test()
DEDENT 
