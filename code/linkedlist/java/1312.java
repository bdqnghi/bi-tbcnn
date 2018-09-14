
public class linkedlist {
	Node head;
	class Node{
		int data;
		Node next;
		public Node(int i) {
			data=i;
			next=null;
		}
	}
	public void push(int i) {
		if(head==null) {
			Node new_node=new Node(i);
			head=new_node;
		}
		else {
			Node temp=head;
			Node new_node=new Node(i);
			head=new_node;
			new_node.next=temp;
		}
	}
	public int pop() {
		if(head==null) return -1;
		else {
			Node temp=head;
			head=temp.next;
			return temp.data;
		}
	}
	public boolean isEmpty(linkedlist d) {
		if(head==null)return true;
		else return false;
	}
}
