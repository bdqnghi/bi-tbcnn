
public class Heap{

    private int[] heap;
    private int size;
    //insert?
    
    public Heap(int n){
	heap = new int[n];
	size = 0;
    }
    
    public Heap(int[] a){
       	heap = a;
	size = a.length;
    }
    
    public int getSize(){
	return size;
    }
    
    public int[] getHeap(){
        return heap;
    }
    
    public void insert(int n){
	int x = size + 1;
	heap[x] = n;
	while (x > 1 && heap[x] >= heap[x/2]){
	    int temp = heap[x];
	    heap[x] = heap[x/2];
	    heap[x/2] = temp;
	    x = x/2;
	}
	size ++;
    }

}
