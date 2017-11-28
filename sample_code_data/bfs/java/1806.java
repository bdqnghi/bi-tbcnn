package com.shankar.trees;

import java.util.Arrays;
import java.util.LinkedList;

public class BFS {

	private static StringBuilder sb = new StringBuilder();

	public static void main(String args[]) {

		BinaryTree bt = new BinaryTree();
		Arrays.asList(8, 5, 4, 13, 9, 15, 1, 6, 2).stream().map(x -> {
			Node n = new Node();
			n.value = x;
			bt.insert(n);
			return x;
		}).count();

		bfs(bt);

		//System.out.println(sb);
	}

	public static void bfs(BinaryTree bt) {

		sb.append(bt.getRoot() + " ");
		printNodeBFS(bt.getRoot());
	}

	private static void printNodeBFS(Node root) {
		LinkedList<Node> queue = new LinkedList<Node>();
		queue.add(root);
		
		while(!queue.isEmpty()){
			Node node = queue.remove();
			System.out.println(node.value);
			if(node.left != null)
				queue.add(node.left);
			if(node.right != null)
				queue.add(node.right);
			
		}

	}

}
