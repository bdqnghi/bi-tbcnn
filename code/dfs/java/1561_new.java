import junit.framework.TestCase;

public class DFSTest extends TestCase {

	private Graph emptyGraph;
	private Graph edgelessGraph;
	private Graph treeGraph;
	private Graph cycleGraph;

	protected void setUp() throws Exception {
		super.setUp();
		emptyGraph = new GraphImpl();

		edgelessGraph = new GraphImpl();
		edgelessGraph.addNode("a");
		edgelessGraph.addNode("b");
		edgelessGraph.addNode("c");

		treeGraph = new GraphImpl();
		treeGraph.addEdge("a", "b");
		treeGraph.addEdge("a", "c");
		treeGraph.addEdge("b", "d");
		treeGraph.addEdge("b", "e");

		cycleGraph = new GraphImpl();
		cycleGraph.addEdge("a", "b");
		cycleGraph.addEdge("b", "c");
		cycleGraph.addEdge("c", "d");
		cycleGraph.addEdge("d", "a");
	}

	protected void tearDown() throws Exception {
		super.tearDown();
		emptyGraph = null;
		edgelessGraph = null;
		treeGraph = null;
		cycleGraph = null;
	}

	public void testGetVisited() {
		{
			DFS emptyDFS = new DFS(emptyGraph);
			emptyDFS.dfs(new Object());
			assertTrue(emptyDFS.getVisited().isEmpty());
		}

		{
			DFS edgelessDFS = new DFS(edgelessGraph);
			edgelessDFS.dfs("a");
			assertEquals(edgelessDFS.getVisited().size(), 1);
			assertTrue(edgelessDFS.getVisited().contains("a"));

			NaiveSet previsited = new NaiveSet();
			previsited.add("b");
			edgelessDFS = new DFS(edgelessGraph, previsited);
			edgelessDFS.dfs("b");
			assertEquals(edgelessDFS.getVisited().size(), 1);
			assertTrue(edgelessDFS.getVisited().contains("b"));
		}

		{
			DFS treeDFS = new DFS(treeGraph);
			treeDFS.dfs("b");
			assertEquals(treeDFS.getVisited().size(), 3);
			assertTrue(treeDFS.getVisited().contains("b"));
			assertTrue(treeDFS.getVisited().contains("d"));
			assertTrue(treeDFS.getVisited().contains("e"));

			treeDFS.dfs("a");
			assertEquals(treeDFS.getVisited().size(), 5);
			assertTrue(treeDFS.getVisited().contains("a"));
			assertTrue(treeDFS.getVisited().contains("b"));
			assertTrue(treeDFS.getVisited().contains("c"));
			assertTrue(treeDFS.getVisited().contains("d"));
			assertTrue(treeDFS.getVisited().contains("e"));

			NaiveSet previsited = new NaiveSet();
			previsited.add("b");
			treeDFS = new DFS(treeGraph, previsited);
			treeDFS.dfs("a");
			assertEquals(treeDFS.getVisited().size(), 3);
			assertTrue(treeDFS.getVisited().contains("a"));
			assertTrue(treeDFS.getVisited().contains("b"));
			assertTrue(treeDFS.getVisited().contains("c"));
		}

		{
			DFS cycleDFS = new DFS(cycleGraph);
			cycleDFS.dfs("c");
			assertEquals(cycleDFS.getVisited().size(), 4);
			assertTrue(cycleDFS.getVisited().contains("c"));
			assertTrue(cycleDFS.getVisited().contains("d"));
			assertTrue(cycleDFS.getVisited().contains("a"));
			assertTrue(cycleDFS.getVisited().contains("b"));

			cycleDFS.dfs("a");
			assertEquals(cycleDFS.getVisited().size(), 4);
			assertTrue(cycleDFS.getVisited().contains("c"));
			assertTrue(cycleDFS.getVisited().contains("d"));
			assertTrue(cycleDFS.getVisited().contains("a"));
			assertTrue(cycleDFS.getVisited().contains("b"));

			NaiveSet previsited = new NaiveSet();
			previsited.add("c");
			cycleDFS = new DFS(cycleGraph, previsited);
			cycleDFS.dfs("a");
			assertEquals(cycleDFS.getVisited().size(), 3);
			assertTrue(cycleDFS.getVisited().contains("a"));
			assertTrue(cycleDFS.getVisited().contains("b"));
			assertTrue(cycleDFS.getVisited().contains("c"));
		}
	}

