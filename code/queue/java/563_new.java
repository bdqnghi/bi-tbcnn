public class Test {
	public static void main(String[] args) {
		testArrayQueue();
		testArrayQueueSingleton();
		testArrayQueueADT();
	}
	
	public static void testArrayQueue() {
		System.out.println("Test ArrayQueue");
		ArrayQueue queue = new ArrayQueue(10);
                for (int i = 0; i < 16; i++) {
                        queue.push(i);
                }
		System.out.println("Array queue elements:");
                queue.printQueue();
		for (int i = 0; i < 4; i++) {
                	queue.pop();
                }
		System.out.println("Array queue after extracting elements:");
                queue.printQueue();
                System.out.println("Is queue empty: " + queue.isEmpty() + " Queue size: " + queue.size());
	}

	public static void testArrayQueueSingleton() {
		System.out.println("Test ArrayQueueSingleton");
		for (int i = 0; i < ArrayQueueSingleton.MAX_SIZE; i++) {
                        ArrayQueueSingleton.push(i);
                }
                System.out.println("Array queue singleton elements: ");
                ArrayQueueSingleton.printQueue();
		for (int i = 0; i < 3; i++) {
                	ArrayQueueSingleton.pop();
		}
                System.out.println("Array queue singleton after extracting elemetns:");
                ArrayQueueSingleton.printQueue();
		System.out.println("Is queue empty: " + ArrayQueueSingleton.isEmpty() + " Queue size: " + ArrayQueueSingleton.size());
	}

	public static void testArrayQueueADT() {
		System.out.println("Test ArrayQueueADT");
		ArrayQueueADT queue = new ArrayQueueADT(14);
                for (int i = 0; i < 14; i++) {
                        ArrayQueueADT.push(queue, i);
                }
		System.out.println("Array queue ADT elements:");
                ArrayQueueADT.printQueue(queue);
                for (int i = 0; i < 14; i++) {
                        ArrayQueueADT.pop(queue);
                }
		System.out.println("Array queue ADT after extracting elements:");
                ArrayQueueADT.printQueue(queue);
                System.out.println("Is queue empty: " + ArrayQueueADT.isEmpty(queue) + " Queue size: " + ArrayQueueADT.size(queue));
	}
}
