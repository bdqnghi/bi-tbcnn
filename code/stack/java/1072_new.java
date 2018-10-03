package task4;

public class StackTest {

	public static void main(String[] args) {
		int size = 4;
		Stack stack = new StackImpl(size);
		
		System.out.printf("Create stack with %d elements\n", size);
		stack.printElements(stack);
		stack.push("pesho");
		stack.printElements(stack);
		stack.push(4);
		stack.push(1);
		stack.push(2);
		System.out.println("Get element: " + stack.get());
		stack.printElements(stack);
		System.out.println("Pop element: " + stack.pop());
		System.out.println("Pop element: " + stack.pop());
		stack.printElements(stack);
		System.out.println("Is stack empty? " + stack.isEmpty());
		stack.clean();
		stack.printElements(stack);
		System.out.println("Is stack empty? " + stack.isEmpty());
		System.out.println("Get element: " + stack.get());
		System.out.println("Pop element: " + stack.pop());
	}

}
