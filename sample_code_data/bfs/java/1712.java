package j.UndirectedGraphs;

import java.util.ArrayDeque;
import java.util.Queue;

public class BFS {
    private boolean[] marked;
    private int[] edgeTo;

    public BFS(Graph G, int s) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        bfs(G, s);
    }

    private void bfs(Graph G, int s) {
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(s);
        marked[s] = true;
        while (!q.isEmpty()) {
            int v = q.poll();
            for (int w: G.adj(v)) {
                if (!marked[w]) {
                    q.offer(w);
                    marked[w] = true;
                    edgeTo[w] = v;
                }
            }
        }
    }
}
