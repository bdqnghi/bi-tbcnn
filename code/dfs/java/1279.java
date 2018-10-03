/**
 * Dfs --- class to conduct the DFS for nodes loaded into
 * both an adjacency matrix and an adjacency list.
 * @author    Matt Schulman
 */

import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Dfs {	
	/**
	   * conducts a DFS
	   * @param an adjacency matrix (2d array), the adjacencyList (an array of linked lists),
	   * a boolean describing if the search should be for a matrix or for a list, a String
	   * representing the file name, an int representing the number of users, and an int
	   * representing the first node
	   * @exception IOException
	   * @return none
	   */
	@SuppressWarnings("rawtypes")
	public static void dfs(int[][] adjacencyMatrix, LinkedList[] adjacencyLines, 
			boolean trueIfMatrix, String fileName, int numOfUsers, int firstNode) throws IOException {
        System.out.print("DFS Order : "+firstNode);
        
        //create queues and stacks to track which nodes have already been visited and which 
        //nodes are next in the DFS
        Queue<Integer> alreadyVisited = new LinkedList<Integer>();
		Stack<Integer> stack = new Stack<Integer>();
		stack.push(firstNode);
		alreadyVisited.add(firstNode);
		
		//nodeCounter counts the number of nodes that have been visited
		int nodeCounter = 1;
        while(!stack.isEmpty()) {
        	int curVertex = stack.peek();
        	int childVertex = getUnvisitedChildVertex(curVertex, numOfUsers, 
        			adjacencyMatrix, adjacencyLines, alreadyVisited, trueIfMatrix);
        	if (childVertex != -1) {
        		System.out.print(" -> "+childVertex);
        		alreadyVisited.add(childVertex);
        		nodeCounter++;
        		stack.push(childVertex);
        	}
        	else {
        		stack.pop();
        	}
        }
        System.out.println();
        System.out.println("The DFS reached a total of "+nodeCounter+" nodes.");
	}
	
	/**
	   * gets an unvisited child node of the input node (if one exists)
	   * @param an int representing the current vertex, an int representing the number of users,
	   * the adjacency matrix (a 2d int array), the adjacency list (an array of linked lists),
	   * an integer queue describing which nodes have already been visited, and a boolean
	   * representing if the search is being done with a matrix or a list.
	   * @exception IOException
	   * @return the int corresponding with the child node. returns -1 if no unvisited child
	   * node exists
	   */
	private static int getUnvisitedChildVertex(int curVertex, int numOfUsers, 
			int[][] adjacencyMatrix, @SuppressWarnings("rawtypes") LinkedList[] adjacencyLines, 
				Queue<Integer> alreadyVisited, boolean trueIfMatrix) {
    	//if (trueIfMatrix) {
		for (int i = 0; i <= numOfUsers; i++) {    		
			if (trueIfMatrix) {
				if (adjacencyMatrix[curVertex][i] == 1 && !alreadyVisited.contains(i)) {
					return i;
				}
			}
			else {
				if (adjacencyLines[curVertex].contains(i) && !alreadyVisited.contains(i)) {
					return i;
				}
			}		
		}
	return -1;
	}
}

