package com.whattheheckisthis;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Stack<E> {
	private E[] elements;
	public int size= 0;
	public Stack(){
		elements = (E[])new Object[10];
	}
	
	public void push(E item){
		elements[size++] = item;
	}
	
	public E pop(){
	
		return (E)elements[--size];
		
	}
	static <K,V> HashMap<K,V> newHashmap(){
		return new HashMap<K,V>();
	}
	
	public static void main(String[] args) {
		
		Map<String,List<String>> myMap= newHashmap();
		
		Stack<String> myStack = new Stack<String>();
		myStack.push("One");
		myStack.push("Two");
		myStack.push("Three");
		
		for(int i=0;i<myStack.size;i++){
			System.out.println("Element:" + myStack.pop());
		}
	     
	}
}
