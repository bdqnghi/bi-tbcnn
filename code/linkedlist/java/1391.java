package Collection;

import java.util.LinkedList;

public class Linkedlist {
     public static void main(String args[]){
    	 
    	 //LinekdList Decalaration
    	 LinkedList<String> ls = new LinkedList<String>();
    	 
    	 //add element to linked list
    	 ls.add("Item1");
    	 ls.add("Item2");
    	 ls.add("Item6");
    	 ls.add("Item4");
    	 ls.add("Item9");
    	 
    	 //To display element in linked list
    	 System.out.println(ls);
    	 
    	 //add first and add last element
    	 ls.addFirst("First Item");
    	 ls.addLast("Last Item");
    	 System.out.println("List Content after additon" + ls);
    	 
    	 //This is how to get and set values
    	 Object var = ls.get(0);
    	 System.out.println("First item is " +var);
    	 ls.set(0, "Changed First Item");
    	 Object var2 = ls.get(0);
    	 System.out.println("After setting :" +var2);
    	 
    	 //Remove first and Last Element 
    	 ls.removeFirst();
    	 ls.removeLast();
    	 System.out.println("After removing first and last element :" + ls);
    	 
    	 //Add to a position and remove to the position 
    	 ls.add(0, "First Item ");
    	 ls.remove(2);
    	 System.out.println("After removing and adding element" +ls);
    	 
    	 
     }
}
