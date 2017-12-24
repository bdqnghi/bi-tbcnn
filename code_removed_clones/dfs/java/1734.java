/**
 * 
 */
package SearchAlgorithms;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Stack;

import MazeReadIn.Maze;
import MazeReadIn.Pair;
import MazeReadIn.ReadMaze;
import MazeReadIn.WriteMaze;
import static java.lang.System.*;



/**
 * @author zhenchengwang
 * Data structure: 1, queue -> Queue<Pair<Integer, Integer>> myQueue
 * 				   2, table to mark visited ->  int[][] canTravel 
 * 				   3, dictionary to remember the path -> Map<Pair<Integer, Integer>, Pair<Integer, Integer>> myMap
 * 				   4, path -> List<Pair<Integer, Integer>> myPath 
 *
 */
public class DFS {

	/* 
	 * canTravel: push adjacent node into queue, mark them as visited */
	public static int pushAdjacent(Stack<Pair<Integer, Integer>> myStack, int[][] canTravel, Pair<Integer, Integer> curr, Map<String, String> myMap, int[][] pathCost){
		
			int currX = curr.getFirst();
			int currY = curr.getSecond();
			 
			if(currX+1<canTravel.length && canTravel[currX+1][currY]==0){
				Pair<Integer, Integer> rightChild = new Pair(currX+1, currY);
				String parent = ""+currX+","+currY+"";
				String child = 	""+(currX+1)+","+currY+"";	
				myMap.put(child, parent);
				pathCost[currX+1][currY] = pathCost[currX][currY]+1;
				myStack.push(rightChild);
			}
			if(currY+1<canTravel[0].length && canTravel[currX][currY+1]==0){
				Pair<Integer, Integer> upChild = new Pair(currX, currY+1);
				String parent = ""+currX+","+currY+"";
				String child = 	""+(currX)+","+(currY+1)+"";	
				myMap.put(child, parent);
				pathCost[currX][currY+1] = pathCost[currX][currY]+1;
				myStack.push(upChild);
			}
			if(currX-1>=0 && canTravel[currX-1][currY]==0){
				Pair<Integer, Integer> leftChild = new Pair(currX-1, currY);
				String parent = ""+currX+","+currY+"";
				String child = 	""+(currX-1)+","+currY+"";	
				myMap.put(child, parent);
				pathCost[currX-1][currY] = pathCost[currX][currY]+1;
				myStack.push(leftChild);
			}
			if(currY-1>=0 && canTravel[currX][currY-1]==0){
				Pair<Integer, Integer> downChild = new Pair(currX, currY-1);
				String parent = ""+currX+","+currY+"";
				String child = 	""+(currX)+","+(currY-1)+"";	
				myMap.put(child, parent);
				pathCost[currX][currY-1] = pathCost[currX][currY]+1;
				myStack.push(downChild);
			}
				
			return myStack.size();	
		
	}
	
	/* findGoal: check if we find the goal */
	
