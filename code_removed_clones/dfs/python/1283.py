#!/usr/bin/env python
# -*- coding: utf-8 -*-
import networkx as nx
import numpy as n

def DFS(G, s): INDENT
    cor  = {}
    pred = {}
    d    = {}
    f    = {}

    tempo = 0

    for v in G.nodes(): INDENT
        cor[v]  = 'branco' # cores possíveis: branco cinza e preto
        pred[v] = None

DEDENT     for v in G.nodes(): INDENT
        if cor[v] == 'branco': INDENT
            tempo = visit(G, v, cor, pred, d, f, tempo)

DEDENT DEDENT     H = nx.create_empty_copy(G)

    for v1,v2,data in G.edges(data=True): INDENT
        if (pred[v2] is v1) or (pred[v1] is v2 and not nx.is_directed(H)): INDENT
            H.add_edge( v1, v2, data )
            H.node[v1]['begin_time'] = d[v1]
            H.node[v2]['begin_time'] = d[v2]
            H.node[v1]['finish_time'] = f[v1]
            H.node[v2]['finish_time'] = f[v2]

DEDENT DEDENT     return H

DEDENT def visit(G, s, cor, pred, d, f, tempo): INDENT
    tempo  = tempo + 1
    d[s]   = tempo
    cor[s] = 'cinza'

    for v in G[s]: INDENT
        if cor[v] == 'branco': INDENT
            pred[v] = s
            tempo = visit(G, v, cor, pred, d, f, tempo)

DEDENT DEDENT     cor[s] = 'preto'
    tempo = tempo + 1
    f[s] = tempo

    return tempo
DEDENT 
