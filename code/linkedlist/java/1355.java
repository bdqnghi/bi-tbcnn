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
    public Node addatend(int data){
    	Node n = new Node(data);
 	   if(head==null){
 		  
 	 	   n.next=head;
 	 	   head=n;
 	 	   size++;
 	   }else{
 		   
 		   n.next=null;
 		   Node ptr = head;
 		   while(ptr.next!=null){
 			   ptr=ptr.next;
 		   }
 		   ptr.next=n;
 		   size++;
 		   
 	   }
 	   return n;
}
    
    public void display(){
		System.out.println("");
		Node currNode = head;
		while(currNode!=null){
			System.out.print("->" + currNode.data);
			currNode=currNode.next;
		}
		System.out.println("");
	}
    public void createIntersection(Linkedlist a, Node nd){
		Node hd = a.head; // this is the list to which another list will intersect, in our example its list a
		while(hd!=nd){
			hd = hd.next;
		}
		Node currNode = head;// this is for the list which will connect, in our example its list b
			while(currNode.next!=null){
				currNode = currNode.next;
			}
			currNode.next = hd; 
	}
    }