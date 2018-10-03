package chapter9;

public class chapter9 {
	public static void main(String[] args) {
		Heap heap = new Heap(100);
		heap.enqueue("c");
		heap.enqueue("e");
		heap.enqueue("d");
		heap.enqueue("a");
		heap.enqueue("u");
		heap.enqueue("i");
		heap.enqueue("g");
		heap.enqueue("j");
		heap.enqueue("r");
		heap.enqueue("p");
		heap.enqueue("t");
		heap.enqueue("e");
		heap.enqueue("y");
		heap.enqueue("o");
		heap.enqueue("z");
		heap.enqueue("n");
		heap.enqueue("b");
		heap.show();
		heap.dequeue();
		heap.show();
		heap.dequeue();
		heap.show();
		heap.dequeue();
		heap.show();
		heap.makeEmpty();
		heap.enqueue(1);
		heap.enqueue(8);
		heap.enqueue(5);
		heap.enqueue(6);
		heap.enqueue(2);
		heap.enqueue(3);
		heap.enqueue(4);
		heap.enqueue(7);
		heap.enqueue(9);
		heap.show();
		heap.dequeue();
		heap.show();
		heap.dequeue();
		heap.show();
		heap.dequeue();
		heap.show();

	}
}
