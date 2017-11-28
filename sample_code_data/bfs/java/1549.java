package lab11;

import java.util.*;

public class BFS {
	//	public void performBFS(UndirectedGraph undirectedGraph, int source){
	//		for (int v = 0; v < undirectedGraph.V; v++) {
	//			System.out.println("oi");
	//			undirectedGraph.v[v].setColor("WHITE");
	//			undirectedGraph.v[v].d = Integer.MAX_VALUE;
	//			undirectedGraph.v[v].pi = (Integer) null;
	//		}
	//		
	//		undirectedGraph.v[source].color = "GRAY";
	//		undirectedGraph.v[source].d = 0;
	//		undirectedGraph.v[source].pi = (Integer) null;
	//		
	//		Queue<Integer> q = new ArrayDeque();
	//		q.add(source);
	//		
	//		while(!q.isEmpty()){
	//			int n = q.remove();
	//			for(int w : undirectedGraph.adj[n]){
	//				if(undirectedGraph.v[w].color == "WHITE"){
	//					undirectedGraph.v[w].color = "GRAY";
	//					undirectedGraph.v[w].d = undirectedGraph.v[n].d + 1;
	//					undirectedGraph.v[w].pi = n;
	//					q.add(w);
	//				}
	//			}
	//			undirectedGraph.v[n].color = "BLACK";
	//		}
	//	}

	private static final int INFINITY = Integer.MAX_VALUE;
	private boolean[] marked;  // marked[v] = is there an s-v path
	private int[] edgeTo;      // edgeTo[v] = previous edge on shortest s-v path
	private int[] distTo;      // distTo[v] = number of edges shortest s-v path

	public BFS(UndirectedGraph G, int s) {
		marked = new boolean[G.V];
		distTo = new int[G.V];
		edgeTo = new int[G.V];
		bfs(G, s);
	}

	private void bfs(UndirectedGraph G, int s) {
		Queue<Integer> q = new ArrayDeque<Integer>();
		for (int v = 0; v < G.V; v++) distTo[v] = INFINITY;
		distTo[s] = 0;
		marked[s] = true;
		q.add(s);

		while (!q.isEmpty()) {
			int v = q.remove();
			for (int w : G.adj[v]) {
				if (!marked[w]) {
					edgeTo[w] = v;
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.add(w);
				}
			}
		}
	}
	
	public void printPath(UndirectedGraph undirectedGraph, int s, int v){
		if (v == s)
			System.out.print(s);
		else if (edgeTo[v] != 0)
			System.out.print("no path");
		else{
			printPath(undirectedGraph, s, edgeTo[v]);
		}
		System.out.print(v);	
		
	
	}

	public boolean hasPathTo(int v) {
		return marked[v];
	}

	public Iterable<Integer> pathTo(int v) {
		if (!hasPathTo(v)) return null;
		Stack<Integer> path = new Stack<Integer>();
		int x;
		for (x = v; distTo[x] != 0; x = edgeTo[x])
			path.push(x);
		path.push(x);
		return path;
	}

	public int distTo(int v) {
		return distTo[v];
	}

	public void printPath(UndirectedGraph undirectedGraph){
		for (int v1 = 0; v1 < undirectedGraph.V; v1++) {
			if (hasPathTo(v1)) {
				System.out.println("0 ---> " + v1 + ": ");
				for (int x : pathTo(v1)) {
					if (x == undirectedGraph.E) System.out.print(x);
					else        System.out.print(x + ", ");
				}
				System.out.println();
			}

			else {
				System.out.printf("%d to %d (-):  not connected\n",undirectedGraph.V, v1);
			}

		}
	}
}