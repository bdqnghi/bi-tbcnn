package task_3;
import java.util.Iterator;

public class Stack<Item> implements Iterable<Item> {
	private class Node {
		Item item;
		Node next;
	}
	Node first;
	public boolean isEmpty() {
		return first == null;
	}
	public void push (Item item) {
		Node newFirst = new Node();
		newFirst.item = item;
		newFirst.next = first;
		first = newFirst;
	}
	public Item pop() {
		Item item = first.item;
		first = first.next;
		return item;
	}
	private class ListIterator implements Iterator<Item> {
		Node current = first;
		public boolean hasNext() {
			return current != null;
		}
		public void remove() {}
		public Item next() {
			Item item = current.item;
			current = current.next;
			return item;
		}
	}
	public Iterator<Item> iterator() {
		return new ListIterator();
	}
	public boolean isCyclical() {
		if (first.next == first) return true;
		boolean b = false;
		Node index2 = first.next.next;
		Node index3 = index2.next;
		while (index2 != null && index3 != null && !b) {
			index2 = index2.next.next;
			if (index2 == index3) b = true;
			index3 = index3.next.next.next;
		}
		return b;
	}
	public void show() {
		int i = 20;
		Node p = first;
		while (i > 0 && p != null) {
			System.out.print(p.item + " ");
			i--;
			p = p.next;
		}
		System.out.println();
	}
	public static void main(String[] args) {
		Stack<Integer> intStack = new Stack<Integer>();
		intStack.push(1);
		intStack.push(2);
		intStack.push(3);
		intStack.push(4);
		intStack.push(5);
		intStack.first.next.next.next.next.next = intStack.first.next;
		System.out.print("intStack: ");
		intStack.show();
		Stack<String> stringStack = new Stack<String>();
		stringStack.push("a");
		stringStack.push("b");
		stringStack.push("s");
		stringStack.push("f");
		stringStack.push("rr");
		stringStack.push("lala");
		System.out.print("stringStack: ");
		stringStack.show();
		if (intStack.isCyclical()) System.out.println("intStack is cyclical");
		else System.out.print("intStack is not cyclical");
		if (stringStack.isCyclical()) System.out.println("stringStack is cyclical");
		else System.out.print("stringStack is not cyclical");
	}
}
