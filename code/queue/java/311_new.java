package org.sooo.datastructure;

import org.junit.Test;

public class QueueTest {

	@Test
	public void enqueue() {
		Queue queue = new Queue();
		System.out.println(queue);
		for (int i = 0; i < 3; i++) {
			queue.enqueue(i);
			System.out.println("queue: " + queue);
		}
	}

	@Test
	public void dequeue() {
		Queue queue = new Queue();
		for (int i = 0; i < 3; i++)
			queue.enqueue(i);
		System.out.println("queue: " + queue);

		for (int i = 0; i < 3; i++) {
			System.out.println("dequeued: " + queue.dequeue());
			System.out.println("queue: " + queue);
		}
	}
}
