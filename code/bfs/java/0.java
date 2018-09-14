package com.gotodeveloper.exercises.bfsdfs;

import java.util.LinkedList;
import java.util.List;

public class BFS {
    private List<Node> allNodes;

    private LinkedList<Node> queue = new LinkedList<Node>();

    public BFS(List<Node> allNodes) {
        this.allNodes = allNodes;
    }

    public void bfsTraversal(Node start) {

        queue.addLast(start);
        while (!queue.isEmpty()) {
            Node temp = queue.removeFirst();
            System.out.println(temp.data);
            if (temp.adjacentNodes != null) {
                for (Node x : temp.adjacentNodes) {
                    queue.addLast(x);
                }
            }
        }
    }

}
