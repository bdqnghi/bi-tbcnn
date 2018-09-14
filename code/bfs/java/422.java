// java.utils imports omitted for brevity

import org.neo4j.graphdb.Direction;
import org.neo4j.graphdb.Node;
import org.neo4j.graphdb.Relationship;

/*
 * Breadth First Search Traverser 
 */
public class BFSTraverser {
	protected Queue<Node> queue;
	protected List<Node> visitedNodes;
	protected Node rootNode;
	
	public BFSTraverser(Node rootNode) {
		this.queue = new LinkedList<Node>();
		this.rootNode = rootNode;
		this.queue.add(this.rootNode);
		this.visitedNodes = new ArrayList<Node>();
	}

	//Getters and setters omitted for brevity
	
	/*
	 * Process BFS algorithm and return the last reached Node
	 */
	public Node next(){
		Node removedNode = queue.remove(); 
		visitedNodes.add(removedNode);
		
		Iterator<Relationship> itRel = removedNode.getRelationships(Direction.OUTGOING).iterator();
		while(itRel.hasNext()){
			Node currentParent = itRel.next().getEndNode();
			
			if(!visitedNodes.contains(currentParent)){
				queue.add(currentParent);
			}
		}
		return removedNode;
	}
}