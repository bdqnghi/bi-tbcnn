public class Linklist {

	Node head;
		
	// add node to end of a list
	public void addNode(int value)
	{
		if (head == null)
		{
			head = new Node(value);
			return;
		}
		
		Node newNode = new Node(value);
		Node currentNode = head;
		
		if (currentNode != null)
		{
			while (currentNode.next != null)
				currentNode = currentNode.next;
			currentNode.next = newNode;
		}
	}
	
	// add node to a head of a list
	public void addHead(int value)
	{
		if (head == null)
		{
			head = new Node(value);
			return;
		}
		
		Node newHead = new Node(value);
		newHead.next = head;
		head = newHead;
	}
	
	// get size of a list
	public int getListSize()
	{
		if (head == null)
			return 0;
		return head.getSize();
	}
	
	// remove node with a given value
	public void removeNodewithValue(int value)
	{
		if (head == null)
			return;
		
		if (head.value == value)
		{
			head = head.next;
			return;
		}
		
		Node currentNode = head.next; 	
		Node tmpNode = head;
		while (currentNode != null )
		{
			if (currentNode.value == value)
			{
				tmpNode.next = currentNode.next;
				return;
			}
			tmpNode = currentNode;
			currentNode = currentNode.next;
		}
		return;	
	}
	
	// add node with a given value to a sorted list
	public void addNodeSorted(int value)
	{
		if (head == null || value <= head.value)
		{	
			Node newNode = new Node(value);
			newNode.next = head;
			head = newNode;
			return;
		}
		
		Node currentNode = head.next;
		Node tmpNode = head;
		Node newNode = new Node(value);
		while (currentNode != null)
		{
			if (value <= currentNode.value)
			{
				tmpNode.next = newNode;
				newNode.next = currentNode;
				return;
			}
			tmpNode = currentNode;
			currentNode = currentNode.next;
		}
		tmpNode.next = newNode;
	}
	
	//print a list
	public void printList()
	{
		if (head == null)
			System.out.println("Empty List!");
		
		Node currentNode = head;
		while (currentNode != null)
		{
			System.out.println(currentNode.value);
			currentNode = currentNode.next;
		}	
	}
}
