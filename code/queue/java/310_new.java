package tests;
import utils.Queue;


public class Queue_Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue<Integer> queue = new Queue<Integer>();
		System.out.println(queue);
		queue.enqueue(1);System.out.println(queue);
		queue.enqueue(2);System.out.println(queue);
		queue.enqueue(3);System.out.println(queue);
		queue.enqueue(4);System.out.println(queue);
		queue.dequeue();System.out.println(queue);
		queue.dequeue();System.out.println(queue);
		queue.dequeue();System.out.println(queue);
		queue.dequeue();System.out.println(queue);

	}

}
