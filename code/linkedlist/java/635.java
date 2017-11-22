
import java.util.LinkedList;
import java.util.Queue;



public class Linkedlist {
	
	public Node head;
	
	public Linkedlist () {
		this.head = null;
	}
	
	public void addNode(Node n) {
		if(this.head == null) {
			this.head = n;
		} else {
			Node current = head;
			while (current.next != null) {
				current = current.next;
			}	
			current.next = n;
		}
	}
	
	public void printList(Node head) {
		
		Node temp = head;
		if(temp == null) {
			System.out.println("List is empty.");
		} else {
			while (temp != null) {
				System.out.print(" " + temp.value);
				temp = temp.next;
			}
			System.out.println();
		}
	}
	
	public void printList2() {
		
		if (this.head == null) {
			System.out.println("List is empty.");
		} else {
			Node temp = this.head;
			while (temp != null) {
				System.out.print(" " + temp.value);
				temp = temp.next;
			}
			System.out.println();
		}
	}
	
	public Node reverseList() {
		
		Node previous = null;
		Node current;
		while (this.head != null) {
			current = this.head.next;
			this.head.next = previous;
			previous = this.head;
			this.head = current;		
		}
		this.head = previous;
		return this.head;
	}
	
	public Node reverseListRecursive(Node n) {
		
		if(n == null || n.next == null) {
			return n;
		}
		Node second = n.next;
		n.next = null;
		Node reverse = reverseListRecursive(second);
		second.next = n;
		return reverse;
	}
	
	public void printNode(Node n) {
		if(n == null) {
			return;
		}
		System.out.println(" " + n.value);
	}
	
	public void findMax() {
		
		if(this.head == null) {
			System.out.println("List is empty.");
			return;
		}
		Node max = this.head;
		Node current = this.head.next;
		while (current != null) {
			if(max.value < current.value) {
				max = current;
			}
			current = current.next;
		}
		printNode(max);
	}
	
	public void findMin() {
		
		if(this.head == null) {
			System.out.println("List is empty.");
			return;
		}
		Node min = this.head;
		Node current = this.head.next;
		while (current != null) {
			if(current.value < min.value) {
				min = current;
			}
			current = current.next;
		}
		printNode(min);
	}
	
	public Boolean isCircular(){
		
		Node slow = this.head;
		Node fast = this.head.next;
		while (true) {
			if(fast == null || fast.next == null) {
				return false;
			}
			if(fast == slow || fast.next == slow){
				return true;
			}
			slow = slow.next;
			fast = fast.next.next;
		}
	}
	
	public void deleteLastNode() {
		
		Node pre = null;
		Node current = this.head;
		if(this.head == null) {
			System.out.println("List is empty.");
			return;
		}
		//If one node, make head null
		if(this.head.next == null) {
			this.head = pre;	
		} else {
			while (current.next != null){
				pre = current;
				current = current.next;	
			}
			pre.next = null;
		}
	}
	
	public Node findMiddleNode() {
		
		Node slow = this.head;
		Node fast = this.head;
		while(true) {
			if(fast == null || fast.next == null) {
				return slow;
			}
			slow = slow.next;
			fast = fast.next.next;
		}
	}
	
	public void deleteMiddleNode() {
		
		Node middle = this.findMiddleNode();
		if (middle == null || middle.next == null) {
			return;
		}
		middle.value = middle.next.value;
		middle.next = middle.next.next;
		this.printList2();
	}
	
	
	public void combineLists(Linkedlist l2) {
		//If either lists are null, print as is.
		if(this.head == null) {
			l2.printList2();
			return;
		} else if (l2.head == null){
			this.printList2();
			return;
		} 
		//Add all nodes of l2 to a queue.
		Queue<Node> queue = new LinkedList<Node>();
		Node temp = l2.head;
		while(temp != null) {
			queue.add(temp);
			temp = temp.next;
		}
		Node current = this.head.next;
		Node pre = this.head;
		while(!queue.isEmpty() && current != null) {
			pre.next = queue.remove();
			pre = pre.next;
			pre.next = current;
			pre = current;
			current = current.next;
		}
		while (!queue.isEmpty()) {
			pre.next = queue.remove();
			pre = pre.next;
		}
		System.out.print("Combined lists - ");
		this.printList2();
	}
	
