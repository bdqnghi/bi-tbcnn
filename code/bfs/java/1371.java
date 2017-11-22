package graphs;

import java.util.ArrayList;

//710 750
public class BFS {
 GraphInterface graph;
 GraphNode[] parNode;
 boolean[] isVisited;
 
 public BFS(GraphInterface graph){
	 this.graph = graph;
	 parNode = new GraphNode[this.graph.getNoOfVertices()];
	 isVisited = new boolean[this.graph.getNoOfVertices()];
 }
 
 public ArrayList<GraphNode> findPath(GraphNode at, GraphNode bt){
	 GraphNode a = graph.getNodeFromList(at);
	 GraphNode b = graph.getNodeFromList(bt);
	 doBFS(a);
	 ArrayList<GraphNode> list = new ArrayList<GraphNode>();
	 GraphNode tmp = b;
	 while((tmp!=null)&&(tmp.getDataNode().getData()!=a.getDataNode().getData())){
		 list.add(tmp);
		 tmp = parNode[tmp.getIndex()];
	 }
	 if(list.size()==1){
		 list.remove(0);
	 }
	 else{
		 list.add(a);
	 }
	 return list;
 }
 
 private void doBFS(GraphNode a){
	 ArrayList<GraphNode> queue = new ArrayList<GraphNode>();
	 isVisited[a.getIndex()] = true;
	 queue.add(a);
	 GraphNode itrNode;
	 
	 while(!queue.isEmpty()){
	    itrNode = queue.remove(0);
	    for(GraphNode node: itrNode.getAdjList()){
	    	if(isVisited[node.getIndex()]==false){
	    		isVisited[node.getIndex()]=true;
	    		parNode[node.getIndex()]=itrNode;
	    		queue.add(node);
	    	}
	    }
	 }
 }
}
