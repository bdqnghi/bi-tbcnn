package FortinetHackerRank;

public class Linkedlist {

	Node head;
	
	// Logic for reverse Linked list
	Node reverseList(Node head) {
		
		if(head == null)
			return null;
		if(head.next == null)
			return head;
		
		Node newPrev = head.next;
		
		head.next = null;
		
		Node newHead = reverseList(newPrev);
		
		newPrev.next = head;
		
		return newHead;
	}

}

class Node {

	int data;
	Node next;

	// Creating constructor for adding Node in Linkedlist
	Node(int data) {
		this.data = data;
	}

}
