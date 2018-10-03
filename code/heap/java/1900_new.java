package heap;

/**
 * Created by insidious on 3/6/16.
 */
public class Heap_Main {

    public static void main(String [ ] args) {
        Heap heap = new Heap();
        heap.insert(10);
        heap.insert(2);
        heap.insert(8);
        heap.insert(4);
        heap.insert(18);
        heap.insert(20);
        heap.insert(3);
        heap.insert(16);
        heap.insert(5);
        heap.dumpheap();


        //HeapSort
        int tmp, i;
        i = 0;
        int[] sorted = new int[12];
        tmp = heap.extract_max();
        heap.dumpheap();
        while(tmp != 0){
            sorted[i] = tmp;
            i++;
            tmp = heap.extract_max();
            heap.dumpheap();
        }
        System.out.println("Sorted Array");
        for(int j =0; j < sorted.length; j++){
            System.out.print( " "+sorted[j]+",");
        }


    }
}
