package myclasses.demos.ds.queue;

public class QueueApp {
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		Queue queue = new Queue(4);
		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);
		queue.enqueue(4);
		queue.displayQueueEff();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.enqueue(5);
		queue.enqueue(6);
		queue.enqueue(7);
		queue.dequeue();
		queue.enqueue(8);
		queue.displayQueueEff();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.displayQueueEff();
		queue.enqueue(9);
		queue.displayQueueEff();
	}
}
