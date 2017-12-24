package trees_graphs;


import java.util.LinkedList;

public class DFS {
	private Graph<Integer> g;
	public DFS(Graph<Integer> g) {
		this.g=g;
	}
	public boolean find(int a){
		for(GNode<Integer> n:g.nodes){
			n.status=GNodeStatus.UNVISITED;
		}
		LinkedList<GNode<Integer>> stack= new LinkedList<GNode<Integer>>();
		stack.addFirst(g.nodes.get(0));
		while(!stack.isEmpty()){
			GNode<Integer> n = stack.removeFirst();
			n.status=GNodeStatus.VISITING;
			if(n.value==a) return true;
			for(GNode<Integer> n1:n.neighbours){
				if(n1.status == GNodeStatus.UNVISITED){
					stack.add(n1);
				}
			}
		}
		return false;
	}

}
