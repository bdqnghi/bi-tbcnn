package princeton.algorithms.partone;


public class BinaryHeapTester {

	/**
	 * @param This class will test BinaryHeap.
	 */
	public static void main(String[] args) {
		
		BinaryHeap binHeap = new BinaryHeap();
		binHeap.insert(5);
		binHeap.insert(20);
		//binHeap.printHeap();
		binHeap.insert(1);
		binHeap.insert(10);
		//binHeap.printHeap();
		binHeap.insert(4);
		//binHeap.printHeap();
		binHeap.insert(8);
		//binHeap.printHeap();
		binHeap.insert(3);
		//binHeap.printHeap();
		binHeap.delMax();
//		binHeap.delMax();
		binHeap.delMax();
		binHeap.delMax();
		binHeap.delMax();
		binHeap.delMax();
		binHeap.delMax();
		binHeap.delMax();
	}

}
