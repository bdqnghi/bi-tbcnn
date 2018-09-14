
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
    public void kthnodefromend(Node head,int k){
    	Node curr = head;
    	while(k>0){
    		curr=curr.next;
    		k--;
    	}
    	Node sec= head;
    	while(curr!=null){
    		curr=curr.next;
    		sec=sec.next;
    	}
    	int i =sec.data;
    	System.out.println("Kth node is"+i);
    	
    	
    }
    public void display(Node head){
		Node n=head;
		while(n!=null){
			System.out.print("->" + n.data);
			n=n.next;
		}
}}