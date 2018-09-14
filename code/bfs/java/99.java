package chapter3.search;

import java.util.LinkedList;

import chapter3.nodes.Node;
import chapter3.nodes.Tree;

public class BFS implements ISearch {

	private LinkedList<Node> bfs;

	public BFS() {
		bfs = new LinkedList<>();
	}

	@Override
	public void start(Tree t) {
		System.out.println("-- BREADTH_FIRST_SEARCH START --");
		bfs.add(t.getRootNode());
		while (!bfs.isEmpty()) {
			expand();
			printCurrentState();
		}
		System.out.println("-- SEARCH END --\n");
	}

	private void expand() {
		Node n = visit();
		if (n.getChildList() == null) return;
		bfs.addAll(n.getChildList());
	}

	private Node visit() {
		Node n = bfs.getFirst();
		System.out.print("Visit : " + String.format("%5s", n.getId()) + "  |  ");
		bfs.removeFirst();
		return n;
	}

	private void printCurrentState() {
		for (int i = 0; i < bfs.size(); i++) {
			System.out.print(bfs.get(i).getId() + " -> ");
		}
		System.out.println("��");
	}
}