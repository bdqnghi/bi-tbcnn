package com.RandomExer;

import java.util.LinkedList;

public class linkedlist {

	public static void main(String args[])
	{
		LinkedList<String> ll = new LinkedList<String>();
		ll.add("sathya");
		ll.add("surya");
		ll.add("shiva");
		
		System.out.println("Before Addition : " + ll);
		
		ll.addFirst("Jaxx");
		ll.addLast("Reverse");
		
		
		System.out.println("After Addition : " + ll);
		
	}
	
}


