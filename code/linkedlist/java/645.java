package com.sai;

import java.util.HashSet;

public class Linkedlist {
	ListNode head = null;
	ListNode tail = null;
	int size = 0;

	public void addStart(int data) {

		ListNode newNode = new ListNode(data);
		if (head == null) {
			head = newNode;
			tail = newNode;
			size++;
		} else {
			newNode.next = head;
			head = newNode;
			size++;
		}

	}

	public void addEnd(int data) {

		ListNode newNode = new ListNode(data);
		if (tail == null) {
			head = newNode;
			tail = newNode;
			size++;
		} else {
			tail.next = newNode;
			tail = newNode;
			size++;

		}
	}

	public int addAtIndex(int data, int index) {
		if (index > size + 1 || index < 1) {
			System.out.println("Invalid position");
		}
		ListNode before = null;
		ListNode after = null;
		ListNode dummy = head;
		int count = 0;
		while (dummy.next != null) {
			count++;
			if (count == index - 1) {
				before = dummy;
			}

			dummy = dummy.next;

		}
		after = before.next;
		ListNode node = new ListNode(data);
		before.next = node;
		node.next = after;
		size++;
		return data;

	}

	public int Delete(int data) {
		ListNode start = head;
		ListNode before = null;
		while (start.data != data) {
			if (start.next == null) {
				System.out.println("Not existing");
			} else {

				before = start;
				start = start.next;
			}
		}
		if (start == head) {
			head = head.next;
			size--;
		} else {
			before.next = start.next;
			size--;
		}
		return start.data;

	}

	public int find(int val) {
		ListNode finder = head;
		while (finder.data != val) {
			if (finder.next == null) {
				return 0;
			} else {

				finder = finder.next;
			}
		}
		return finder.data;

	}

	public void display() {
		ListNode dummy = head;

		while (dummy != null) {
			System.out.println(dummy);
			dummy = dummy.next;

		}

	}

	public void displayReverse(ListNode head) {
		ListNode dummy = head;
		while (dummy != null) {
			System.out.println(dummy.data);
			dummy = dummy.next;

		}

	}

	public void ReverseList() {
		ListNode current = head;
		ListNode previous = null;
		ListNode next = null;

		while (current != null) {
			next = current.next;
			current.next = previous;
			previous = current;
			current = next;
		}
		System.out.println("After Reversing");
		displayReverse(previous);

	}

	public int Addafter(int data, int val) {
		ListNode dummy = head;
		ListNode previous = null;
		ListNode newNode = new ListNode(val);
		if (head.data == data) {
			newNode.next = head.next;
			head.next = newNode;
		} else {
			while (dummy.data != data) {
				dummy = dummy.next;
				previous = dummy;
			}
			newNode.next = previous.next;
			previous.next = newNode;
			size++;
		}
		return val;
	}

	public int printNthFromLast(int n) {
		ListNode dummy = head;
		int len = 0;

		while (dummy != null) {
			len++;
			dummy = dummy.next;
		}

		if (n > len) {
			return -1;
		}
		dummy = head;

		for (int i = 1; i < len - n + 1; i++) {
			dummy = dummy.next;
		}

		return dummy.data;

	}

	public int printNthFromLastRecursion(ListNode node, int n) {

		if (node == null) {
			return 0;
		}
		int index = printNthFromLastRecursion(node.next, n) + 1;
		if (index == n) {
			System.out.println(n + "th node from last is " + node.data);
		}
		return index;

	}

	ListNode nthTolast(ListNode head, int k) {
		ListNode pl = head;
		ListNode p2 = head;

		/* Move pl k nodes into the list. */
		for (int i = 0; i < k; i++) {
			if (pl == null)
				return null; // Out of bounds
			pl = pl.next;
		}
		/*
		 * Move them at the same pace. When pl hits the end, p2 will be at the
		 * right element.
		 */
		while (pl != null) {
			pl = pl.next;
			p2 = p2.next;
		}
		return p2;
	}

	public ListNode middlenumber() {
		ListNode slowptr = head;
		ListNode fastptr = head;

		while (fastptr != null) {
			fastptr = fastptr.next;

			if (fastptr != null && fastptr.next != null) {
				slowptr = slowptr.next;
				fastptr = fastptr.next;
			}
		}

		return slowptr;

	}

	public ListNode RevUsingRecursion(ListNode node) {

		if (node == null || node.next == null) {
			return node;
		}
		ListNode remaining = RevUsingRecursion(node.next);
		node.next = node;
		node.next = null;
		System.out.println(remaining.data);
		return remaining;

	}

	public boolean checkPalindrome() {
		ListNode middle = middlenumber();

		ListNode secondHead = middle.next;
		middle.next = null;
		ListNode revsecond = RevUsingRecursion(secondHead);

		while (head != null && secondHead != null) {
			if (head.data == revsecond.data) {
				head = head.next;
				revsecond = revsecond.next;
				continue;
			} else {

				return false;
			}
		}

		return true;

	}

	public void removeDuplicates() {
		HashSet<Integer> set = new HashSet<Integer>();
		ListNode dummy = head;
		ListNode previous = null;
		while (dummy != null) {
			if (set.contains(dummy.data)) {
				previous.next = dummy.next;
			} else {
				set.add(dummy.data);
				previous = dummy;
			}
			dummy = dummy.next;

		}

	}

	public static void main(String[] args) {

		Linkedlist list = new Linkedlist();
		list.addEnd(4);
		list.addEnd(5);
		list.addEnd(4);
		list.addEnd(7);
		list.addEnd(7);
		list.addStart(2);

		System.out.println("before insertion");
		list.display();
		int z = list.addAtIndex(3, 2);

		System.out.println("after insertion of " + z);
		list.display();

		int x = list.Delete(3);
		System.out.println("after deletion of " + x);
		list.display();

		int y = list.find(5);
		if (x != 0) {
			System.out.println("Found " + y);
		} else {
			System.out.println("Not Found");
		}

		int m = list.Addafter(2, 3);
		System.out.println("After adding " + m);

		list.display();
		System.out.println("2nd element from end is " +list.printNthFromLast(2));
		list.printNthFromLastRecursion(list.head, 4);
		System.out.println("3rd element from end is " +list.nthTolast(list.head, 3).data);
		// boolean bool =list.checkPalindrome();
		// if(bool){
		// System.out.println("List is palindrome");
		// }else{
		// System.out.println("List is not palindrome");
		// }
		System.out.println("Middle element is " + list.middlenumber().data);
		// System.out.println("Reversing using recursion");
		// list.RevUsingRecursion(list.head);
		System.out.println("After removing duplicates");
		list.removeDuplicates();
		list.display();
		//list.ReverseList();
		list.RevUsingRecursion(list.head);

	}

}

class ListNode {

	int data;
	ListNode next;

	ListNode(int data) {
		this.data = data;
	}

	public String toString() {
		return data + "";
	}

}
