package com.qsoft.stack;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;
import org.junit.Test;

public class StackTest {

	@Test
	public void returnZeroWhenStackIsEmpty() {
		Stack stack = new Stack();
		assertEquals(0, stack.getSize());
	}

	@Test
	public void returnOneWhenPushElementToStack() {
		Stack stack = new Stack();
		stack.push(1);
		assertEquals(1, stack.getSize());
	}

	@Test
	public void pushToStackContainSomeElement() {
		Stack stack = new Stack(5);
		stack.push(1);
		assertEquals(6, stack.getSize());
	}

	@Test
	public void topAtEmptyStack() {
		Stack stack = new Stack();
		assertEquals(null, stack.top());
	}

	@Test
	public void topAtStackContainOneElement() {
		Stack stack = new Stack();
		stack.push(1);
		assertEquals(1, (int) stack.top());
	}

	@Test
	public void throwStackEmptyExceptionToPopEmptyStack() {
		try {
			Stack stack = new Stack();
			stack.pop();
			fail();
		} catch (RuntimeException e) {
			// TODO: handle exception
			assertEquals("StackEmptyException", e.getMessage());
		}
	}

	@Test
	public void popAtStackContainSomeElement() {
		Stack stack = new Stack(10);
		stack.pop();
		assertEquals(9, stack.getSize());
	}

	@Test
	public void popAtStackContainOneElement() {
		Stack stack = new Stack(1);
		stack.pop();
		assertEquals(0, stack.getSize());
	}

	@Test
	public void testTopAndPopElement() {
		Stack stack = new Stack();
		stack.push(1);
		stack.push(2);
		stack.push(3);
		assertEquals(3, (int) stack.top());
		assertEquals(3, stack.pop());
	}

	@Test
	public void testPushAndPopElement() {
		Stack stack = new Stack();
		stack.push(1);
		stack.push(2);
		stack.push(3);
		assertEquals(3, stack.pop());
		assertEquals(2, stack.pop());
		assertEquals(1, stack.pop());
		assertEquals(0, stack.getSize());
	}
}