	/* BFS Main function: */
	public static ArrayList<String> DFS(Maze myMaze, ArrayList<Integer> counter, ArrayList<Pair<Integer, Integer>> reachedGoals){
		ArrayList<String> path = new ArrayList<String>();
		int mazeWidth = myMaze.maze.length;
		int mazeHeight = myMaze.maze[0].length;	
		
		Stack<Pair<Integer, Integer>> myStack = new Stack<Pair<Integer, Integer>>(); 
		int[][] canTravel = new int[mazeWidth][mazeHeight];
		int[][] pathCost = new int[mazeWidth][mazeHeight];
		Map<String, String> myMap = new HashMap<String, String>();
		
		// initialization queue, push the start point into queue, initial canTravel:
		Pair<Integer, Integer> curr = new Pair(myMaze.start[0], myMaze.start[1]);
		for(int i=0; i<mazeWidth; i++){
			for(int j=0; j<mazeHeight; j++){
				if(myMaze.maze[i][j] == 1)
					canTravel[i][j] = 1;
				else
					canTravel[i][j] = 0;
			}
		}
		for(int i=0; i<mazeWidth; i++){
			for(int j=0; j<mazeHeight; j++){
				pathCost[i][j] = Integer.MAX_VALUE; 
			}
		}
		pathCost[curr.getFirst()][curr.getSecond()] = 0;
		myStack.push( curr );
		while(myStack.size() != 0){
			// pop one element from queue, mark it visited
			Pair checkCurr = myStack.pop();
			int currX = (int) checkCurr.getFirst();
			int currY = (int) checkCurr.getSecond();			
			canTravel[currX][currY] = 1;
			Integer nVisited = counter.get(0);
			nVisited++;
			counter.set(0, nVisited);
			// check if we reach the goal(s)
			
			Iterator<Pair<Integer, Integer>> goalsIterator = myMaze.goals.iterator();
			boolean found = false;
			while (goalsIterator.hasNext()) {
	            Pair<Integer, Integer> g = goalsIterator.next();
	            int goalX = g.getFirst();
				int goalY = g.getSecond();
				if(currX == goalX && currY == goalY ){
					reachedGoals.add(new Pair<Integer, Integer>(goalX, goalY));
					myMaze.start[0] = g.getFirst();
					myMaze.start[1] = g.getSecond();
					goalsIterator.remove();
					found = true;
					break;
				}
		    }
			// if so terminate
			if(found){				
				break;			
			}
			// if not push unvisited adjacents into queue, update dictionary, so we can find our path when we reach the goal:
			else{
				int currExpand = pushAdjacent(myStack, canTravel, checkCurr, myMap, pathCost);
				Integer maxExpand = counter.get(1);
				if( maxExpand < currExpand){
					maxExpand = currExpand;
					counter.set(1, maxExpand);
				}
			}
		}
		
		counter.set(2, findMaxDepth(pathCost));
		// we are out of the loop, now report the path we found
			// initialize initial key: the 
		String currKey = ""+myMaze.start[0]+"," + myMaze.start[1]+"";
		path.add(currKey);
		while(myMap.containsKey(currKey)){
			currKey = myMap.get(currKey);
			path.add(currKey);
		}
		return path;
	}

	
	/* Find the maximal tree depth */
	public static int findMaxDepth(int[][] maze){
		int max = Integer.MIN_VALUE;
		for(int i=0; i<maze.length; i++){
			for(int j=0; j<maze[0].length; j++){
				if(maze[i][j]<Integer.MAX_VALUE && max<maze[i][j])
					max = maze[i][j];
			}
		}
		return max;
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		out.println("Please enter the maze you would like to run:");
		String input = "src/MazeReadIn/trickySearch";//console().readLine();
		String output = input+"Solution";
		Maze myMaze = ReadMaze.parseMaze(input); // className.methodName
		ArrayList<String> result = new ArrayList<String>();
		boolean firstLoop = true;
		ArrayList<Integer> counter = new ArrayList<Integer>();
		counter.add(new Integer(0));
		counter.add(new Integer(0));
		counter.add(new Integer(-1));
		Integer maxDepth = -1;
		ArrayList<Pair<Integer, Integer>> reachedGoals = new ArrayList<Pair<Integer, Integer>>();
		
		while(myMaze.goals.size()>0){
			
			ArrayList<String> partialResult = DFS(myMaze, counter, reachedGoals);
			if(maxDepth < counter.get(2))
			{
				maxDepth = counter.get(2);
			}
			if(firstLoop){
				partialResult.addAll(result);
				firstLoop = false;
			}else
			{
				partialResult.addAll(result.subList(1, result.size()-1));
			}
			result = partialResult;
		}
		
		for(int i= result.size() - 1; i >= 0 ; i--){			
			out.println(result.get(i));
		}
		out.println("PATH LEN:" + (result.size() - 1));
		out.println("MAX TREE DEPTH:"+ maxDepth);
		out.println("VISITED:"+ counter.get(0));
		out.println("FRONTIER COUNT:"+ counter.get(1));
		
		//WriteMaze.writeSolution(input, result, output);
		WriteMaze.writeSolution(input, result, output, reachedGoals);
	}

}
