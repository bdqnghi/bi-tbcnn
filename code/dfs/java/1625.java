import java.util.ArrayList;

public class Dfs {
	private Integer[][] nodes; //Weighted adjacency matrix
	private int startNode; //Default is 0
	private int tos; //"Top of Stack"
	private int check;
	private ArrayList<Integer> visited; //List of visited nodes
	private ArrayList<Integer> stack; //Stack data type for nodes that are not visited yet
	private static String traversal; //Stores the traversal of the visited nodes
	
	public Dfs() {
		startNode = 0;
		check = 0;
		visited = new ArrayList<Integer>();
		stack = new ArrayList<Integer>();
		traversal = "Depth-First Search traversal returned:\n";
		
		getNodes();
		doDFS(startNode);
	}
	
	public void getNodes() { //Gets the weighted adjacency matrix from Center class
		nodes = Center.getWam();
	}
	
	public void doDFS(int startNode) { //Simulates Depth-First Search
		stack.add(startNode);
		while (stack.size() != 0) {
            //Check if the last node in the stack is already visited
            tos = stack.get(stack.size() - 1);
            if (!visited.contains(tos)) {
                visited.add(tos);
            }
            //Check if each adjacent node has already been visited
            for (int i=0; i<nodes[tos].length; i++) {
                if (!visited.contains(i) && nodes[tos][i] != 0) {
                    stack.add(i);
                    check = 0;
                    break;
                } else if (visited.contains(i) && nodes[tos][i] != 0){
                    check = 1;
                }
                
            }
            if (check == 1) {
                stack.remove(stack.size() - 1);
            }
        }
		
		setTraversal(visited);
	}
	
	public void setTraversal(ArrayList<Integer> visited) { //Sets the outcome of the DFS into a String
		for (int i=0; i<visited.size(); i++) {
			traversal = traversal + " " + visited.get(i);
		}
	}
	
	public static String getTraversal() { //Gets the "traversal" String
		return traversal;
	}
}