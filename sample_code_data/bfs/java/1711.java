void bfsTraversal( Graph graph )
{
	boolean[] found = new boolean[ graph.numVertices() ];
	for every Vertex v in graph.vertices()
		found[v] = false;
	for every Vertex v in graph.vertices()
	if ( !found[v] )
		bfsExplore(graph, found, v);
}
void bfsExplore( Graph graph, boolean[] found, Vertex root )
{ 
	Queue<Vertex> waiting = new QueueInArray<Vertex>(graph.numVertices() - 1 );
	waiting.enqueue(root);
	found[root] = true;
	do {
		Vertex vertex = waiting.dequeue(); TREAT(vertex);
		for every Vertex w in graph.outAdjacentVertices(vertex)
			if ( !found[w] ) {
				waiting.enqueue(w);
				found[w] = true;
			}
	}
	while ( !waiting.isEmpty() );
}
