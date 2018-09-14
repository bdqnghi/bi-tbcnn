package fundamentals;

import java.util.*;

public class BFS {

    class Node {
        public State state;
        public ArrayList<Node> getAdjacentNodes() {
            return null;
        }
    }

    public static ArrayList<Node> getAllNodes() {
        return null;
    }

    enum State { unvisited, visited }

    public boolean BFS(Node root, Node n) {
        if (root == null) return false;
        if (root == n) return true;

        for(Node u : getAllNodes()) {
            u.state = State.unvisited;
        }

        java.util.Queue<Node> q = new LinkedList<Node>();
        q.add(n);
        root.state = State.visited;
        while(!q.isEmpty()) {
            Node cur = q.remove();
            for(Node v : cur.getAdjacentNodes()) {
                if(v.state == State.unvisited) {
                    if(v == n) {
                        return true;
                    }
                    else {
                        v.state = State.visited;
                        q.add(v);
                    }
                }
            }
            cur.state = State.visited;
        }

        return false;
    }


}
