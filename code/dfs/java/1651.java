package com.home.latest.graph;

import com.home.latest.ds.Stack;
import com.home.latest.ds.StackImpl;

import java.util.Arrays;

/**
 * Depth First Search Graph processing
 * Created by pranabdas on 1/8/16.
 */
public class DFS{

    private int source;
    private boolean[] marked;
    private int[] parent;

    public DFS(Graph G, int s){
        marked = new boolean[G.V()];
        parent = new int[G.V()];
        source = s;
        Arrays.fill(parent, -1);
        dfs_r(G, s);
    }

    public void dfs_r(Graph G, int v){
        marked[v] = true;
        for(int w : G.adj(v)){
            if(!marked[w]){
                parent[w] = v;
                dfs_r(G, w);
            }
        }
    }

    public void dfs_nr(Graph G, int s){
        Stack<Integer> stack = new StackImpl<>();
        marked[s] = true;
        stack.push(s);
        while(!stack.isEmpty()){
            int v = stack.pop();
            for(int w: G.adj(v)){
                if(!marked[w]){
                    marked[w] = true;
                    parent[w] = v;
                    stack.push(w);
                }
            }
        }
    }

    public int parent(int w){
        return parent(w);
    }

    public boolean hasPathTo(int v){
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v){
        if(!hasPathTo(v)) return null;
        Stack<Integer> pathTo = new StackImpl<>();
        for(int x = v ; x != source; x = parent[x]){
            pathTo.push(x);
        }
        pathTo.push(source);
        return pathTo;
    }

    public static void main(String[] args){
        Graph G = new UnDiGraph(7);
        G.addEdge(0, 6);
        G.addEdge(0, 1);
        G.addEdge(0, 2);
        G.addEdge(0, 5);
        G.addEdge(4, 6);
        G.addEdge(3, 4);
        G.addEdge(5, 3);
        G.addEdge(5, 4);
        G.printGraph();
        DFS d1 = new DFS(G, 0);
        System.out.println(d1.hasPathTo(6));
        for(Integer edge : d1.pathTo(3)){
            System.out.print(" " + edge + " ");
        }

        System.out.println();
        Graph G1 = new DiGraph(13);
        G1.addEdge(4, 2);
        G1.addEdge(2, 3);
        G1.addEdge(3, 2);
        G1.addEdge(6, 0);
        G1.addEdge(0, 1);
        G1.addEdge(2, 0);
        G1.addEdge(11, 12);
        G1.addEdge(12, 9);
        G1.addEdge(9, 10);
        G1.addEdge(9, 11);
        G1.addEdge(8, 9);
        G1.addEdge(10, 12);
        G1.addEdge(11, 4);
        G1.addEdge(4, 3);
        G1.addEdge(3, 5);
        G1.addEdge(6, 8);
        G1.addEdge(8, 6);
        G1.addEdge(5, 4);
        G1.addEdge(0, 5);
        G1.addEdge(6, 4);
        G1.addEdge(6, 9);
        G1.addEdge(7, 6);
        G1.printGraph();
        DFS d2 = new DFS(G1, 0);
        System.out.println(d2.hasPathTo(5));
        for(Integer edge : d2.pathTo(2)){
            System.out.print(" " + edge + " ");
        }
    }
}
