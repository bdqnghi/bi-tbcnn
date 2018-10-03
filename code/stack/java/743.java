package model;
import java.util.LinkedList;

public class Stack {

	private LinkedList<Integer> stack = new LinkedList<Integer>();
		
	/**
	 * stack up a operand
	 * @param Integer operand
	 */
	public void push(Integer operand) {
		System.out.println("PUSH:" + operand);
	    this.stack.addFirst(operand);
	}
	
	/**
	 * remove operand from top of pile
	 * @return Integer
	 */
	public int pop() {
	    return this.stack.removeFirst();
	}
}
