package ds;

public class Stack {
	private Node top;
	
	public Stack(int data)
	{
		top = new Node();
		top.setData(data);
		top.setPrevious(null);
	}
	
	public void push(int data)
	{
		Node temp = new Node();
		temp.setData(data);
		temp.setPrevious(top);
		top = temp;
	}
	
	public boolean empty()
	{
		if(top == null)
			return true;
		else
			return false;
	}
	
	public int pop()
	{
		int temp = top.getData();
		top = top.getPrevious();
		
		return temp;
	}
	
	public int peek(){
		return top.getData();
	}
	

}
