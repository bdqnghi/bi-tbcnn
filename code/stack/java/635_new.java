package Prep;

import java.util.Stack;

public class SortStack {
	public static void main(String op[]){
		Stack<Integer> stack = new Stack<Integer>();
		stack.push(9);
		stack.push(1);
		stack.push(18);
		stack.push(3);
		for(int i=0;i<stack.size();i++){
			swapAndCompare(stack);
		}
		System.out.println(stack.toString());
	}

	private static void swapAndCompare(Stack<Integer> stack) {
		if(stack.size()==1)
			return;
		int x = stack.peek();
		stack.pop();
		swapAndCompare(stack);
		if(stack.peek()<x){
			int y = stack.peek();
			stack.pop();
			stack.push(x);
			stack.push(y);
		}
		else
			stack.push(x);
	}
}
