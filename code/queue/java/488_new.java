package Chapter3StackQueue;

public class Question3_0 {

	public static void main(String[] args) {
		StackTry stack = new StackTry();
		stack.push("A");
		stack.push("B");
		stack.push("C");
		stack.display();
		stack.pop();
		stack.display();
		
		System.out.println("\n*****************Queue Test*****************\n");
		QueueTry queue = new QueueTry();
		queue.inQueue("A");
		queue.inQueue("B");
		queue.inQueue("C");
		queue.display();
		queue.deQueue();
		queue.display();
		queue.deQueue();
		queue.display();
	}

}
