package com.gems.algorithms;

public class Stack<T> {

	private T[] stack; 
	private int N;
	
	public Stack(int size)
	{
		stack = (T[]) new Object[size];
		N = 0;
	}
	
	public boolean isEmpty()
	{
		return 0 == N;
	}
	
	public int size()
	{
		return stack.length;
	}
	
	private void resize(int size)
	{
		T[] array = (T[]) new Object[size];
		for (int i=0; i<stack.length; i++) 
			array[i] = stack[i];
		stack = array;
	}
	
	public void push(T item)
	{
		if (N == stack.length) resize(2*stack.length);
		stack[N++] = item;
	}
	
	public T pop() 
	{
		T item = stack[--N];
		stack[N] = null;
		if (N > 100 && N == stack.length / 4) resize(stack.length / 2);
		return item;
	}
}
