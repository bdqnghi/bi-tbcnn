package learn;
import java.util.Iterator;
import java.util.NoSuchElementException;


public class Stack<Item> implements Iterable<Item> {
	private Node first;
	private int N;
	
	public Stack(){
		first = new Node();
	}
	private class Node{
		Item item;
		Node next;
	}
	public Item pop(){
		if(first.item == null) throw new NoSuchElementException("Stack is Empty!");
		Item item = first.item;
		first = first.next;
		N--;
		return item;
	}
	public void push(Item i){
		Node oldFirst = first;
		first = new Node();
		first.item = i;
		first.next = oldFirst;
		N++;
	}
	public boolean isEmpty(){
		return N == 0;
	}
	public int size(){
		return N;
	}
	public Iterator<Item> iterator(){
		return new StackIterator();
	}
	private class StackIterator implements Iterator<Item>{
		@Override
		public boolean hasNext() {
			return !isEmpty();
		}
		@Override
		public Item next() {
			return pop();
		}
		@Override
		public void remove() {}
	}

	public static void main(String[] args) {
		Stack<String> strStack = new Stack<String>();
		strStack.push("to");
		strStack.push("be");
		strStack.push("or");
		strStack.push("not");
		strStack.push("that");
		strStack.push("is");

		for(String s : strStack){
			System.out.print(s + " ");
		}
	}
	@Override
	public String toString() {
		String rtn = "Stack [";
		for(Item s : this){
			rtn += s + ", ";
		}
		return rtn + "]";
	}
	public String cleanString() {
		String rtn = "";
		for(Item i : this){
			rtn += i + " ";
		}
		return rtn + "";		
	}
}
