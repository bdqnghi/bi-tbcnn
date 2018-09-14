
/* Maria L Martinez - mlmartinez85@gmail.com
 * CS 4311 - Week 8 Assignment
 * Winter 2015
 * 02/25/2015
 *
 * BFS.java
 * Breadth First Search implementation
 *
 * Output:
 * A
 * B C D
 * E F G H
 * I J K
 * L
 */

import java.sql.ResultSet;
import java.sql.SQLException;

public class BFS {
    
    public static void main(String[] args) {
        DataBase db = new DataBase("genDB");
        Queue q = new Queue();
		
		// set the root node to the given command line argument
		// set it's depth to 0 - the rest are incremented when added as a child
		BFSNode root = new BFSNode(args[0]);
		root.depth = 0;
		q.enqueue(root);
		int lastDepth = 0;
		
        while (!q.isEmpty()) { 	   
            BFSNode parent = (BFSNode) q.dequeue();
			
			// print a new line if we are on a new depth level
			if (lastDepth != parent.depth)
				System.out.print("\n");
			System.out.print(parent.letter + " ");
			
			// get the children of this node
			ResultSet rs = db.execute("select child from Letters where parent = '" + parent.letter + "'");
            try {
                while (rs.next()) {
                    BFSNode child = new BFSNode(rs.getString("CHILD"));
					child.depth = parent.depth + 1;
                    q.enqueue(child);
                }
				rs.close();
				// keep track of the last depth to properly display output
				lastDepth = parent.depth;                              
            } 
            catch (SQLException e) { System.out.println(e.getMessage()); }
        }
    }
    
}
