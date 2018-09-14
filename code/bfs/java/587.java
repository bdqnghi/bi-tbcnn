package com.competition.algorithm;

import java.util.Stack;

import com.competition.graph.Edge;
import com.competition.graph.Graph;

public class BFS {
	private boolean[] marked;
	private int[] edgeTo;
	private int[] distTo;
	private final int s;
	
	public BFS(Graph G , int s){
		marked = new boolean[G.V()];
		edgeTo = new int[G.V()];
		distTo = new int[G.V()];
		for(int i = 0; i < distTo.length; i ++)
		{
			distTo[i] = Integer.MAX_VALUE;
		}
		distTo[s] = 0;
		this.s = s;
		bfs(G , s);
	}
	
	private void bfs(Graph G , int s){
		int[] quene = new int[G.V()];
		int head = 0;
		int tail = 0;
		marked[s] = true;
		quene[tail] = s;
		while(head <= tail){
			int v = quene[head++];
			for(Edge e:G.adj(v)){
				int w = e.getW();
				if(!marked[w]){
					edgeTo[w] = v;
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					quene[++tail] = w;
				}
			}
		}
	}
	
	public boolean hasPathTo(int v){
		return marked[v];
	}
	
	public int distTo(int v){
		return distTo[v];
	}
	
	public Stack<Integer> pathTo(int v){
		if(!hasPathTo(v))
			return null;
		Stack<Integer> path = new Stack<Integer>();
		for(int x = v;x != s; x = edgeTo[x]){
			path.push(x);
		}
		path.push(s);
		return path;
	}
	
	public int[] getDistTo(){
		return distTo;
	}
}
