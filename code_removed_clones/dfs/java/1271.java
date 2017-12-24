package com.funnybear.advanced.algorithm.DepthFirstSearch.Basic;

import java.util.List;
import java.util.Stack;

import com.funnybear.advanced.algorithm.DepthFirstSearch.Common.Vertex;

public class DFS {

	public void search(List<Vertex> list) {
		for (Vertex v : list) {
			// This for loop is for handling separate components in the graph. 
			
			if (!v.isVisited()) {
				dfsWithStack(v);
			}

		}
	}

	public void dfsWithStack(Vertex root) {

		Stack<Vertex> stack = new Stack<>();

		root.setVisited(true);
		stack.push(root);

		while (!stack.isEmpty()) {

			Vertex vertex = stack.pop();
			vertex.setVisited(true);

			System.out.println(vertex + " ");

			for (Vertex v : vertex.getNeighbourList()) {

				stack.push(v);

			}

		}

	}

	public void dfsWithRecursion(Vertex root) {

		root.setVisited(true);

		System.out.println(root + " ");

		for (Vertex v : root.getNeighbourList()) {

			dfsWithRecursion(v);

		}

	}

}
