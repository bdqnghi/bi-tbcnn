
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
    public void display(Node head){
		System.out.println("");
		Node currNode = head;
		while(currNode!=null){
			System.out.print("->" + currNode.data);
			currNode=currNode.next;
		}
		System.out.println("");
	}
    
}
