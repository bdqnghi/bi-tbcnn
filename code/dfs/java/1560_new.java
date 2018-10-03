
public class DfsMain {

	public static void main(String[] args) {
		Depth dfs = new Depth();
		dfs.addVertex('a');
		dfs.addVertex('b');
		dfs.addVertex('c');
		dfs.addVertex('d');
		dfs.addVertex('e');
		dfs.addVertex('f');
		dfs.addVertex('g');
		//dfs.addVertex('h');
		
		dfs.addEdge(0, 1);
		dfs.addEdge(0, 2);
		dfs.addEdge(0, 3);
		dfs.addEdge(0, 4);
		dfs.addEdge(1, 3);
		dfs.addEdge(1, 4);
		dfs.addEdge(2, 6);
		dfs.addEdge(2, 5);
		dfs.addEdge(3, 4);
		dfs.addEdge(5, 6);
		
		dfs.dfs();
		
		dfs.count();

	}

}
