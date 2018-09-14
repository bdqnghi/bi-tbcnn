import java.util.*;
import static java.lang.System.out;

public class BFS{
    final Graph g;
    static final int MAXV = 100;
    boolean[] processed = new boolean[MAXV+1];
    boolean[] discovered = new boolean[MAXV+1];

    int parent[] =  new int[MAXV+1 + 1]; 

    public BFS(Graph g) {
        this.g = g;
        for (int i=1; i<=g.nvertices; i++) {
            processed[i] = false;
            discovered[i] = false;
            parent[i] = -1;
        }
    }

    public void bfs(int start) {
        Queue<Integer> queue = new LinkedList<Integer>();
        int v;
        int y;
        Graph.EdgeNode p;

        queue.offer(start);
        discovered[start] = true;
        while(!queue.isEmpty()) {                             // Process each discovered vertex
            v = queue.poll();
            processVertexEarly(v);
            processed[v] = true;
            p = g.edges[v];
            while (p != null) {                             // Process each edge of the vertex
                y = p.y;
                if (processed[y] == false || g.directed)    // If undirected, edge is processed iff y is processed
                    processEdge(v,y);
                if (discovered[y] == false) {               // add undiscovered children to queue
                    queue.offer(y);
                    discovered[y] = true;
                    parent[y] = v;
                }
                p = p.next;
            }
            processVertexLate(v);
        }
    }

    void processVertexEarly(int v) {
        out.format("Processing vertex %d early\n", v);
    }

    void processVertexLate(int v) {
        out.format("Processing vertex %d late\n", v);
    }

    void processEdge(int v, int y) {
        out.format("Processing edge %d-%d\n", v,y);
    }


    public static void main(String[] args) {
        Graph g = Graph.readGraph(true);
        g.printGraph();
        BFS bfs = new BFS(g);
        bfs.bfs(1);
    }
}
