package Main;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
/**
 * !!! - NOT COMPLETE - !!!
 * @author Tommy
 *
 */
public class BFS extends Search{

	static Queue<String> fifo=new LinkedList<String>();
	
	BFS(ArrayList<String> fileLines){
		lines=fileLines;
	}
	
	public void search(){
		setStartTime();
		
		String start=getStart();
		String end=getEnd();
		fifo.add(start);
		
		while(!fifo.isEmpty()){
			current=fifo.remove();
			if(current.equals(end)){
				addToVisited(current);
				break;
			}
			else{
				Queue<String> neighbors=getConnections(current);
				while(!neighbors.isEmpty()){
					if(!haveVisited(neighbors.peek())){
					fifo.add(neighbors.remove());
					}
				}
				addToVisited(current);
			
			}
		}
		setEndTime();
	}
	
}
