package myclasses.demos.ds.stack.queue;

public class QueueFromStackApp {
	public static void main(String[] args) {

		QueueFromStack queue = new QueueFromStack(5);
		queue.enQueue(1);
		queue.enQueue(2);
		queue.enQueue(3);
		queue.enQueue(4);
		queue.enQueue(5);
		queue.displayQueue();
		queue.deQueue();
		queue.deQueue();
		queue.displayQueue();
		queue.enQueue(6);
		queue.displayQueue();
		queue.deQueue();
		queue.deQueue();
		queue.deQueue();
		queue.deQueue();
		queue.displayQueue();

		System.out.println("*************************");
		
		queue.enQueueOptimzed(1);
		queue.enQueueOptimzed(2);
		queue.enQueueOptimzed(3);
		queue.enQueueOptimzed(4);
		queue.enQueueOptimzed(5);
		queue.displayQueue();
		queue.deQueueUnOptimized();
		queue.deQueueUnOptimized();
		queue.displayQueue();
		queue.deQueueUnOptimized();
		queue.enQueueOptimzed(6);
		queue.displayQueue();
		
	}
}
