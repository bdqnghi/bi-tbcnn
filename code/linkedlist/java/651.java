//Linked List implementation
class node{
	int value;
	node next;	
}
public class linkedlist {
	//Find the last node of the linked list using Recursion
	public static node last_node_find(node node1){
		if(node1.next ==null){
			return node1;
		}
		else{
			return last_node_find(node1.next);
		}
	}
	//Add a new node to the end of linked list
	public static void add_node_last(node root_node,int number){		
		node last_node = last_node_find(root_node);
		node new_node = new node();
		last_node.next = new_node;
		new_node.value = number;
	}
	//Add a new node to the first of the linked list
	public static node add_node_first(node root_node,int number){
		node node1 = new node();
		node1.next = root_node;
		node1.value = number;
		return node1;
	}
	//Calculate number of nodes in the linked list
	public static int number_of_nodes_count(node root_node){
		int node_count = 0;
		node node1 = root_node;
		while(node1 != null){
			node_count = node_count + 1;
			node1 = node1.next;
		}
		return node_count;
	}
	//Print the linked list
	public static void print_linked_list(node root_node){
		node node1 = root_node;
		while(node1 != null){
			System.out.println(node1.value);
			node1 = node1.next;
		}
	}
	//Add new node at "place" position in the linked list
	public static node add_node(node root_node,int place, int number){
		int number_of_nodes = number_of_nodes_count(root_node);
		if(place>number_of_nodes){
			return null;
		}
		node new_root_node = new node();
		if(place==1){
			new_root_node.value = number;
			new_root_node.next = root_node;
		}
		else{
			node node1 = root_node;
			node node2 = root_node;
			for(int i=1;i<place;i++){
				node1 = node2;
				node2 = node2.next;
			}
			node new_node = new node();
			node1.next = new_node;
			new_node.value = number;
			new_node.next = node2;	
			new_root_node = root_node;
		}
		return new_root_node;
		
	}
	//Delete a node
	public static node delete_node(node root_node,int place){
		int number_of_nodes = number_of_nodes_count(root_node);
		if(place>number_of_nodes){
			return null;
		}
		node new_root_node = root_node;
		node node1 = root_node;
		node node2 = root_node;
		node node3 = root_node;
		if(place ==1){
			new_root_node = root_node.next;
		}
		else{
			for(int i =0;i<place;i++){
				node1 = node2;
				node2 = node3;
				node3 = node3.next;
			}
			node1.next = node3;
		}
		return new_root_node;
	}
	//Initializing a simple Linked list
	public static void main(String[] args) {
		node root_node = new node();
		int number_of_nodes = 0;
		root_node.value = 11;
		//System.out.println(root_node.value);
		linkedlist.add_node_last(root_node,10);
		linkedlist.add_node_last(root_node,12);
		linkedlist.add_node_last(root_node,20);
		linkedlist.add_node_last(root_node,22);
		root_node = linkedlist.add_node_first(root_node,30);
		number_of_nodes = linkedlist.number_of_nodes_count(root_node);
		root_node = linkedlist.add_node(root_node,4,40);
		//linkedlist.print_linked_list(root_node);
		//Result = 30,11,10,40,12,20,22
		root_node = linkedlist.delete_node(root_node,2);
		linkedlist.print_linked_list(root_node);
		//Result = 30,10,40,12,20,22
		System.out.println("Number of nodes:");
		System.out.println(number_of_nodes);
		//Result = 6
	}

}
