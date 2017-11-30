package decreaseAndConquer.graphTraversals;

public class BFS {
	
	private static int[][] adjMatrix1 = {{ 99 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ,
						 				{ 1 , 0 , 1 , 1 , 1 , 1 , 0 , 0 } ,
						 				{ 2 , 1 , 0 , 0 , 0 , 0 , 1 , 0 } ,
						 				{ 3 , 1 , 0 , 0 , 0 , 0 , 0 , 1 } ,
						 				{ 4 , 1 , 0 , 0 , 0 , 0 , 1 , 0 } ,
						 				{ 5 , 1 , 0 , 0 , 0 , 0 , 0 , 1 } ,
						 				{ 6 , 0 , 1 , 0 , 1 , 0 , 0 , 0 } ,
						 				{ 7 , 0 , 0 , 1 , 0 , 1 , 0 , 0 }
										};
	
	private static int[][] adjMatrix2 = {{ 99 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9  } ,
										 { 1 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 } ,
										 { 2 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 } ,
										 { 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 } ,
										 { 4 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 } ,
										 { 5 , 0  ,0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 } ,
										 { 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
										 { 7 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 } ,
										 { 8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
										 { 9 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
										 
		};
	
	private static void traverseBF ( int[][] adjMatrix , Queue q , int[] nodesVisited , int[][] bfsTree ) {
		while ( q.getFrontEnd() <= q.getRearEnd() ) {
			
			int ver = q.remove();
			
			for ( int i = 1 ; i < adjMatrix[ver].length ; i++ ) {
			if ( ( adjMatrix[ver][i] != 0 ) && ( nodesVisited[i] != 1 ) ) {
				bfsTree[ver][i] = 1 ;
				bfsTree[i][ver] = 1 ;
				System.out.println(ver + " - " + i);
				q.add(i);
				nodesVisited[i] = 1 ;
			}
			}			
			
		}
	}
	
	
	private static void bfs( int[][] adjMatrix ) {
		
		Queue q = new Queue();
		
		int[] nodesVisited = new int[adjMatrix.length];
		
		int[][] bfsTree = new int[adjMatrix.length][adjMatrix[0].length];
		
		for ( int i = 1 ; i < bfsTree.length ; i++ ) {
			bfsTree[0][i] = i ;
			bfsTree[i][0] = i ;
		}
		q.add(1);
		nodesVisited[1] = 1 ;
		
		traverseBF( adjMatrix , q , nodesVisited , bfsTree );

		boolean done = false ;
		
		while ( !done ) {
			done = true ;
			for ( int i = 1 ; i < nodesVisited.length ; i++ ) {
				if ( nodesVisited[i] == 0 ) {
					done = false ;
					q.add(i);
					nodesVisited[i] = 1 ;
				
					traverseBF( adjMatrix , q , nodesVisited , bfsTree );
				}
			}
		}
		
		System.out.println("Adjacency Matrix for BFS : ");
		for ( int i = 0 ; i < bfsTree.length ; i++ ) {
			for ( int j = 0 ; j < bfsTree[i].length ; j++ ) {
				System.out.print(bfsTree[i][j] + "\t");
			}
			System.out.println();
		}
		
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		bfs(adjMatrix1);
		bfs(adjMatrix2);
	}

}

// =======================================Q=U=E=U=E=================================//

class Queue {
	private int[] queue = new int[10] ;
	
	private int frontEnd = 0 ;
	private int rearEnd = -1 ;
	
	public int getFrontEnd() {
		return frontEnd;
	}

//	public void setFrontEnd(int frontEnd) {
//		this.frontEnd = frontEnd;
//	}

	public int getRearEnd() {
		return rearEnd;
	}

//	public void setRearEnd(int rearEnd) {
//		this.rearEnd = rearEnd;
//	}
	
	public void add ( int item ) {
		if ( rearEnd < 9 ) {
		rearEnd++ ;
		queue[rearEnd] = item ;
		
		}
		else {
			System.out.println("Queue full.\n");
		}
	}

	public int remove ( ) {
		if ( ( frontEnd  < 0 ) || ( frontEnd > rearEnd ) ) {
			System.out.println("Queue empty.");
			return -1 ;
		}
		else {
		int item = queue[frontEnd] ;
		queue[frontEnd] = 0 ;
		frontEnd++;
		return item ;
		}
	}
	
	public void displayQueue () {
		System.out.println("Queue Contents : ");
		for ( int i = frontEnd ; i <= rearEnd ; i++ ) {
			System.out.print(queue[i] + "\t");
		}
		System.out.println("\nfrontEnd : " + frontEnd);
		System.out.println("rearEnd : " + rearEnd);
		
	}
}