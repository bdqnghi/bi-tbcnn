package heap;

public class HeapTest {
	public static void main(String[] args) {
		testHeap();
	}

	public static void testHeap() {
		Heap heap = new Heap(31);

		heap.insert(70);
		heap.insert(40);
		heap.insert(50);
		heap.insert(20);
		heap.insert(60);
		heap.insert(100);
		heap.insert(80);
		heap.insert(30);
		heap.insert(10);
		heap.insert(90);

		heap.displayHeap();

		heap.insert(53);
		heap.displayHeap();

		heap.remove();
		heap.displayHeap();

		heap.remove();
		heap.displayHeap();
	}
}
