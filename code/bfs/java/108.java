import java.util.ArrayList;

/**
 * Breadth First Search Algorithm extends The Solver Abstract Class
 * @author 18998712
 */
public class BFS extends Solver {

  /**
   * Search Node Nested Class
   * @author Bhekimpilo Ndhlela @ 18998712
   */
  private class SearchNode {
    private Grid board;
    private int moves;
    private SearchNode previous;

    public SearchNode(Grid b, int moves, SearchNode previous) {
      this.board = b;
      this.moves = moves;
      this.previous = previous;
    }
  }

  /**
   * Find the solution of the initial board using the BFS algorithm.
   * @param initial		The Board to be solved
   */
  public BFS(Grid initial) {
    Queue<SearchNode> queue = new Queue<SearchNode>();
    ArrayList<Grid> explored = new ArrayList<Grid>();

    queue.enqueue(new SearchNode(initial, 0, null));
    SearchNode sn = null;
    while (!queue.isEmpty()) {
      sn = queue.dequeue();
      if (explored.contains(sn.board)) continue;
      if (sn.board.isGoal()) break;
      explored.add(sn.board);
      expNodes++;
      for (Grid b: sn.board.neighbors()) {
        if (!explored.contains(b))
          queue.enqueue(new SearchNode(b, sn.moves + 1, sn));
        }
      }
      if(queue.isEmpty()) {
        solvable = false;
        return;
      }
      SearchNode prev = sn;
      movements = new Stack<Action>();
      while (prev != null) {
        movements.push(prev.board.getAction());
        moves++;
        prev = prev.previous;
      }
      solvable = true;
    }

  /*
   * (non-Javadoc)
   * @see Solver#isSolvable()
   */
  public boolean isSolvable() {
    return solvable;
  }

  /*
   * (non-Javadoc)
   * @see Solver#expandedNodes()
   */
  public int expandedNodes() {
    return expNodes;
  }

  /*
   * (non-Javadoc)
   * @see Solver#moves()
   */
  public int moves() {
    return moves;
  }

  /*
   * (non-Javadoc)
   * @see Solver#solution()
   */
  public Iterable<Action> solution() {
    return (!solvable) ? null : movements;
  }
}
