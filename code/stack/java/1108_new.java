package my.custom.stack;


import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class StackTest {

	@Test
	public void testArrayStack() {
		Stack<Integer> stack = new ArrayStack<Integer>();
		assertTrue(stack.empty());
		
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(3);
		stack.push(4);
		
		assertTrue(stack.size() == 5);
		assertTrue(!stack.empty());
		
		assertTrue(4 == stack.pop());
		assertTrue(3 == stack.pop());
		assertTrue(3 == stack.pop());
		assertTrue(2 == stack.pop());
		assertTrue(1 == stack.pop());
		
		assertTrue(stack.size() == 0);
		assertTrue(stack.empty());
	}

}
