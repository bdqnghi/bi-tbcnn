package com.nikul.javapractice.queue;

public class TestQueue {

	public static void main(String[] args){
		QueueImpl q = new QueueImpl();
		
		q.queuePush(3);
		q.queuePush(4);
		q.queuePush(5);
		q.queuePush(6);
		q.queuePush(7);
		q.queuePush(8);
		q.queuePush(9);
		
		q.showQueue();
		
		System.out.println(q.queuePull());
		System.out.println(q.queuePull());
		System.out.println(q.queuePull());
		System.out.println(q.queuePull());
		q.queuePush(3);
		q.queuePush(4);
		q.queuePush(5);
		q.queuePush(6);
		
		q.showQueue();
	}
}
