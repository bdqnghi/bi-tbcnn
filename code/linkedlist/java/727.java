package collections;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Iterator;


public class Linkedlist {
	
	
	
	public static void main(String[] aa)
	{
		LinkedList<String>data=new LinkedList<String>();
 
		data.add("e");
		data.add("a");
		data.add("b");
		data.add("c");
		data.add("d");
		data.add("l");
		data.add("k");
		data.addFirst("1");
		data.addLast("0");
		
		
ListIterator itr=data.listIterator();
System.out.println("inserting order");
while(itr.hasNext())
{
	System.out.println("data is"+itr);
}
	System.out.println("reverse order");	
while(itr.hasPrevious())
{
	System.out.println("data is"+itr);
}
data.removeFirst();
data.removeLast();
System.out.println("after removing the first and last element");

Iterator itr1=data.iterator();
while(itr.hasNext())
{
	System.out.println("data is"+itr1.next());
}
data.set(0,"test");
System.out.println("data");

}
		
	
	}


