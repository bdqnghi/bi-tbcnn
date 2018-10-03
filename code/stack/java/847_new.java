package c3.t2_StackMin;

import java.util.Stack;

public class MinStack {

    Stack<Integer> fullStack = new Stack<Integer>();
    Stack<Integer> minStack = new Stack<Integer>();

    public void push(Integer v) {
        if (minStack.empty() || (int) v < (int) minStack.peek()) {
            minStack.push(v);
        } else {
            minStack.push(minStack.peek());
        }
        fullStack.push(v);
    }

    public Integer pop() {
        fullStack.pop();
        return minStack.pop();
    }
}
