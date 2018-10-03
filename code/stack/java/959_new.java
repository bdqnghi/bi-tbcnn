package com.structures;

import com.Test;

public class StackTest implements Test {

	public void run() {
	
		Stack<String> stack = new Stack<String>();
		stack.push("quick");
		stack.push("brown");
		stack.push("fox");
		stack.push("jumped");
		stack.push("over");
		stack.push("little");
		stack.push("lazy");
		stack.push("dog");
		
		assert stack.size() == 8;
		
		stack.pop();
		stack.pop();
		assert (stack.pop().equals("little"));
		assert (stack.peek().equals("over"));
		assert (stack.peek().equals("over"));
		assert (!stack.isEmpty());
		assert (stack.size() == 5);
	}
	
	
}
