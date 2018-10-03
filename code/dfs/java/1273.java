package practice;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;



//Given a graph ,checking if it is a tree or not

public class DFS {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int v = sc.nextInt();
		int e = sc.nextInt();
		if (e + 1 != v) {
			System.out.println("No");
			return;
		} else {
			ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i <= v; i++) {
				graph.add(new ArrayList<Integer>());
			}
			for (int i = 0; i < e; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				graph.get(a).add(b);
				graph.get(b).add(a);
			}

			if (dFS(graph, v)) {
				System.out.println("yes");
			} else {
				System.out.println("no");
			}
		}
	}

	private static boolean dFS(ArrayList<ArrayList<Integer>> graph, int v) {
		boolean[] visited = new boolean[v + 1];
		Stack<Integer> s = new Stack<Integer>();
	    s.add(1);
		visited[1] = true;
		
		while(!s.isEmpty()){
			int temp=s.pop();
			ArrayList<Integer> neighbours=graph.get(temp);
			for(int n:neighbours){
				if(!visited[n]){
					s.add(n);
					visited[n]=true;
				}
			}
			
		}
		
		for (int i = 1; i <= v; i++) {
			if (!visited[i]) {
				return false;
			}
		}

		return true;
	}

}
