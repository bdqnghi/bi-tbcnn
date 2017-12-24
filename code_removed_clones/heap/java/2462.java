class heap<T extends Comparable>{
    private T h[];
    private int current;
    private int size;
    heap(T ax[]){
        h = ax;
        current = 1;
        size = ax.length;
        for (int i=0;i<ax.length;i++)
            insert(ax[i]);
    }
    public void insert(T i){
        if (current > size) // array size is too low
            return;
        h[current - 1] = i;
        heapify(current);
        current++;
    }
    public boolean is_empty(int i){
        return h[i-1] == 0;
    }
    public void heapsort(){
        int j=size-1;
        int k=current-1;
        for (int i=0;i<k;i++){
            //print();
            h[j] = pop_root();
            j--;
        }
    }
    public int pop_root(){
        int i = 1;
        int ret = h[0];
        h[0] = h[current-2];        
        current--;
        h[current-1] = 0;
        heapify_td(1);
        return ret;
    }
    public void heapify_td(int i){ // top down
        int j,k,l;
        if ( ((2*i+1<current) && (h[i-1].compareTo(h[2*i])<0)) || ((2*i<current) && (h[i-1].compareTo(h[2*i-1])<0)) ){
            k=i*2;
            j=i*2-1;
            
            if (h[j]==0) 
                l=k;
            else if (h[k]==0)
                l=j;
            else {
                if ( h[j].compareTo(h[k]) > 0 )
                    l=j;
                else
                    l=k;
            }
            T tmp = h[l];
            h[l] = h[i-1];
            h[i-1] = tmp;
            
            heapify_td(l+1);
        }
    }
    public void heapify(int i){ // bottom up
        int prev;
        int tmp;
        int k;
        prev = i;
        i = parent(i);
        while (i!=0){
            if (h[prev-1].compareTo(h[i-1]) > 0){
                tmp = h[i-1];
                h[i-1] = h[prev-1];
                h[prev-1] = tmp;
            }
            prev = i;
            i = parent(i);
        }
    }
    private int sibiling(int i){
        if (i%2 == 0){
            return i+1;
        } else {
            return i-1;
        }
    }
    private int parent(int i){
        if (i % 2 == 0){
            return i / 2;
        } else {
            return (i - 1)/2;
        }
    }
    public void print(){
        for (int i=0;i<size;i++)
            System.out.print(h[i]+", ");
        System.out.println();
    }
}
