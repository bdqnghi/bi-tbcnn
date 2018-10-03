package com.holy.algo.adt;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Queue<T> implements Iterable<T> {

	private class Item {
		T element;
		Item next;
	}
	
	public Queue(){
		count = 0;
		head = null;
		tail = null;
	}
	
	public T dequeue(){
		if(isEmpty())
			throw new NoSuchElementException("buffer underflow");
		T returnValue = head.element;
		head = head.next;
		count--;
		if( isEmpty() )
			tail = null;
		return returnValue;
	}
	
	public void enqueue(T item){
		Item oldTail = tail;
		tail = new Item();
		tail.element = item;
		tail.next = null;
		count++;
		if( isEmpty())
			head = tail;
		else
			oldTail.next = tail;
	}
	
	public boolean isEmpty(){
		return (head==null);
	}
	
	public T peek(){
		if( isEmpty())
			throw new NoSuchElementException("buffer underflow");
		return head.element;
	}
	
	public int size(){
		return count;
	}
	
	public String toString(){
		StringBuilder s = new StringBuilder();
		for( T e : this)
			s.append(e + " ");
		return s.toString();
	}
	
	
	public Iterator<T> iterator() {
		return new ListIterator();
	}

	private class ListIterator implements Iterator<T>{

		private Item current = head;
		
		public boolean hasNext() {
			return (current != null);
		}

		public T next() {
			if( !hasNext() )
				throw new NoSuchElementException("buffer underflow");
			T returnValue = current.element;
			current = current.next;
			return returnValue;
		}

		public void remove() {
			throw new UnsupportedOperationException();
		}	
	}
	
	private int count;
	private Item head;
	private Item tail;
}
