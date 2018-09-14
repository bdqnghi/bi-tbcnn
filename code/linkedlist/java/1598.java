
public class Linkedlist {
	public void deleteMiddle(Node mid){

		if(mid.next==null){

			return;

		}

		Node curr = mid;

		curr.data = curr.next.data;

		curr.next = curr.next.next;

	}

	public void display(Node head){

		Node n=head;

		while(n!=null){

			System.out.print("->" + n.data);

			n=n.next;
            
		}
		System.out.println();

	}
	}