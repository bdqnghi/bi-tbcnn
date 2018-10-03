package com.promouit.stack.utils;

import com.promouit.stack.exception.StackEmptyException;
import com.promouit.stack.impl.Stack;

public class StackUtils {

	public static <E extends Comparable<E>> Stack<E> sortStack(Stack<E> stack) throws StackEmptyException{
		Stack<E> tempStack = new Stack<E>();
		while(!stack.isEmpty()){
			E data = stack.pop();
			while(!tempStack.isEmpty()&&(tempStack.peek().compareTo(data)<0)){
				stack.push(tempStack.pop());
			}
			tempStack.push(data);
		}
		return tempStack;
	}
	
}
