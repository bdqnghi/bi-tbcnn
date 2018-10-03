
public class DFS {
	public static void main(String[] args){
		Tree tree = new Tree();
		tree.insert(2);
		tree.insert(3);
		tree.insert(1);
		tree.insert(5);
		tree.insert(0);
		DFS(tree.root);
		
	}
	
	public static void  DFS(Node root){
		Node temp = root;
		if(!visitedOrNot(temp)){
			if(temp != null)
				System.out.println(temp.data);
			return;
		}
		else{
			System.out.println(temp.data);
			temp.visited = 1;
			DFS(temp.leftChild);
			DFS(temp.rightChild);
		}
		
	}
	public static boolean visitedOrNot(Node node){
		if(node == null)
			return false;
		if(node.leftChild != null && node.rightChild != null){
			if(node.leftChild.visited == 0 && node.leftChild.visited == 0)
				return true;
			else
				return false;
		}
		else if(node.leftChild != null && node.rightChild == null){
			if(node.leftChild.visited == 0)
				return true;
			else
				return false;
		}
		else if(node.rightChild != null && node.leftChild == null){
			if(node.rightChild.visited == 0)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

class Node{
	Node leftChild;
	Node rightChild;
	int visited;
	int data;
	public Node(int d){
		this.data = d;
		this.visited = 0;
	}
}

class Tree{
	Node root;
	Node focusNode;
	Node parentNode;
	
	public void insert(int data){
		if(root == null){
			root = new Node(data);
			return;
		}
		else{
			focusNode = root;
			while(focusNode != null){
				if(focusNode.data > data){
					parentNode = focusNode;
					focusNode = focusNode.leftChild;
					if(focusNode == null){
						parentNode.leftChild = new Node(data);
						return;
					}
				}
				else{
					parentNode = focusNode;
					focusNode = focusNode.rightChild;
					if(focusNode == null){
						parentNode.rightChild = new Node(data);
						return;
					}
				}
			}
		}
	}
}
