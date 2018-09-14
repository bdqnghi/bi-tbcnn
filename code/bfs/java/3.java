import java.util.List;


public class BFS {

	public static void main(String[] args) {

		Graph g = new Graph();
		boolean found = search(g.getRoot(), 151);
		System.out.println("Found: "+found);
	}
	
	public static boolean search(Node root, int value){
		
		if(root.getValue() == value){
			return true;
		}else{
			List<Node> nodes = root.getChildren();
			int i=0;
			while(i < nodes.size()){
				if(nodes.get(i).getValue() == value){
					return true;
				}else{
					List<Node> children = nodes.get(i).getChildren();
					if(children != null){
						nodes.addAll(children);
					}
				}
				i++;
			}
			return false;
		}

	}

}
