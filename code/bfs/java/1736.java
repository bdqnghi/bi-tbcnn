package week1;
import java.util.ArrayList;
/**
 * BFS data structure to compute path with fewest edges in flow graph
 *
 * @author Vivekanand Ganapathy Nagarajan
 * @version 1.0 September 1st, 2016
 */

class BFS {

    private int startVertex;
    private FlowGraph graph;
    private int[] path;
    private boolean[] visited;



    BFS(int startVertex, FlowGraph graph) {
        this.startVertex = startVertex;
        this.graph = graph;
        this.path = new int[graph.getSize()];
        this.visited = new boolean[graph.getSize()];
    }

    public void run() {
        visited[startVertex] = true;
        Queue<Integer> queue = new Queue<Integer>();
        queue.enqueue(startVertex);
        while (!queue.isEmpty()) {
            int vertex = queue.dequeue();
            for (int flowEdgeId: graph.getIds(vertex)){
                FlowEdge flowEdge = graph.flowEdges[flowEdgeId];
                if (flowEdge.isFull()){
                    //discard the edge
                    continue;
                }
                int neighbor = flowEdge.endVertex;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.enqueue(neighbor);
                    path[neighbor] = flowEdgeId;
                }

            }
        }
    }


    /**
     * Get path of the indices from source to destination vertex
     * @param destVertex destination vertex
     * @return
     */
    ArrayList<Integer> pathTo(int destVertex) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        if (!visited[destVertex]){
            return result;
        }

        while (destVertex != startVertex){
            int edgeIndex = path[destVertex];
            result.add(edgeIndex);
            FlowEdge flowEdge = graph.flowEdges[edgeIndex];
            destVertex = flowEdge.startVertex;
        }
        return result;
    }

    boolean containsPath(int destVertex){
        return visited[destVertex];
    }
}