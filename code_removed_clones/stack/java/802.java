package important;

public class Stack {

	private int size;
	private long[] stackElements;
	private int top;
	Stack(int x){
		size=x;
		stackElements=new long[size];
		top=-1;
	}
	public void push(long value){
		stackElements[++top]=value;
	}
	public long pop(){
		return stackElements[top--];
	}

	public boolean isEmpty(){
		return (top==-1);
		
	}
	public static void main(String[] args) {

		Stack s=new Stack(10);
		s.push(20);
		s.push(24);
		s.push(35);
		while(s.isEmpty()){
			long value=s.pop();
	   System.out.println(value);
			System.out.println(s.pop());
	}

}
}
 






























