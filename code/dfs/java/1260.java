package chapter_four;

import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;


public class DFS
{
    public static class GraphNode<T extends Comparable<T>>
    {
        private T m_data;
        private GraphNode<T> m_left;
        private GraphNode<T> m_right;

        public T getData()
        {
            return m_data;
        }

        public GraphNode<T> getLeft()
        {
            return m_left;
        }

        public GraphNode<T> getRight()
        {
            return m_right;
        }

        public GraphNode(T data, GraphNode<T> left, GraphNode<T> right)
        {
            m_data = data;
            m_left = left;
            m_right = right;
        }

        public GraphNode(T data)
        {
            this(data, null, null);
        }

        public void setLeft(GraphNode<T> left)
        {
            m_left = left;
        }

        public void setRight(GraphNode<T> right)
        {
            m_right = right;
        }

        @Override
        public String toString()
        {
            return "" + m_data + ": [" + (m_left != null ? m_left.m_data : "") + ", " + (m_right != null ? m_right.m_data : "") + "]";
        }
    }

    /******************************** DEPTH FIRST SEARCH ****************************************/
    public static <T extends Comparable<T>> boolean pathExists(GraphNode<T> start, GraphNode<T> goal)
    {
        return dfs(start, goal);
    }

    /**
     * Depth first search - iterative implementation.
     * This implementation only confirms the existence of the path, and doesn't
     * calculate what the path is.
     *
     * @param start - where to start searching from
     * @param goal - node to be found
     * @param visited - a set of nodes already visited by the search
     * @return True if path between start and goal exists, False otherwise
     */
    private static <T extends Comparable<T>> boolean dfs(GraphNode<T> start, GraphNode<T> goal)
    {
        Queue<GraphNode<T>> fringe = new ArrayDeque<>();
        Set<GraphNode<T>> visited = new HashSet<>();

        fringe.add(start);
        while(!fringe.isEmpty())
        {
            GraphNode<T> node = fringe.poll();
            visited.add(node);
            if (node.getData().compareTo(goal.getData()) == 0)
            {
                return true;
            }
            else
            {
                if(node.getLeft() != null && !visited.contains(node.getLeft()))
                {
                    fringe.add(node.getLeft());
                }
                if(node.getRight() != null && !visited.contains(node.getRight()))
                {
                    fringe.add(node.getRight());
                }
            }
        }
        return false;
    }
    /********************************************************************************************/
}
