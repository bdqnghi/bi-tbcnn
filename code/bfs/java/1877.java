package trees_graphs;


import java.util.HashMap;
import java.util.HashSet;

import stacks_queues.Queue;

public class BFS {
	private Graph<Integer> g;
	public BFS(Graph<Integer> g) {
		this.g=g;
	}
	public boolean find(int a){
		for(GNode<Integer> n:g.nodes){
			n.status=GNodeStatus.UNVISITED;
		}
		Queue<GNode<Integer>> queue= new Queue<GNode<Integer>>();
		queue.insert(g.nodes.get(0));
		while(!queue.isEmpty()){
			GNode<Integer> n = queue.remove();
			n.status=GNodeStatus.VISITING;
			if(n.value==a) return true;
			for(GNode<Integer> n1:n.neighbours){
				if(n1.status == GNodeStatus.UNVISITED){
					queue.insert(n1);
				}
			}
		}
		return false;
	}

}
