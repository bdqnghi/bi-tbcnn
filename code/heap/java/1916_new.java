package hust.idc.util.heap.test;

import hust.idc.util.heap.BinaryHeap;

public class TestBinaryHeap extends TestHeap {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinaryHeap<Integer> heap = new BinaryHeap<Integer>(comp);
		
		init(heap, HEAP_SIZE);
		printSorted(heap.clone());
		
		System.out.println("Extract Max: " + heap.poll());
		printSorted(heap.clone());
		
		System.out.println("Heap Contains Element 35? " + heap.contains(35));
		System.out.println("Heap Contains Element 100? " + heap.contains(100));

		heap.decreaseElement(35, 30);
		System.out.println("Decrease : 35 �� 30 " + heap);
		printSorted(heap.clone());
		
		heap.increaseElement(35, 40);
		System.out.println("Increase : 35 �� 40 " + heap);
		printSorted(heap.clone());
		
		heap.remove(30);
		System.out.println("Remove : 30 " + heap);
		printSorted(heap.clone());
		
		System.out.println("Heap Contains Element 30? " + heap.contains(30));
		System.out.println("Heap Contains Element 100? " + heap.contains(100));
		
		testSerialization(heap);
		
		heap.clear();
		System.out.println("Clear: " + heap);
		printSorted(heap);
	}

}
