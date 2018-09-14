import java.util.LinkedList;

public class BFS{
    private int[] distTo;
    private boolean[] marked;
    
    public BFS(Graph G){
        distTo = new int[G.numVertices()];
        marked = new boolean[G.numVertices()];
        for(int i = 0; i < G.numVertices();i++)
            distTo[i] = Integer.MAX_VALUE;
        bfs(G,0);
    }
    
    public int[] distTo(){
        return distTo;
    }

    private void bfs(Graph G,int s){
        LinkedList<Integer> Q = new LinkedList<Integer>();
        Q.add(s);
        distTo[s] = 0;
        marked[s] = true;
        int dist = 0;
        while(Q.peek() != null){
            dist++;
            int v = Q.remove();
            for(int u: G.adj(v)){
                if(!marked[u]){
                    distTo[u] = dist;
                    Q.add(u);
                    marked[u] = true;
                }
            }
                
        }
    }
}
