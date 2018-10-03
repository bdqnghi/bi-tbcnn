/*
 * See the file "LICENSE" for the full license governing this code.
 */
package se.liu.ida.nlp.sdp.toolkit.graph;

/**
 * Depth-first graph search.
 *
 * @author Marco Kuhlmann
 */
public class DFS {

	/**
	 * Whether to search the graph as an undirected graph.
	 */
	private final boolean undirected;

	/**
	 * The graph.
	 */
	private final Graph graph;

	/**
	 * The index of the run during which each node was (first) visited.
	 */
	private final int[] run;

	/**
	 * The number of runs.
	 */
	private int nRuns;

	/**
	 * The preorder timestamps of each node.
	 */
	private final int[] enter;

	/**
	 * The postorder timestamps of each node.
	 */
	private final int[] leave;

	/**
	 * A depth-first search on the specified graph.
	 *
	 * @param graph a graph
	 * @param undirected if {@code true}, the graph will be searched as an
	 * undirected graph
	 */
	public DFS(Graph graph, boolean undirected) {
		this.undirected = undirected;

		this.graph = graph;

		int nNodes = graph.getNNodes();
		this.run = new int[nNodes];
		this.enter = new int[nNodes];
		this.leave = new int[nNodes];
		computeTimestamps();
	}

	/**
	 * A depth-first search on the specified graph.
	 *
	 * @param graph a graph
	 */
	public DFS(Graph graph) {
		this(graph, false);
	}

	/**
	 * Computes the preorder and postorder timestamps for the inspected graph.
	 */
	private void computeTimestamps() {
		for (Node node : graph.getNodes()) {
			enter[node.id] = -1;
		}
		Timer timer = new Timer();
		for (Node node : graph.getNodes()) {
			if (enter[node.id] == -1) {
				computeTimestamps(node, timer);
				nRuns++;
			}
		}
	}

	/**
	 * Computes the preorder and postorder timestamps for the subgraph starting
	 * at the specified node.
	 *
	 * @param node the entry point for the subgraph
	 * @param timer the global timer
	 */
	private void computeTimestamps(Node node, Timer timer) {
		run[node.id] = nRuns;
		enter[node.id] = timer.tick();
		for (Edge outgoingEdge : node.getOutgoingEdges()) {
			// Only visit nodes that have not been visited before.
			if (enter[outgoingEdge.target] == -1) {
				computeTimestamps(graph.getNode(outgoingEdge.target), timer);
			}
		}
		if (undirected) {
			for (Edge incomingEdge : node.getIncomingEdges()) {
				if (enter[incomingEdge.source] == -1) {
					computeTimestamps(graph.getNode(incomingEdge.source), timer);
				}
			}
		}
		leave[node.id] = timer.tick();
	}

	/**
	 * Timer used in depth-first search.
	 */
	private static final class Timer {

		/**
		 * The current time.
		 */
		private int time;

		/**
		 * Returns the current time, then increments it.
		 *
		 * @return the current time
		 */
		public int tick() {
			return time++;
		}
	}

	/**
	 * Returns the number of runs of the search. This is the number of times the
	 * recursive search was called to cover all nodes in the graph.
	 *
	 * @return the number of runs of the search
	 */
	public int getNRuns() {
		return nRuns;
	}

	/**
	 * Test whether the specified edge is a self-loop.
	 *
	 * @param edge an edge in the searched graph
	 * @return {@code true} if the specified edge is a self-loop
	 */
	public boolean isSelfLoop(Edge edge) {
		return edge.source == edge.target;
	}

	/**
	 * Test whether the specified edge is a back edge.
	 *
	 * @param edge an edge in the searched graph
	 * @return {@code true} if the specified edge is a back edge
	 */
	public boolean isBackEdge(Edge edge) {
		return enter[edge.target] < enter[edge.source] && leave[edge.source] < leave[edge.target];
	}

	/**
	 * Test whether the searched graph is cyclic.
	 *
	 * @return {@code true} if the searched graph is cyclic
	 */
	public boolean isCyclic() {
		for (Edge edge : graph.getEdges()) {
			if (isSelfLoop(edge) || isBackEdge(edge)) {
				return true;
			}
		}
		return false;
	}
}
