/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.tolok.javacorereinforcement.datastructure;

import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Serhii_Tolok
 */
public class StackArrayBasedTest {    
    
    public StackArrayBasedTest() {
    }

    @Test
    public void testPush() {
        StackArrayBased<String> stack = new StackArrayBased<String>();
        stack.push("b");
        assertEquals("b", stack.pop());
    }
    
    @Test
    public void testPushMany() {
        StackArrayBased<String> stack = new StackArrayBased<String>();
        stack.push("b");stack.push("b");stack.push("b");stack.push("b");
        stack.push("b");stack.push("b");stack.push("b");stack.push("c");
        assertEquals("c", stack.pop());
    }
    
    @Test
    public void testPushTooMany() {
        StackArrayBased<String> stack = new StackArrayBased<String>();
        stack.push("b");stack.push("b");stack.push("b");stack.push("b");
        stack.push("b");stack.push("b");stack.push("b");stack.push("c");
        stack.push("b");stack.push("b");stack.push("b");stack.push("c");
        assertEquals("c", stack.pop());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testPop() {
        StackArrayBased<String> stack = new StackArrayBased<String>();
        stack.push("b");
        stack.pop();
        stack.pop();
    }
    @Test
    public void testPopMany() {
        StackArrayBased<String> stack = new StackArrayBased<String>();
        stack.push("a");stack.push("b");stack.push("b");stack.push("b");
        stack.push("b");stack.push("b");stack.push("b");stack.push("c");
        stack.push("b");stack.push("b");stack.push("b");stack.push("c");
        stack.pop();stack.pop();stack.pop();stack.pop();stack.pop();
        stack.pop();stack.pop();stack.pop();stack.pop();stack.pop();
        stack.pop();
        assertEquals("a", stack.pop());
    }
}