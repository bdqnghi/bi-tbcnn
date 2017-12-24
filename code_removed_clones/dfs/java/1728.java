package graphs;

import java.util.Arrays;
import java.util.Stack;

/**
 * Depth First Search O(V+E)
 * Created by dwaipaya on 1/21/16.
 */
public class DFS extends GraphAlgo{

    DFS(int nodes){
        super(nodes);
    }


    /** DFS driver function
     * call dfsUtil for all unvisited nodes
     */
    void dfs(){
        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[graph.nodes];
        for(int i = 0; i< graph.nodes; i++) {
            if(!visited[i])
                dfsUtil(i, visited);
        }
        System.out.println(stack);
    }

    /**
     *
     * @param startNode startNode
     * @param visited visited matrix
     */
    void dfsUtil(int startNode,boolean[] visited){
        visited[startNode]=true;    //mark startNode as visited
        if(graph.arr[startNode]!=null) {    //if startNode has adjacency list
            for (Edge node : graph.arr[startNode]) {   //traverse all destinations and call dfsUtil if i
                                                            //its not visited
                int dest = node.dest;
                if(!visited[dest]){
                    dfsUtil(dest,visited);
                }
            }
        }
        System.out.println(startNode);
    }

    boolean dfsCycle(){
        boolean[] visited = new boolean[graph.nodes];
        boolean[] recStack = new boolean[graph.nodes];
        int[] parent = new int[graph.nodes];
        Arrays.fill(parent,-1);
        for(int i = 0; i< graph.nodes; i++) {
            if(dfsCycleUtil(i, visited,recStack,parent)) {
                return true;
            }
        }
        return false;
    }

    boolean dfsCycleUtil(int startNode,boolean[] visited, boolean[] recstack,int[] parent){
        if(!visited[startNode]) {

            visited[startNode] = true;
            recstack[startNode] = true;
            if (graph.arr[startNode] != null) {
                for (Edge node : graph.arr[startNode]) {
                    int dest = node.dest;
                    if (!visited[dest]){ // if not visited destination
                        parent[dest]=startNode;
                        if(dfsCycleUtil(dest,visited,recstack,parent))
                            return true;

                    }
                    if(recstack[dest]) {  // if dest is in recursion stack
                        System.out.print(dest);
                        int temp =startNode;
                        while ((temp!=dest)){
                            System.out.print("<--"
                                    +temp);
                            temp=parent[temp];
                        };
                        return true;
                    }
                }
            }
        }
        recstack[startNode]=false;
        return false;
    }


    public static void main(String args[]) {
        DFS d = new DFS(4);
        d.graph.addEdge(3,0,1);
        System.out.println("&&&&&&&&&&&&");
        d.graph.print();
        System.out.println("\n"+d.dfsCycle());
    }
}
