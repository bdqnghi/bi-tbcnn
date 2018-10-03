package com.Queue.WrapAroundQueue;

public class QueueApp {

	public static void main(String[] args) {

		Queue theQueue = new Queue(5);

		theQueue.insert(1);
		theQueue.insert(2);
		theQueue.insert(3);
		theQueue.insert(4);

		theQueue.remove();// 1 removed
		theQueue.remove();// 2 removed
		theQueue.remove();// 3 removed

		theQueue.insert(5);
		theQueue.insert(6);
		theQueue.insert(7);
		theQueue.insert(8);

		while (!theQueue.isEmpty()) {

			int n = theQueue.remove();
			System.out.println("n = " + n);

		}

	}

}