	public void testGetFinished() {
		{
			DFS emptyDFS = new DFS(emptyGraph);
			emptyDFS.dfs(new Object());
			assertEquals(emptyDFS.getFinished().size(), 0);
		}

		{
			DFS edgelessDFS = new DFS(edgelessGraph);
			edgelessDFS.dfs("a");
			assertEquals(edgelessDFS.getFinished().size(), 1);
			assertEquals(edgelessDFS.getFinished().elementAt(0), "a");

			NaiveSet previsited = new NaiveSet();
			previsited.add("b");
			edgelessDFS = new DFS(edgelessGraph, previsited);
			edgelessDFS.dfs("b");
			assertEquals(edgelessDFS.getFinished().size(), 0);
		}

		{
			DFS treeDFS = new DFS(treeGraph);
			treeDFS.dfs("b");
			assertEquals(treeDFS.getFinished().size(), 3);
			assertEquals(treeDFS.getFinished().elementAt(0), "d");
			assertEquals(treeDFS.getFinished().elementAt(1), "e");
			assertEquals(treeDFS.getFinished().elementAt(2), "b");

			treeDFS.dfs("a");
			assertEquals(treeDFS.getFinished().size(), 5);
			assertEquals(treeDFS.getFinished().elementAt(0), "d");
			assertEquals(treeDFS.getFinished().elementAt(1), "e");
			assertEquals(treeDFS.getFinished().elementAt(2), "b");
			assertEquals(treeDFS.getFinished().elementAt(3), "c");
			assertEquals(treeDFS.getFinished().elementAt(4), "a");

			NaiveSet previsited = new NaiveSet();
			previsited.add("b");
			treeDFS = new DFS(treeGraph, previsited);
			treeDFS.dfs("a");
			assertEquals(treeDFS.getFinished().size(), 2);
			assertEquals(treeDFS.getFinished().elementAt(0), "c");
			assertEquals(treeDFS.getFinished().elementAt(1), "a");
		}

		{
			DFS cycleDFS = new DFS(cycleGraph);
			cycleDFS.dfs("c");
			assertEquals(cycleDFS.getFinished().size(), 4);
			assertEquals(cycleDFS.getFinished().elementAt(0), "b");
			assertEquals(cycleDFS.getFinished().elementAt(1), "a");
			assertEquals(cycleDFS.getFinished().elementAt(2), "d");
			assertEquals(cycleDFS.getFinished().elementAt(3), "c");

			cycleDFS.dfs("a");
			assertEquals(cycleDFS.getFinished().size(), 4);
			assertEquals(cycleDFS.getFinished().elementAt(0), "b");
			assertEquals(cycleDFS.getFinished().elementAt(1), "a");
			assertEquals(cycleDFS.getFinished().elementAt(2), "d");
			assertEquals(cycleDFS.getFinished().elementAt(3), "c");

			NaiveSet previsited = new NaiveSet();
			previsited.add("c");
			cycleDFS = new DFS(cycleGraph, previsited);
			cycleDFS.dfs("a");
			assertEquals(cycleDFS.getFinished().size(), 2);
			assertEquals(cycleDFS.getFinished().elementAt(0), "b");
			assertEquals(cycleDFS.getFinished().elementAt(1), "a");
		}
	}

	public void testGetReverseFinished() {
		{
			DFS emptyDFS = new DFS(emptyGraph);
			emptyDFS.dfs(new Object());
			assertEquals(emptyDFS.getReverseFinished().size(), 0);
		}

		{
			DFS edgelessDFS = new DFS(edgelessGraph);
			edgelessDFS.dfs("a");
			assertEquals(edgelessDFS.getReverseFinished().size(), 1);
			assertEquals(edgelessDFS.getReverseFinished().elementAt(0), "a");

			NaiveSet previsited = new NaiveSet();
			previsited.add("b");
			edgelessDFS = new DFS(edgelessGraph, previsited);
			edgelessDFS.dfs("b");
			assertEquals(edgelessDFS.getReverseFinished().size(), 0);
		}

		{
			DFS treeDFS = new DFS(treeGraph);
			treeDFS.dfs("b");
			assertEquals(treeDFS.getReverseFinished().size(), 3);
			assertEquals(treeDFS.getReverseFinished().elementAt(2), "d");
			assertEquals(treeDFS.getReverseFinished().elementAt(1), "e");
			assertEquals(treeDFS.getReverseFinished().elementAt(0), "b");

			treeDFS.dfs("a");
			assertEquals(treeDFS.getReverseFinished().size(), 5);
			assertEquals(treeDFS.getReverseFinished().elementAt(4), "d");
			assertEquals(treeDFS.getReverseFinished().elementAt(3), "e");
			assertEquals(treeDFS.getReverseFinished().elementAt(2), "b");
			assertEquals(treeDFS.getReverseFinished().elementAt(1), "c");
			assertEquals(treeDFS.getReverseFinished().elementAt(0), "a");

			NaiveSet previsited = new NaiveSet();
			previsited.add("b");
			treeDFS = new DFS(treeGraph, previsited);
			treeDFS.dfs("a");
			assertEquals(treeDFS.getReverseFinished().size(), 2);
			assertEquals(treeDFS.getReverseFinished().elementAt(1), "c");
			assertEquals(treeDFS.getReverseFinished().elementAt(0), "a");
		}

		{
			DFS cycleDFS = new DFS(cycleGraph);
			cycleDFS.dfs("c");
			assertEquals(cycleDFS.getReverseFinished().size(), 4);
			assertEquals(cycleDFS.getReverseFinished().elementAt(3), "b");
			assertEquals(cycleDFS.getReverseFinished().elementAt(2), "a");
			assertEquals(cycleDFS.getReverseFinished().elementAt(1), "d");
			assertEquals(cycleDFS.getReverseFinished().elementAt(0), "c");

			cycleDFS.dfs("a");
			assertEquals(cycleDFS.getReverseFinished().size(), 4);
			assertEquals(cycleDFS.getReverseFinished().elementAt(3), "b");
			assertEquals(cycleDFS.getReverseFinished().elementAt(2), "a");
			assertEquals(cycleDFS.getReverseFinished().elementAt(1), "d");
			assertEquals(cycleDFS.getReverseFinished().elementAt(0), "c");

			NaiveSet previsited = new NaiveSet();
			previsited.add("c");
			cycleDFS = new DFS(cycleGraph, previsited);
			cycleDFS.dfs("a");
			assertEquals(cycleDFS.getReverseFinished().size(), 2);
			assertEquals(cycleDFS.getReverseFinished().elementAt(1), "b");
			assertEquals(cycleDFS.getReverseFinished().elementAt(0), "a");
		}
	}
}
