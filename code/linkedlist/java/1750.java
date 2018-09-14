

	public class Linkedlist {
		public Node head;
	    public int size;
	    public Linkedlist(){
	     	head=null;
	     	}
	    public void Addatbeg(int data){
	 	   Node n = new Node(data);
	 	   n.next=head;
	 	   head=n;
	 	   size++;
	    }
	    public void addatend(int data){
	 	   if(head==null){
	 		   Addatbeg(data);
	 	   }else{
	 		   Node n = new Node(data);
	 		   n.next=null;
	 		   Node ptr = head;
	 		   while(ptr.next!=null){
	 			   ptr=ptr.next;
	 		   }
	 		   ptr.next=n;
	 		   size++;
	 	   }
	}
	    public void reverselist(Node head){
	    	Node current = head;
	    	Node next=null;
	    	Node previous = null;
	    	while(current!=null){
	    		next=current.next;
	    		current.next=previous;
	    		previous=current;
	    		current =next;
	    	}
	    	head = previous;
	    	System.out.println("Reversed list is");
	    	display(head);
	    	
	    }
	    public void display(Node head){
	    	Node currNode = head;
			while(currNode!=null){
				System.out.print("->" + currNode.data);
				currNode=currNode.next;
			
	    }
	    
	}}
	

