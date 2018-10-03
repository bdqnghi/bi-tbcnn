package collections;

import java.util.List;
import java.util.Stack;

public class StackTest 
{
	public static void main(String[] args) {
		
		Stack<String> stack=new Stack<String>();
		
		//add elements
		stack.push("Botton");
		printStack(stack);
		stack.push("Second");
		printStack(stack);
		stack.push("Third");
		printStack(stack);
		
		stack.pop();
		printStack(stack);
	}

	private static void printStack(Stack<String> stack) {
		// TODO Auto-generated method stub
		System.out.println(" ");
		for(String x:stack)
		{
			
			System.out.printf("%s ",x);
		}
		
	}

}
