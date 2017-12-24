# coding: utf-8
from util import build_path
from graph import Graph


def dfs(source, target, graph): INDENT
    """ Depth-first graph search """
    fringe = [source]
    parent = {source:None}

    while fringe: INDENT
        x = fringe.pop()

        if x == target: INDENT
            return build_path(parent, target)

DEDENT         for v in graph.adj(x): INDENT
            if v not in parent: INDENT
                fringe.append(v)
                parent[v] = x
DEDENT DEDENT DEDENT     return None
DEDENT 
