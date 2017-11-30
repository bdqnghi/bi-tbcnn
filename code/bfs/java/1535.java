package graph;

import arrayList.ArrayIndexList;
import arrayList.IndexList;
import nodeList.NodePositionList;
import nodeList.PositionList;

public class BFS<V, E, I, R> {
	protected Graph<V, E> graph;    
	protected Vertex<V> start;      
	protected I info;              
	protected R visitResult;        
	protected static Object STATUS = new Object();    
	protected static Object VISITED = new Object();   
	protected static Object UNVISITED = new Object(); 
	protected IndexList<PositionList<Vertex<V>>> layers;

	public R execute(Graph<V,E> g, Vertex<V> s, I in){
		graph = g;
		layers = new ArrayIndexList<PositionList<Vertex<V>>>(graph.numVertices());
		start = s;
		info = in;
		for(Vertex<V> v : graph.vertices()){
			unVisit(v);
		}

		for(Edge<E> e : graph.edges()){
			unVisit(e);
		}
		setup();
		return finalResult(bfsTrasversal(start));
	}

	protected R bfsTrasversal(Vertex<V> v){
		initResult();
		if(isDone()){
			visit(v);
			layers.add(0,new NodePositionList<Vertex<V>>());
			layers.get(0).addLast(v);
		}
		int i = 0;
		while(!layers.get(i).isEmpty()){
			layers.add(i+1,  new NodePositionList<Vertex<V>>());
			for(Vertex<V> vertexInLayer: layers.get(i)){
				for(Edge<E> e: graph.incidentEdges(vertexInLayer)){
					if(!isVisited(e)){
						visit(e);
						Vertex<V> w = graph.opposite(vertexInLayer, e);
						if(!isVisited(w)){
							traverseDiscovery(e,vertexInLayer);
							if(isDone())break;
							visit(w);
							layers.get(i+1).addLast(w); 
							if(isDone())break;
						}
					}
				}
				if(isDone())finishVisit(vertexInLayer);

			} 	


			i++;
		}
		return result();
	}

	protected void visit(DecorablePosition<?> p) { p.put(STATUS, VISITED); }
	protected void unVisit(DecorablePosition<?> p) { p.put(STATUS, UNVISITED); }
	protected boolean isVisited(DecorablePosition<?> p) {
		return (p.get(STATUS) == VISITED);
	}



	protected void setup() {}
	protected void initResult() {}
	protected void startVisit(Vertex<V> v) {}
	protected void finishVisit(Vertex<V> v) {}
	protected void traverseDiscovery(Edge<E> e, Vertex<V> from) {}
	protected void traverseBack(Edge<E> e, Vertex<V> from) {}
	protected boolean isDone() { return false;  }
	protected R result() { return null; }
	protected R finalResult(R r) { return r;  }


}
