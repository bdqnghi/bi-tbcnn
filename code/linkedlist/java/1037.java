
public class Linkedlist {
	Node head;
	Node tail;
	int size;
	public Linkedlist(){
		head=null;
		tail=null;size=0;
	}
	
	public void insert(int data){
		Node n=new Node(data);
		
		if(size==0){
			head=tail=n;
		}
		else{
			tail.next=n;
			n.prev=tail;
			tail=n;
		}
		size++;
	}
	
	public void delete(int data){
		
		while(head.x==data){
			if(size==1){
				head=null;
				tail=null;
			}
			else{head=head.next;
			head.prev=null;}
			size--;
		}
		Node curr=head.next;
		while(curr!=tail){
			if(curr.x==data){
				
				curr.next.prev=curr.prev;
				curr.prev.next=curr.next;
				
				size--;
			}
			curr=curr.next;
		}
		if(tail.x==data){
			tail=tail.prev;
			tail.next=null;
			size--;
		}
	}
	
	public void reverse(int n1,int n2){
		Node curr1=head;
		Node curr2=tail;
		while(curr1!=null){
			if(curr1.x==n1){
				curr1=curr1.prev;
			}
			else
			curr1=curr1.next;
		}
		
		while(curr2!=null){
			if(curr2.x==n2){
				curr2=curr2.next;;
			}
			else
			curr2=curr2.prev;
		}
		//check
		curr1.next=curr2.prev;
		Node curr3=curr1.next;
		while(curr3.prev!=curr1){
			curr3.next=curr3.prev;
			curr3=curr3.next;
		}
		
		curr3.next=curr2;
		//prev pointers
		curr3=curr1.next;
		while(curr3!=curr2){
			curr3.prev=curr1;
			curr3=curr3.next;
			curr1=curr1.next;
		}
	}
	
	public void displaylist(){
		Node curr=head;
		while(curr!=null){
			curr.displayNode();
			curr=curr.next;
		}
	}

}
