package dsa.annotated;
public class TestHeap extends TestingClass {
	public static void main(String[] args) {
		new TestHeap().runAllTest();
	}

	public void testAdd() {
		Heap heap = new Heap();
		heap.add(23);
		heap.add(7);
		assert "[7, 23]".equals(heap.toString()) : "add 1 failed:"
				+ heap.toString();
		heap.add(6);
		assert "[6, 23, 7]".equals(heap.toString()) : "add 2 failed:"
				+ heap.toString();
		heap.add(5);
		assert "[5, 6, 7, 23]".equals(heap.toString()) : "add 3 failed:"
				+ heap.toString();
	}

	public void testRemove() {
		Heap heap = buildHeap();
		// heap should be like this now
		assert "[5, 6, 7, 23, 8, 9, 11]".equals(heap.toString());
		heap.remove(5);
		assert "[6, 8, 7, 23, 11, 9]".equals(heap.toString());

	}
	
	public void testContains() {
		Heap heap = buildHeap();
		assert heap.contains(23) : "contains 23";
		assert !heap.contains(66) : "contains 66";
	}

	public void testIndexOf() {
		Heap heap = buildHeap();
		assert heap.indexOf(9) == 5 : "indexOf 9";
		assert heap.indexOf(5) == 0 : "indexOf 5";
		assert heap.indexOf(7) == 2 : "indexOf 7";
	}

	public void testGetParent() {
		Heap heap = buildHeap();
		assert heap.getParent(heap.indexOf(23)) == 1 : "getParent 23";
		assert heap.getParent(heap.indexOf(5)) == 0 : "getParent 5";
		assert heap.getParent(heap.indexOf(11)) == 2 : "getParent 11 ";
		assert heap.getParent(heap.indexOf(7)) == 0 : "getParent 7";
	}

	public void testGetLeftChild() {
		Heap heap = buildHeap();
		assert heap.getLeftChild(heap.indexOf(6)) == 3 : "left child 6";
		assert heap.getLeftChild(heap.indexOf(5)) == 1 : "left child 5";
		assert heap.getLeftChild(heap.indexOf(7)) == 5 : "left child 7";
	}

	public void testSwap() {
		Heap heap = new Heap();
		// test without testing add
		heap.graph.add(3);
		heap.graph.add(4);
		heap.swap(0, 1);

		assert heap.graph.get(0).equals(4) : "swap 1";
		assert heap.graph.get(1).equals(3) : "swap 2";
	}

	private Heap buildHeap() {
		Heap heap = new Heap();
		heap.add(23);
		heap.add(7);
		heap.add(6);
		heap.add(5);
		heap.add(8);
		heap.add(9);
		heap.add(11);
		return heap;
	}
}
