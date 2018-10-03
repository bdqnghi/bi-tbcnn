package com.foran.graph.tools;

import com.foran.graph.Edge;
import com.foran.graph.Node;
import com.foran.graph.Graph;

/***
 * DFS class, meant to be used statically on a given Graph.  Will do a DFS traversal of the 
 * graph labeling all edges and nodes accordingly.
 *
 * @author Andrew Foran
 * ***/

public class DFS{
	public static final int DISCOVERY = 1;
	public static final int BACK = 0;
	public static final int UNEXPLORED = -1;
	
	/***
	* The entry point for a DFS search of a given Graph.  Iterates through all nodes in the 
	* graph and is the node has yet to be discovered calls DFSVisit on it.  The DFSVisit will
	* discover the connected component containing that node and the next undiscovered node 
	* will be found and visited.
	*
	* @param graph The Graph to be studied.
	***/


	public static void DFSearch(Graph graph) {
		for(Node n : graph.nodes) {
			n.explored = false;
		}
		
		for(Edge e: graph.edges) {
			e.explored = false;
			e.label = UNEXPLORED;
		}
		
		for(Node n : graph.nodes) {
			if(n.explore() == true) {
				DFSVisit(n);
			}
		}
		
	}
	
	public static void DFSFromNode(Graph graph, Node startNode) {
		for(Node n : graph.nodes) {
			n.explored = false;
		}
		
		for(Edge e: graph.edges) {
			e.explored = false;
			e.label = UNEXPLORED;
		}

		if(startNode.explore() == true) {
			DFSVisit(startNode);
		}
	}
	/***
	* Searches the edges connected to a node and explores them using recursive DFSVisit() calls
	*
	* @param n The node to be studied	
	***/


	public static void DFSVisit(Node n) {
		for(Edge e : n.edgeAdjacencies) {
			if(e.explored == false) {
				Node w = e.opposite(n);
				if(w != null && w.explore() == true) {
					e.explored= true;
					e.label = DISCOVERY;
					DFSVisit(w);
				} else {
					e.explored = true;
					e.label = BACK;
				}
			}
		}
	}
}
