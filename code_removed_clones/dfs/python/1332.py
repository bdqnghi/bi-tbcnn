import graph
import BFS



def main(): INDENT
        g1 = graph.Graph().rand_graph(1, 12)
        source = g1.nodes[0]
        DFS(g1, source)
        # test_DFS()

DEDENT def DFS(g, source): INDENT
        for n in g.nodes: INDENT
                n.color = "white"
                n.pred = None
DEDENT         time = 0;
        for n in g.nodes: INDENT
                # print n.color
                if n.color == "white": INDENT
                        time = DFS_visit(n, time)
DEDENT DEDENT         print_DFS(g)

DEDENT def DFS_visit(source, time): INDENT
        time += 1
        source.startTime = time
        source.color = "gray"
        for n in source.adjList: INDENT
                if n.color == "white": INDENT
                        n.pred = source
                        time = DFS_visit(n, time)
DEDENT DEDENT         source.color = "black"
        time += 1
        source.endTime = time;
        return time


DEDENT def print_DFS(g): INDENT
        for n in g.nodes: INDENT
                predString = "{0}".format(n.id)
                while n.pred != None: INDENT
                        n = n.pred
                        predString = "{0}-->".format(n.id) + predString
DEDENT                 print predString


DEDENT DEDENT def test_DFS(): INDENT
        g1 = graph.Graph().rand_graph(10,15)
        BFS.BFS(g1, g1.nodes[0])
        distances = {}
        for n in g1.nodes: INDENT
                distances[n.id] = n.distance
                n.distance = -1

DEDENT         DFS(g1, g1.nodes[0])
        print distances
        for n in g1.nodes: INDENT
                assert distances[n.id] == n.distance

DEDENT DEDENT if __name__ == "__main__": INDENT
        main()
DEDENT 
