package datastructure.heap;

public class MainHeap {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		testHeap();
	}

	
	public static void testHeap(){
		Heap heap = new Heap();
		
		heap.insertToMinHeap(15);
		heap.insertToMinHeap(11);
		heap.insertToMinHeap(27);
		heap.insertToMinHeap(3);
		heap.insertToMinHeap(9);
		heap.insertToMinHeap(58);
		heap.insertToMinHeap(22);
		heap.insertToMinHeap(1);
		heap.insertToMinHeap(17);

		boolean contain = heap.containsInMinHeap(8);
		System.out.print("Contain : " + contain + "\n" );
		
		heap.insertToMaxHeap(15);
		heap.insertToMaxHeap(11);
		heap.insertToMaxHeap(27);
		heap.insertToMaxHeap(3);
		heap.insertToMaxHeap(9);
		heap.insertToMaxHeap(58);
		heap.insertToMaxHeap(22);
		heap.insertToMaxHeap(1);
		heap.insertToMaxHeap(17);
		
		heap.printArrayMin();
		heap.printArrayMax();
		
		heap.removeFromMinHeap();
		heap.printArrayMin();
		
		heap.removeFromMaxHeap();
		heap.printArrayMax();
	}
}
