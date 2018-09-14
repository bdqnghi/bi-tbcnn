package sorting;

/**
 * Another storage
 * 
 * 
 */

import java.util.Iterator;
import java.util.NoSuchElementException;

public class linkedlist<E extends Comparable<E>> implements linkedListinterface<E>, Iterable<E> {
	Node<E> head = null;
	Node<E> tail = null;
	private int size = 0;

	public boolean isEmpty() {
		return head == null;
	}

	@Override
	public boolean add(E e) {
		if (isEmpty()) {
			head = new Node<E>(e, head);
			tail = head;
			size++;
			return true;
		}
		Node<E> oldTail = tail;
		tail = new Node<E>(e, null);
		oldTail.next = tail;
		size++;
		return true;
	}
	
	public boolean add(int index, E e) {
		if (index == 0){
			head = new Node<E>(e, head);
			size++;
			return true;
		}
		Node<E> temp = head;
		for (int i = 0; i < index-1; i++)
			temp = temp.next;
		if (temp == null) {
			throw new IndexOutOfBoundsException();
		}
		temp.next = new Node<E>(e, temp.next.next);
		size++;
		return true;
	}
	
	

	@Override
	public boolean contains(Object o) {
		Node<E> temp = head;
		while (temp != null) {
			if (temp.data.equals(o))
				return true;
			temp = temp.next;
		}
		return false;
	}

	private boolean removeHead() {
		if (head == null)
			throw new RuntimeException("cannot delete");
		head = head.next;
		size--;
		return true;
	}
	
	public E pop(){
		E data = head.data;
		removeHead();
		return data;
	}
	
	@Override
	public boolean remove(Object o) {
		if (head == null)
			return false;

		if (head.data.equals(o)) {
			head = head.next;
			size--;
			return true;
		}
		Node<E> prev = null;
		Node<E> cur = head;
		while (cur != null) {
			if (cur.data.equals(o)) {
				prev.next = cur.next;
				size--;
				return true;
			}
			prev = cur;
			cur = cur.next;
		}
		return false;
	}

	@Override
	public E get(int index) {
		Node<E> temp = head;
		for (int i = 0; i < index; i++)
			temp = temp.next;
		if (temp == null) {
			throw new IndexOutOfBoundsException();
		}
		return temp.data;
	}

	@Override
	public linkedListinterface<E> sort() {
		// TODO Auto-generated method stub
		return mergeSort(this);
	}

	@Override
	public int size() {
		return size;
	}

	private linkedListinterface<E> mergeSort(linkedlist<E> list) {
		int listSize = list.size();
		if (listSize <= 1) {
			return list;
		}
		int mid = listSize % 2 == 0 ? listSize / 2 : (listSize + 1) / 2;
		linkedlist<E> left = new linkedlist<>();
		linkedlist<E> right = new linkedlist<>();
		for (int i = 0; i < mid; i++) {
			left.add(list.get(i));
		}
		for (int i = mid; i < listSize; i++) {
			right.add(list.get(i));
		}

		left = (linkedlist<E>) mergeSort(left);
		right = (linkedlist<E>) mergeSort(right);
		return merge(left,right);
	}

	private linkedListinterface<E> merge(linkedlist<E> left, linkedlist<E> right) {
		linkedlist<E> result = new linkedlist<>();
		while(!left.isEmpty() && !right.isEmpty()){
			if(left.get(0).compareTo(right.get(0)) <= 0){
				result.add(left.get(0));
				left.removeHead();
			}else {
				result.add(right.get(0));
				right.removeHead();
			}			
		}
		while(!left.isEmpty()){
			result.add(left.get(0));
			left.removeHead();
		}
		while(!right.isEmpty()){
			result.add(right.get(0));
			right.removeHead();
		}		
		return result;
	}

	@Override
	public Iterator<E> iterator() {
		// TODO Auto-generated method stub
		return new FastCompetitionIterator();
	}

	private class FastCompetitionIterator implements Iterator<E> {
		Node<E> nextNode;

		public FastCompetitionIterator() {
			nextNode = head;
		}

		@Override
		public boolean hasNext() {
			return nextNode != null;
		}

		@Override
		public E next() {
			if (!hasNext())
				throw new NoSuchElementException();
			E res = nextNode.data;
			nextNode = nextNode.next;
			return res;
		}

	}
}
