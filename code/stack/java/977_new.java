package com.tomsquires.puzzles.stacks;

import org.junit.Assert;
import org.junit.Test;

public class StackTest {
    @Test
    public void testSize() {
        Stack<Integer> stack = getIntegerStack();

        Assert.assertEquals(3, stack.size());
    }

    @Test
    public void testPushManyElements() {
        Stack<Integer> stack = getIntegerStack();
        stack.push(4);
        stack.push(5);
        stack.push(6);
        stack.push(7);
        stack.push(8);
        stack.push(9);
        stack.push(10);
        stack.push(11);
        stack.push(12);
        stack.push(13);

        Assert.assertEquals(13, stack.size());
    }

    @Test
    public void testPop() {
        Stack<Integer> stack = getIntegerStack();
        Assert.assertEquals(3, stack.size());

        Assert.assertEquals(8, (Object) stack.pop());
        Assert.assertEquals(2, (Object) stack.pop());
        Assert.assertEquals(5, (Object) stack.pop());

        Assert.assertEquals(0, stack.size());
    }

    @Test
    public void testPeek() {
        Stack<Integer> stack = getIntegerStack();

        Assert.assertTrue(stack.peek(2));
        Assert.assertFalse(stack.peek(37));
        Assert.assertEquals(3, stack.size());
    }

    private Stack<Integer> getIntegerStack() {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(5);
        stack.push(2);
        stack.push(8);
        return stack;
    }
}
