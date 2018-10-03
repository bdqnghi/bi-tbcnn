// MinMaxHeap 클래스 테스트
public class MinMaxHeapTest
{
	public static void main(String[] args){
		MinMaxHeap heap= new MinMaxHeap(10);
		heap.insert(6);
		heap.insert(81);
		heap.insert(87);
		heap.insert(14);
		heap.insert(17);
		heap.insert(12);
		heap.insert(28);
		heap.insert(71);
		heap.insert(25);
		heap.insert(80);
		heap.insert(20);
		heap.insert(52);
		heap.insert(78);
		heap.insert(31);
		heap.insert(42);
				
		System.out.println(heap);
		System.out.println("Max: " + heap.max() + " Min: " + heap.min());
		System.out.println("------------------------------------------");
		System.out.println("Min Deleted: " + heap.deleteMin());
		System.out.println(heap);
		System.out.println("Min Deleted: " + heap.deleteMin());
		System.out.println(heap);
		System.out.println("Min Deleted: " + heap.deleteMin());
		System.out.println(heap);
		System.out.println("Max Deleted: " + heap.deleteMax());
		System.out.println(heap);
		System.out.println("Max Deleted: " + heap.deleteMax());
		System.out.println(heap);
		System.out.println("Max Deleted: " + heap.deleteMax());
		System.out.println(heap);
		System.out.println("------------------------------------------");
	}
}
