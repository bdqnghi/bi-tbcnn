package main.java.graph;

import main.java.graph.util.GraphNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by tyler on 1/2/17.
 */
public class DFS
{
    public void search(GraphNode start)
    {
        if(start==null)
            return;
        List<GraphNode> visited = new ArrayList<>();
        Stack<GraphNode> buffer = new Stack<>();

        buffer.push(start);
        visited.add(start);
        while(!buffer.isEmpty())
        {
            GraphNode top = buffer.pop();
            visited.add(top);
            for(GraphNode c : top.getChildren())
            {
                if(!visited.contains(c))
                {
                    buffer.push(c);
                }
            }
            System.out.println(top.getUniqueId());
        }
    }

    public static void main(String[] args)
    {
        GraphNode c = new GraphNode(3, new ArrayList<>());
        GraphNode x = new GraphNode(55, new ArrayList<>());
        List<GraphNode> dKids = new ArrayList<>();
        dKids.add(x);
        GraphNode d = new GraphNode(4, dKids);

        GraphNode e = new GraphNode(5, new ArrayList<>());
        GraphNode g = new GraphNode(7, new ArrayList<>());

        List<GraphNode> aKids = new ArrayList<>();
        List<GraphNode> bKids = new ArrayList<>();
        List<GraphNode> fKids = new ArrayList<>();

        fKids.add(g);
        GraphNode f = new GraphNode(6, fKids);
        bKids.add(d);
        bKids.add(e);
        bKids.add(f);

        GraphNode b = new GraphNode(2, bKids);
        aKids.add(b);
        aKids.add(c);
        aKids.add(d);
        GraphNode a = new GraphNode(1, aKids);
        bKids.add(a);
        DFS dfs = new DFS();
        dfs.search(a);
    }
}
