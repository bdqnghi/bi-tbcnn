package Lab02;

/**
 *
 * @author Somsubhra(201101056)
 */
public class BinaryHeapTester {
    
    public static void main(String[] args){
        BinaryHeap heap = new BinaryHeap();
        
        heap.add(1);
        heap.add(2);
        heap.add(3);
        heap.add(4);
        heap.add(5);
        heap.add(6);
        heap.add(7);
        heap.add(8);
        heap.add(9);
        heap.add(10);
        System.out.println(heap.leftChildOf(2));
        System.out.println(heap.rightChildOf(2));
        System.out.println(heap.leftChildOf(4));
        System.out.println(heap.rightChildOf(4));
        System.out.println(heap.leftChildOf(5));
        System.out.println(heap.rightChildOf(5));
        System.out.println(heap.parentOf(4));
        System.out.println(heap.parentOf(6));
        System.out.println(heap.parentOf(7));
        
        
    }
    
}
