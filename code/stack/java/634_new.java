public class StackDriver{

    public static void main(String[] args){
	MyStack2 stack = new MyStack2();
	stack.push("1");
	stack.push("2");
	stack.push("3");
	stack.push("4");
	stack.push("5");
	stack.push("6");
	stack.push("7");
	stack.push("8");
	stack.push("9");
	stack.push("10");
	stack.push("11");
	stack.push("12");
	stack.push("13");
	stack.push("14");
	stack.push("15");
	stack.push("16");
	stack.push("17");
	stack.push("18");
	stack.push("19");
	stack.push("20");
	stack.push("21");
	stack.push("22");
	stack.push("23");
	System.out.println(stack);
	while(!(stack.isEmpty())){
	System.out.println(stack.pop());
	}
	
	stack.push("hello");
	System.out.println(stack.peek());
	stack.push("world");		
	System.out.println(stack.peek());
	stack.push("two");
	System.out.println(stack);



    }

}