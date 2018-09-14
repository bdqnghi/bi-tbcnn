package dna.updates.generators.sampling;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;

import dna.graph.Graph;
import dna.graph.nodes.Node;
import dna.updates.generators.sampling.startNode.StartNodeSelectionStrategy;

/**
 * A sampling algorithm based on breadth first search
 * 
 * @author Benedict Jahn
 * 
 */
public class BFS extends SamplingAlgorithm {

	private HashSet<Node> nodesInQueue;
	private LinkedList<Node> queue;
	private Node currentNode;

	/**
	 * Creates an instance of the breadth first sampling algorithm
	 * 
	 * @param fullGraph
	 *            the graph the algorithm shall sample
	 * @param startNodeStrat
	 *            the strategy how the algorithm will select the first node
	 * @param costPerBatch
	 *            how many steps the algorithm shall perform for one batch
	 * @param ressouce
	 *            the maximum count of steps the algorithm shall perform, if
	 *            initialized with 0 or below the algorithm will walk until the
	 *            graph is fully visited
	 * @param parameters
	 *            the parameters which makes this algorithm unique and which
	 *            will be added to the name
	 */
	public BFS(Graph fullGraph, StartNodeSelectionStrategy startNodeStrategy,
			int costPerBatch, int resource, SamplingStop stop,
			WalkingType walkingType) {
		super("BFS", fullGraph, startNodeStrategy, costPerBatch, resource,
				stop, walkingType);

		queue = new LinkedList<Node>();
		nodesInQueue = new HashSet<Node>();
		currentNode = null;
	}

	@Override
	protected Node findNextNode() {
		if (queue.isEmpty()) {
			noNodeFound();
			return null;
		}

		currentNode = queue.poll();
		ArrayList<Node> neighborsList = getUnvisitedNeighbors(currentNode);
		for (Node n : neighborsList) {
			if (!nodesInQueue.contains(n)) {
				queue.add(n);
				nodesInQueue.add(n);
			}
		}
		nodesInQueue.remove(currentNode);
		return currentNode;
	}

	@Override
	protected Node init(StartNodeSelectionStrategy startNode) {
		currentNode = startNode.getStartNode(this.fullGraph);
		nodesInQueue.add(currentNode);

		ArrayList<Node> neighborsList = getUnvisitedNeighbors(currentNode);
		for (Node n : neighborsList) {
			if (!nodesInQueue.contains(n)) {
				queue.add(n);
				nodesInQueue.add(n);
			}
		}
		return currentNode;
	}

	@Override
	protected void localReset() {
		queue = new LinkedList<Node>();
		nodesInQueue = new HashSet<Node>();
		currentNode = null;
	}

}
