

public class linkedlist {
	private Link root;
	private Link iter;
	
	private class Link{
		private Link next;
		private int data;
		
		Link(int veri){
			data = veri;
			next = null;
		}
	}
	
	public void add(int d)
	{
		Link n = new Link(d);
		if(root == null) // list is empty
		{
			iter = n;
			root = n;
		}
		else{ // add next element
			iter.next = n; // shows next element
			iter = n;
		}
		
	}
	
	public void remove(int r)
	{
		Link d = root; Link prev = null; 
		// d is a starting node,
		// prev,which is used showing next element, comes before deleted node
		
		while(d != null){
			if(d.data == r){
				if(root.data == r){ // is root deleted ? it is special situation
					root = d.next;
					break;
				}
				prev.next = d.next; // delete node normally
				d = d.next;
				break;
			}
			else { prev = d; d = d.next; } // goes to next node
		}
	}
	
	public void print(){
		Link d = root;
		while(d != null){ // visits all nodes
			System.out.print(d.data + " ");
			d = d.next;
		}
	}
	
	public static void main(String [] args)
	{
		int[] nums = {31,2, 1,56,33,777,123,25,15,17,20,11,10,1,23,3};
		linkedlist list = new linkedlist();
		for(int i = 0; i < nums.length; i++) list.add(nums[i]);
		
		list.print(); // list
		list.remove(777); // delete 777
		System.out.println(); 
		list.print(); // relist
	}
	
}
