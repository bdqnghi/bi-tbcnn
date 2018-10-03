package strategy.traversal;

import java.util.List;
import java.util.Stack;

import strategy.tree.Node;
import strategy.tree.Tree;

/**
 * Concrete strategy
 * @author alenka
 *
 */
public class DFS implements ITraversalIterator {

	Stack<Node> storage = new Stack<Node>();
	boolean first = true;

	public DFS(Tree tree) {
		storage.add(tree.getRoot());
	}
	
	@Override
	public Node next() {
		Node node = storage.peek();
		
		while (node.getUnivisitedChildNode() != null) {
			Node explored = node.getUnivisitedChildNode();
			explored.setExplored(true);
			storage.add(explored);
			
			node = explored;
		}

		return storage.pop();
	}

	@Override
	public boolean hasNext() {
		return !storage.isEmpty();
	}

}
