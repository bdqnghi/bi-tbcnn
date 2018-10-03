public class TestHeap{

	public static void main(String[] args){
		Heap<Integer> heap = new Heap<Integer>();


		//Testing add method
		heap.add(1);
		heap.add(5);
		heap.add(1);
		heap.add(25);
		heap.add(33);
		heap.add(2);
		heap.add(3);
		heap.add(44);

		Integer i = new Integer(45);
		heap.add(i);

		System.out.println("Printing Heap After Adds\n" + heap);

		//Testing poll method
		heap.poll();
		System.out.println(heap);

		heap.poll();
		System.out.println(heap);

		heap.poll();
		System.out.println(heap);

		heap.poll();
		System.out.println(heap);

		//Testing remove method

		heap.remove(i);
		System.out.println("Printing Heap After Remove\n" + heap);


	}

}