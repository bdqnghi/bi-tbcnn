from Queue import Queue
from sets import Set

def dfs(graph, start): INDENT
        explored=set() #store the distance
        stack=[]
        stack.append(start)
        explored.add(start)
        while len(stack)>0: INDENT
                tail=stack.pop()
                #print "%s -> "%(tail),
                for head, edge in graph.outBounds(tail).items(): INDENT
                        if  head not in explored: INDENT
                                stack.append(head)
                                explored.add(head)

DEDENT DEDENT DEDENT         return explored

 

DEDENT if __name__=='__main__': INDENT
        from graph import Graph, Edge, Vertex
        g=Graph()
        g.addEdge(Edge(Vertex('s'),Vertex('a')),False)
        
        g.addEdge(Edge(Vertex('b'), Vertex('s')),False)
        g.addEdge(Edge(Vertex('b'), Vertex('c')),False)
         
        g.addEdge(Edge(Vertex('c'), Vertex('a')),False)
        g.addEdge(Edge(Vertex('c'), Vertex('d')),False)

        g.addEdge(Edge(Vertex('e'),Vertex('d')),False)
        print "graph: \n",g

        start=Vertex('s')
        explored=dfs(g, start)
        print explored
        
DEDENT 
