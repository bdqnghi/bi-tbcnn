package lecjan;

public class linkedlist {
	private class Node {
		int data;
		Node next;

		public Node(int d, Node next) {
			this.data = d;
			this.next = next;
		}
	}

	Node head;
	Node tail;
	int size;

	public linkedlist() {
		this.head = null;
		this.tail = null;
		this.size = 0;
	}

	public int sizeof() {
		return this.size;
	}

	public boolean isempty() {
		return this.size == 0;
	}

	public void addfirst(int data, Node next) {
		Node n = new Node(data, this.head);

		if (this.size == 0) {
			this.head = n;
			this.tail = n;
		} else {
			this.head = n;
		}

		this.size++;
	}

	public void display() {
		Node temp = this.head;
		while (temp != null) {
			System.out.print(temp.data + "-->");
			temp = temp.next;
		}
	}

	public void addlast(int data, Node next) {
		if (this.size == 0) {
			this.size++;
			Node n = new Node(data, null);
			this.head = n;
			this.tail = n;
		} else {
			this.size++;
			Node n = new Node(data, null);
			tail.next = n;
			this.tail = n;
		}
	}

	public void addbet(int data, int index) throws Exception {
		if (index < 0 || index > this.size) {
			throw new Exception("Out of bound");
		} else if (index == 0)
			addfirst(data, null);
		else if (index == this.size)
			addlast(data, null);
		else {
			Node t = in(index - 1);

			Node temp = new Node(data, t.next);
			t.next = temp;

			this.size++;
		}
	}

	public int removefirst() throws Exception {
		int num;
		if (this.size == 0) {
			throw new Exception("Nothing to remove");
		} else {

			Node temp = this.head;
			num = temp.data;
			if (this.size == 1) {

				this.head = null;
				this.tail = null;
			} else
				this.head = this.head.next;

			this.size--;
			return num;
		}

	}

	public int removelast() throws Exception {
		if (this.size == 0) {
			throw new Exception("Nothing to remove");
		} else {
			
			int num = this.tail.data;
			if (this.size == 1) {
				this.head = null;
				this.tail = null;
			}

			else {

				Node temp = in(this.size - 2);
				temp.next = null;
				this.tail = temp;
			}
			
			this.size--;
			return num;
		}
		
	}

	public int removebet(int index) throws Exception {
		if (this.size == 0) {
			throw new Exception("Nothing to remove");
		}
		Node temp = in(index - 1);
		int num = temp.next.data;
		temp.next = temp.next.next;
		this.size--;
		return num;
	}

	public int getfirst() throws Exception {
		if (this.size == 0) {
			throw new Exception("List is empty");
		} else
			return this.head.data;
	}

	public int getlast() throws Exception {
		if (this.size == 0) {
			throw new Exception("List is empty");
		} else
			return this.tail.data;
	}

	public int getbet(int index) throws Exception {
		if (this.size == 0) {
			throw new Exception("List is empty");
		}
		if (index < 0 || index >= this.size) {
			throw new Exception("Index out of bound ");
		}
		return in(index).data;
	}

	private Node in(int index) {
		Node n = this.head;
		while (index != 0) {
			n = n.next;
			index--;
		}
		return n;
	}

	public void reverseDI() // like bubble sort
	{
		Node temp = head;
		for (int i = this.size; i > 0; i--) {
			Node temp2 = temp;
			for (int j = 1; j < i; j++) {
				Node other = temp2.next;
				int sub = temp2.data;
				temp2.data = other.data;
				other.data = sub;
				temp2 = temp2.next;
			}
		}
	}

	public void reversePI() {

	}

	public void reversePR() // pointer iterative
	{
		reversePRhelp(head);
		Node temp = this.head;
		this.head = this.tail;
		this.tail = temp;
	}

	private void reversePRhelp(Node right) {
		if (right.next == null) {
			this.tail = right;
			this.head = right;
			return;
		}
		reversePRhelp(right.next);
		right.next = null;
		this.head.next = right;
		this.head = right;
	}

	public void reverseDR() // data recursive
	{
		reverseDRhelp(this.head, this.head);
	}

	public Node reverseDRhelp(Node left, Node right) {
		if (right == null) {
			return left;
		}
		Node n = reverseDRhelp(left, right.next);
		int temp = n.data;
		n.data = right.data;
		right.data = temp;
		if(left)
		return left.next;
	}
}
