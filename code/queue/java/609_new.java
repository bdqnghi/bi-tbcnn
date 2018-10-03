package com.srikanth.datastructures;

import org.junit.Test;

public class QueueDemoTest {

	@Test
	public void testenQueue() {
	       QueueDemo.enQueue(10);
	       QueueDemo.enQueue(20);
	       QueueDemo. enQueue(30);
	       QueueDemo.enQueue(40);
	       QueueDemo. enQueue(50);
	       QueueDemo. display();
	}
	@Test
	public void testDeQueue() {
		QueueDemo. enQueue(10);
		QueueDemo. enQueue(20);
		QueueDemo.enQueue(30);
		QueueDemo.enQueue(40);
		QueueDemo.enQueue(50);
		QueueDemo.display();
		QueueDemo.deQueue();
		QueueDemo.deQueue();
		QueueDemo.deQueue();
		QueueDemo.display();
	}

}
