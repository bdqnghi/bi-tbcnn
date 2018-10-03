package wiki.tests;

import wiki.util.Heap;

public class TestHeap {
	Heap heap;
	TestHeap(int size) {
		heap = new Heap(size);
	}

	public void buildHeap() {
		heap.add(1, 1);
		heap.add(2, 3);
		heap.add(3, 6);
		heap.add(4, 5);
		heap.add(5, 9);
		heap.add(6, 8);
	}

	public void printHeap() {
		heap.printHeap();
	}

	public int testAddNode(int id, int priority) {
		return heap.add(id, priority);
	}

	public int testeExtractMin() {
		return heap.extractMin();
	}

	public int testGetSize() {
		return heap.maxSize();
	}

	public boolean testIsFull() {
		return heap.isFull();
	}

	public boolean testIsEmpty() {
		return heap.isEmpty();
	}

	public boolean testDecreasePriority(int id, int priority) {
		return heap.decreasePriority(id, priority);
	}




}
