/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package strategy;


import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author Maty
 * 
 * 1  procedure BFS(G,v):
 * 2      create a queue Q
 * 3      enqueue v onto Q
 * 4      mark v
 * 5      while Q is not empty:
 * 6          t ← Q.dequeue()
 * 7          if t is what we are looking for:
 * 8              return t
 * 9          for all edges e in G.adjacentEdges(t) do
 * 12             u ← G.adjacentVertex(t,e)
 * 13             if u is not marked:
 * 14                  mark u
 * 15                  enqueue u onto Q
 * 
 * 
 */
public class BFS implements IStrategy{
    
    @Override
    public boolean find(Tree tree, int i) {
        System.out.println("Breadth-First Search initiated. Looking for: " + i);
        return BFS(tree,i);
        //throw new UnsupportedOperationException("Not supported yet.");
    }
    
    private boolean BFS(Tree tree, int i){
        Queue<Node> queue = new LinkedList<>();
        Node v = tree.getRoot();
        queue.add(v);
        v.setState(1);
        while (!queue.isEmpty()){
            Node t = queue.poll();
            System.out.println("Examinating node with value: " + t.getData());
            if (t.getData() == i){
                System.out.println("Found node with data " + i + "! and with parent " + t.getParent().getData());
                System.out.println("Found!!");
                return true; // or other return
            }
            for (Node u : t.getChildren()){
                if(u.getState() == 0){
                    u.setState(1);
                    queue.add(u);
                }
            }
        }
        System.out.println("Not found!!");
        return false;

    }
    
}