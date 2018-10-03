import java.util.Stack;


public class ReverseStack 
{
	public static void reverseStack(Stack<Integer> stack)
	{
		if(stack.isEmpty())
			return;
		int temp = stack.pop();
		reverseStack(stack);
		insertAtBottom(stack, temp);
	}
	
	public static void insertAtBottom(Stack<Integer> stack, int data)
	{
		if(stack.isEmpty())
		{
			stack.push(data);
			return;
		}
		int top = stack.pop();
		insertAtBottom(stack, data);
		stack.push(top);
		
	}
	
	public static void main(String[] args) 
	{
		Stack<Integer> stack = new Stack<Integer>();
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);
		stack.push(6);
		stack.push(7);
		stack.push(8);
		
		reverseStack(stack);
		for (Integer integer : stack) 
		{
			System.out.println(integer);
		}
	}

}
