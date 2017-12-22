import java.util.*;
public class linkedlist {
	
	public static void main(String args[]) {
		
		LinkedList<String> ll=new LinkedList<String>();
		
		/*adding  the elements to ll*/
		ll.add("we");
		ll.add("don't");
		ll.add("talk");	
		ll.add("anymore");
		
		display(ll);
		
		/*add element to first place and tail */
		ll.addFirst("Four");
		ll.addLast("years");
		
		display(ll);
		
		/*add the element to any position with index */
		
		ll.add(6, "no");
		ll.add(7, "call");
		
		display(ll);
		
		/*set new element to change the element*/
		ll.set(0, "Charlie");
		
		/* get values */
		System.out.println("The first element after update is :"+ll.getFirst());
		
		/*remove values*/
		ll.removeFirst();
		System.out.println("The new linkedlist after removing first element: "+ ll);
		
	}

	private static void display(LinkedList<String> ll) {
		// TODO Auto-generated method stub
		System.out.println("The LinkedList is shown like this: " + ll);
		
	}

}
