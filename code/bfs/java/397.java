package com.datastruct.Mertix;

/**
 * 广度优先搜索
 * @author huangxw
 *
 */
public class BFS {
	
	public static void main(String[] args) {
		
		Graph graph = new Graph();
		graph.reset();
		graph.addVertex('A');
		graph.addVertex('B');
		graph.addVertex('C');
		graph.addVertex('D');
		graph.addVertex('E');
		graph.addVertex('F');
		
		
		graph.addEage('A', 'B');
		graph.addEage('D', 'B');
		graph.addEage('B', 'E');
		graph.addEage('A', 'C');
		graph.addEage('C', 'F');
		


		
		System.out.println("visitor:");
		graph.BFS();

		

	}
	
	
}
