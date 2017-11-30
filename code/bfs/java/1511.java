package implementation;

/* package codechef; // don't place package name! */

import java.util.*;
/*import java.lang.*;
import java.io.*;
*/

/* Name of the class has to be "Main" only if the class is public. */
class BFS {
	 
	HashMap<Integer, LinkedList<Integer>> adj; 
	HashMap<Integer,Boolean> visited; 
	
	 public  BFS(int[] nodes){
		 adj = new HashMap<Integer,LinkedList<Integer>>();
		 visited = new HashMap<Integer,Boolean>();
		for(int i=0;i<nodes.length;i++){
			adj.put(nodes[i], new LinkedList<Integer>());
			visited.put(nodes[i], false);
		}
	}
	 void addEdge(int v1,int v2){
		 adj.get(v1).add(v2);
	 }
 
	 LinkedList<Integer> getNeighbors(int v){
		 return adj.get(v);
	 }
	 void bfs(BFS g,int n){
		 Queue<Integer> q = new LinkedList<Integer>();
		 q.add(n);
 
		while(!q.isEmpty()){
			n = q.peek();
			System.out.print(n+" ");
			g.visited.put(n, true);
 
			Iterator<Integer> i = g.adj.get(q.peek()).iterator(); // peek() returns the head of the queue without removing
			q.poll(); // poll() removes and returns the head of the queue
			while(i.hasNext() ){
				Integer l = i.next();
				if(!g.visited.get(l)){					
					g.visited.put(l, true);
					q.add(l);				
				}
			}
		}
 
	 }
	 // runtime: O(V+E) , no of vertices + edges
	 public void dfs(BFS g, int n){
		 if(!g.visited.get(n)){
			 System.out.print(n+" ");
			 g.visited.put(n, true);
			 Iterator<Integer> i = g.adj.get(n).iterator();
			 while(i.hasNext()){
				 Integer l = i.next();
				 dfs(g,l);
			 }
		 }
	 }
 
	 static boolean isCyclic(BFS g,int n){
		 if(g.visited.get(n))
			 return true;
		 g.visited.put(n, true);
		 Integer k = null;
		 // try statement to return false if 
		 // k throws an exception:No such element exists
		 try{
		  k = g.adj.get(n).element();
		 }
		 catch(Exception e){
			 return false;
		 }
		 return isCyclic(g, k);
 
	 }
	public static void main (String[] args) throws java.lang.Exception
	{
	
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of vertices");
		int vertices=s.nextInt();
		int[]a=new int[vertices+1];
		for(int i=0;i<=vertices;i++)
			a[i]=i;
			BFS graph= new BFS(a);
			int source, destination;
			System.out.println("Enter number of queries");
			int queries=s.nextInt();
			System.out.println("Enter source and destination respectively");
			while(queries>0)
			{
			    source=s.nextInt();
			    destination=s.nextInt();
			    graph.addEdge(source,destination);
			    queries--;
			}
			System.out.println("Enter position from where to start BFS");
			int temp=s.nextInt();
			System.out.println("The BFS of the Graph starting from "+temp+" is: ");
			graph.bfs(graph,temp);
			System.out.println("Enter position from where to start DFS");
			int t1=s.nextInt();
			graph.dfs(graph,t1);
			s.close();
	}
}

