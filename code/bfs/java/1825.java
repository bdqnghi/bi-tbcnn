package algoritms.graph;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Created by starnakin on 08.11.2015.
 */
public class BFS {
    private static class Graph{
        int vNumber;
        LinkedList<Integer>[] vectorsArray;

        public Graph(int vNumber){
            this.vNumber = vNumber;
            vectorsArray = new LinkedList[vNumber];
            for(int i = 0; i < vNumber; i++){
                vectorsArray[i] = new LinkedList<>();
            }

        }

        public void addEdge(int v, int n){
            vectorsArray[v].addLast(n);
        }

        public List<Integer> getAdjastensylist(int v){
            return vectorsArray[v];
        }

        public int getNumber(){
            return vNumber;
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("Following is Breadth First Traversal "+
                "(starting from vertex 2)");

        BFSGraph(2, g);
    }

    private static void BFSGraph(int v, Graph g){
        Queue<Integer> queue = new LinkedList<>();

        boolean [] visited = new boolean[g.getNumber()];

        queue.add(v);

        while(!queue.isEmpty()) {
            v = queue.poll();

            visited[v] = true;

            System.out.print(v);

            for (Integer adj : g.getAdjastensylist(v)) {
                if (!visited[adj]) {
                    queue.add(adj);
                }
            }

        }
    }
}
