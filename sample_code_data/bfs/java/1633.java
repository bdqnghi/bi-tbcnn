import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BFS {
    private static int distance(ArrayList<Integer>[] adj, int s, int t) {
        //write your code here
		Graph g = new Graph(adj);
		g.traverseBFS(s);
		return g.getMinDistance(t);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer>[] adj = (ArrayList<Integer>[])new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            x = scanner.nextInt();
            y = scanner.nextInt();
            adj[x - 1].add(y - 1);
            adj[y - 1].add(x - 1);
        }
        int x = scanner.nextInt() - 1;
        int y = scanner.nextInt() - 1;
        System.out.println(distance(adj, x, y));
    }
}

class Graph {
	private ArrayList<Integer>[] adjList = null;
	private int[] distance;
	private Queue<Integer> queue;
	final static private int INFINITY = -1;
	
	public Graph(ArrayList<Integer>[] adjList){
		this.adjList = adjList;
		distance = new int[adjList.length];
	}
	
	public void traverseBFS(int origin){
		for(int i = 0; i < adjList.length; ++i){
			distance[i] = INFINITY;
		}
		distance[origin] = 0;
		queue = new LinkedList<Integer>();
		queue.add(origin);
		ArrayList<Integer> neighbours = null;
		while(queue.peek() != null){
			int vertex = queue.poll();
			neighbours = adjList[vertex];
			for(int i = 0; i < neighbours.size(); ++i){
				int v = neighbours.get(i);
				if(distance[v] == INFINITY){
					queue.offer(v);
					distance[v] = distance[vertex] + 1;
				}
			}
		}
	}
	
	public int getMinDistance(int vertex){
		return distance[vertex];
	}
}