
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
}}
