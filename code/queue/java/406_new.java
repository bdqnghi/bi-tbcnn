package com.srikanth.datastructures;

import org.junit.Test;


public class CircularQueueDemoTest {

	@Test
	public void testenQueue() {
		
		CircularQueueDemo.enQueue(10);
		CircularQueueDemo.enQueue(20);
		CircularQueueDemo. enQueue(30);
		CircularQueueDemo.enQueue(40);
		CircularQueueDemo.enQueue(50);
		CircularQueueDemo.display();
	}
	@Test
	public void testdeQueue() {
		CircularQueueDemo.deQueue();
		CircularQueueDemo.deQueue();
		CircularQueueDemo.deQueue();
		CircularQueueDemo.display();
	}
}
