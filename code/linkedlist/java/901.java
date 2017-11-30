import java.util.*;
	public class Linkedlist {

		public static void main(String[] args) {
			// TODO Auto-generated method stub
			LinkedList<Object>al=new LinkedList<Object>();
			al.add("arun");
			al.add("How");
			al.add("Are");
			al.add("you");
			System.out.println("List of items"+al);
			
			
			LinkedList<Object>a2=new LinkedList<Object>();
			a2.add("Rohan");
			a2.add("How");
			a2.add("Are");
			a2.add("You ?");
			System.out.println("List of items in Array2"+a2);
			System.out.println("........................................");
			
			
			al.addAll(a2);
			System.out.println("After adding Array2"+al);
}
}
