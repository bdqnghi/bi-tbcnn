package com.datastructures.stack;

import java.util.Iterator;

public class Stack<Item> implements Iterable<Item> {

	@SuppressWarnings("unchecked")
	private Item[] array = (Item[]) new Object[1];
	private int N = 0;
	
	
	public Stack() {};
	
	public boolean isEmpty() { return N == 0;}
	public int size() { return N; }
	@SuppressWarnings("unchecked")
	private void resize(int max){
		Item[] temp = (Item[]) new Object[max];
		for (int i = 0; i < N; i++) {
			temp[i] = array[i];
		}
		array = temp;
	}
	
	public void push(Item item){
		if (N == array.length) resize(array.length * 2); 
		array[N++] = item;
	}
	
	public Item pop(){
		Item item;
		item = array[--N];
		array[N + 1] = null;
		if (N > 0 && N == array.length/4) resize(array.length/2);
		return item;
	}
	
	@Override
	public Iterator<Item> iterator() {
		// TODO Auto-generated method stub
		return new StackIter();
	}
	
	private class StackIter implements Iterator<Item> {

		private int i = N;
		@Override
		public boolean hasNext() {
			return  i > 0;
		}

		@Override
		public Item next() {
			return array[--i];
		}

		@Override
		public void remove() {
			// TODO Auto-generated method stub
			
		}
		
	}

}
