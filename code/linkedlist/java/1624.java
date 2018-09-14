
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
    public void insertLoop(int index){
		Node endNode = head;
			while(endNode.next!=null){
				endNode = endNode.next;
			}
		Node indexNode = head;
		while(index!=0){
			indexNode = indexNode.next;
			index--;
		}
		endNode.next = indexNode;
	}
	public void displayLoop(){
		System.out.println("");
		Node currNode = head;
		int cnt = 15;
		while(cnt!=0){
			System.out.print("->" + currNode.data);
			currNode=currNode.next;
			cnt--;
		}
	}
	public void display(){
		System.out.println("");
		Node currNode = head;
		while(currNode!=null){
			System.out.print("->" + currNode.data);
			currNode=currNode.next;
		}
	}    
}