	public void combineLists2(Linkedlist l2) {
		//If either lists are null, print as is.
		if(this.head == null) {
			l2.printList2();
			return;
		} else if (l2.head == null){
			this.printList2();
			return;
		} 
		Node p1 = this.head;
		Node c1 = p1.next;
		Node p2 = l2.head;
		Node c2 = p2.next;
		
		while (c1 != null && c2 != null) {
			p1.next = p2;
			p2.next = c1;
			p1 = c1;
			c1 = c1.next;
			p2 = c2;
			c2 = c2.next;
		}
		if(c1 == null) {
			p1.next = p2;
		}
		if(c2 == null) {
			p1.next = p2;
			p2.next = c1;
		}
		System.out.print("Combined lists - ");
		this.printList2();
	}
	
	public int size() {
		if(this.head == null) {
			return 0;
		}
		int count = 1;
		Node temp = this.head;
		while (temp != null) {
			count++;
			temp = temp.next;
		}
		return count;
	}
	
	public void insertAtPosition (int n, Node node) {
		
		if(n > this.size() + 1 || n < 1){
			System.out.println("Illegal position.");
			return;
		}
		//Insert at last.
		if(n == this.size() + 1){
			this.addNode(node);
			return;
		}
		//Insert at first.
		if (n == 1){
			node.next = this.head;
			this.head = node;
			return;
		}
		//Insert in middle.
		Node temp = this.head;
		Node temp2 = this.head.next;
		int count = 1;
		while (count != n - 1) {
			temp = temp.next;
			temp2 = temp2.next;
			count++;
		}
		temp.next = node;
		node.next = temp2;	
	}
	
	
	public static void main(String[] args) {
		
		Linkedlist list = new Linkedlist();
		list.printList2();
		list.reverseList();
		//create and add nodes to list.
		for (int i = 1; i <= 5; i++) {
			Node n = new Node(i);
			list.addNode(n);
		}
		System.out.print("Original List --");
		list.printList2();
		System.out.print("Reverse iterative--");
		list.head = list.reverseList();
		list.printList2();
		System.out.print("Max in list--");
		list.findMax();
		System.out.print("Min in list--");
		list.findMin();
		
		System.out.print("Original List --");
		list.printList2();
		list.head = list.reverseListRecursive(list.head);
		System.out.print("Reverse recursive--");
	    list.printList2();
	    System.out.print("Max in list--");
	    list.findMax();
	    System.out.print("Min in list--");
	    list.findMin();
	    
	    if(list.isCircular()) {
	    	System.out.println("List is circular.");
	    } else {
	    	System.out.println("List is not circular.");
	    }
	    
	    Node middle = list.findMiddleNode();
	    
	    System.out.println("Middle node value = " + middle.value);
	    System.out.println("Deleting middle node in the list-- ");
	    list.printList2();
	    list.deleteMiddleNode();
	    
	    System.out.println("Deleting last node in the list--");
	    list.printList2();
	    list.deleteLastNode();
	    list.printList2();
	    
	    System.out.print("List 1 = ");
	    list.printList2();
	    Linkedlist l2 = new Linkedlist();
	  //create and add nodes to list.
	  	for (int i = 11; i <= 14; i++) {
	  		Node n = new Node(i);
	  		l2.addNode(n);
	  	}
	  	
	  	System.out.print("List 2 = ");
	  	l2.printList2();
	  	System.out.println("Combining lists 1 and 2--");
	    list.combineLists(l2);
	  //list.combineLists2(l2);
	    System.out.print("Inserting node 200 at position 5--");
	    Node n = new Node(200);
	    list.insertAtPosition(5, n);
	    list.printList2();
	}
}
