package Main;

import java.util.ArrayList;
import java.util.Queue;
import java.util.Stack;
/**
 * This class is responsible for implementing the depth first search technique using a stack
 * 
 * @author Tommy
 *
 */
public class DFS extends Search {

	//Stack used to implement depth first search
	static Stack<String> lifo=new Stack<String>();
	
	/**
	 * sets the list of intersections to be used in the search
	 * @param fileLines
	 */
	DFS(ArrayList<String> fileLines){
		lines=fileLines;
	}
	
	/**
	 * performs the breadth first search;
	 */
	public void search(){
		setStartTime();
		
		String start=getStart();
		String end=getEnd();
		lifo.push(start);
		
		//Loop continues untill stack is empty or the destination has been found
		while(!lifo.isEmpty()){
			current=lifo.pop();
			//If final destination has been found then end
			if(current.equals(end)){
				addToVisited(current);
				break;
			}
			else{
				Queue<String> neighbors=getConnections(current);//List containing all the possible destinations from a given country
				//While the country has destinations and those destinations have not been visited
				while(!neighbors.isEmpty()){
					if(!haveVisited(neighbors.peek())){
					lifo.push(neighbors.remove());
					}
				}
				addToVisited(current);
			
			}
		}
		
		setEndTime();
	}//end of search()
	
	
	
	
}
