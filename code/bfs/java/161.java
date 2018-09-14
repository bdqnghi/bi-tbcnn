package FordFulkerson;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BFS {

	private static BufferedReader r;
	private static HashMap<String, HashMap<String, Nodes>> InputGraph,
			LevelGraph;
	private static HashMap<String, Nodes> ConnectedEdges, BfsNodes,
			ShortestPath;
	private static Scanner s;
	private static int level = 0;
	static boolean visited[];
	static long startTime,endTime;
	
	public static void main(String[] args) throws IOException {

		String nline = "";
		int NodeNumber = 0, DestLevel = 0;
		//System.out.print("Enter src n dest");
		Scanner s = new Scanner(System.in);
		String source =args[2];
		String destination =args[3];
		startTime = System.currentTimeMillis();
		r = new BufferedReader(new FileReader(args[1]));
		InputGraph = new HashMap<String, HashMap<String, Nodes>>();

		while ((nline = r.readLine()) != null) {
			ConnectedEdges = new HashMap<String, Nodes>();
			StringTokenizer st = new StringTokenizer(nline, " ");
			while (st.hasMoreTokens()) {

				String name = st.nextToken();
				int capacity = Integer.parseInt(st.nextToken());
				ConnectedEdges.put(name, new Nodes(name, capacity));
			}

			InputGraph.put(Integer.toString(NodeNumber++), ConnectedEdges);
		}
		setBFS(InputGraph);
		
		;
				BfsNodes = doBfs(new Nodes(source),InputGraph);
			for (String p : LevelGraph.keySet()) {
			HashMap<String, Nodes> temp = LevelGraph.get(p);
			Iterator<String> pt1 = temp.keySet().iterator();
			while (pt1.hasNext()) {
				Nodes t1 = (Nodes) temp.get(pt1.next());
			}
		}

		ShortestPath = new HashMap<String, Nodes>();
		
		  
		 Nodes dest = null;
		Iterator<String> it = BfsNodes.keySet().iterator();
		ArrayList<String> path = new ArrayList<String>(BfsNodes.keySet());
		while (it.hasNext()) {
			Nodes node = (Nodes) BfsNodes.get(it.next());
			if (node.getName().equals(destination)) {
				DestLevel = node.getLevel();
				dest = node;

				break;
			} else
				DestLevel = -1;
		}
		ShortestPath.put(dest.getName(), dest);
		Iterator<String> it1 = BfsNodes.keySet().iterator();
		for (int i = path.size() - 2; i >= 0; i--) {
			
			Nodes n1 = (Nodes) BfsNodes.get(path.get(i));
			if (n1.getLevel() == (DestLevel - 1) && Connected(n1, dest)) {
				ShortestPath.put(n1.getName(), n1);
				dest = n1;
				DestLevel = n1.getLevel();
			}
		}

		System.out.println("Shortest Path from Source to Dest is: ");
		Iterator<String> sti = ShortestPath.keySet().iterator();
		while (sti.hasNext()) {
			System.out.print(ShortestPath.get(sti.next()).getName() + "---");
		}
		endTime = System.currentTimeMillis();

		System.out.println("\nThe time of execution of BFS is "
				+ (endTime - startTime) + " millisecs");

	}

	public static void setBFS(HashMap<String, HashMap<String, Nodes>> Input) {
		visited = new boolean[Input.keySet().size()];
		for (int i = 0; i < Input.keySet().size(); i++)
			visited[i] = false;

	}

	private static boolean Connected(Nodes n1, Nodes dest) {
		// TODO Auto-generated method stub
		HashMap<String, Nodes> CheckList = LevelGraph.get(n1.getName());
		Iterator<String> it = CheckList.keySet().iterator();
		while (it.hasNext()) {
			Nodes test = (Nodes) CheckList.get(it.next());
			if (test.getName().equals(dest.getName())) {
				return true;
			}
		}
		return false;
	}

	public static HashMap<String, Nodes> doBfs(Nodes source,HashMap<String, HashMap<String, Nodes>> InputGraph) {
		// TODO Auto-generated method stub

		LinkedList<Nodes> Queue = new LinkedList<Nodes>();
		HashMap<String, Nodes> levelNodes;
		HashMap<String, Nodes> TraversalPath = new HashMap<String, Nodes>();
		LevelGraph = new HashMap<String, HashMap<String, Nodes>>();
		source.setLevel(level);
		visited[Integer.parseInt(source.getName())] = true;
		Queue.addFirst(source);
		TraversalPath.put(source.getName(), source);
		level++;
		while (!Queue.isEmpty()) {

			Nodes head = Queue.remove();
			HashMap<String, Nodes> ConnectedNodes = InputGraph.get(head
					.getName());
			levelNodes = new HashMap<String, Nodes>();
			level = head.getLevel() + 1;
			Iterator<String> it = ConnectedNodes.keySet().iterator();
			while (it.hasNext()) {
				Nodes n1 = (Nodes) ConnectedNodes.get(it.next());
				if ((visited[Integer.parseInt(n1.getName())] != true)
						&& n1.getCapacity() > 0) {
					n1.setLevel(level);
					visited[Integer.parseInt(n1.getName())] = true;
					n1.setVisited(true);
					Queue.add(n1);
					levelNodes.put(n1.getName(), n1);
					TraversalPath.put(n1.getName(), n1);

				}
			}
			LevelGraph.put(head.getName(), levelNodes);
		}
		return TraversalPath;
	}

}
