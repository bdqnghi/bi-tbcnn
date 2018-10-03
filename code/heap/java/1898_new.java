import java.util.*;

public class MyHeap{
    
    private int[] heap;
    private boolean mode;
    
    public MyHeap(){
	heap=new int[10];
	heap[0]=0;
	mode=true;
    }
    
    public MyHeap(boolean isMax){
	heap=new int[10];
	heap[0]=0;
	mode=isMax;
    }

    public void add(int val){
	if(heap[0]==0){
	    heap[1]=val;
	    heap[0]++;
	}else{
	    checkSize();
	    if(mode){
		if(heap[(heap[0]+1)/2] > val){
		    heap[heap[0]+1]=val;
		    heap[0]++;
		}else{
		    checkParent(heap[0]+1,val);
		    heap[0]++;
		}
	    }else{
		if(heap[(heap[0]+1)/2] < val){
		    heap[heap[0]+1]=val;
		    heap[0]++;
		}else{
		    checkParent(heap[0]+1,val);
		    heap[0]++;
		}
	    }
	}
    }
    
    public void checkParent(int pos,int val){
	if(pos==1){
	    heap[heap[0]+1]=heap[1];
	    heap[1]=val;
	    checkOrder(2);
	    checkOrder(3);
	}else if(mode){
	    if(heap[pos/2] > val){
		heap[heap[0]+1]=heap[pos];
		heap[pos]=val;
		checkOrder(2*pos);
		checkOrder(2*pos+1);
	    }else{
		checkParent(pos/2,val);
	    }
	}else{
	    if(heap[pos/2] < val){
		heap[heap[0]+1]=heap[pos];
		heap[pos]=val;
		checkOrder(2*pos);
		checkOrder(2*pos+1);
	    }else{
		checkParent(pos/2,val);
	    }
	}
    }
    
    public void checkOrder(int pos){
	if(2*pos<=heap[0]){
	    if(mode){
		if(heap[pos]<heap[2*pos]){
		    swap(2*pos);
		}
		if(pos*2+1<=heap[0]){
		    if(heap[pos]<heap[2*pos+1]){
			swap(2*pos+1);
			checkOrder(pos);
		    }
		}
	    }else{
		if(heap[pos]>heap[2*pos]){
		    swap(2*pos);
		}
		if(pos*2+1<=heap[0]){
		    if(heap[pos]>heap[2*pos+1]){
			swap(2*pos+1);
			checkOrder(pos);
		    }
		}
	    }		    
	    checkOrder(2*pos);
	    checkOrder(2*pos+1);
	}
    }
    
    public void swap(int pos){
	int temp=heap[pos];
	heap[pos]=heap[pos/2];
	heap[pos/2]=temp;
    }

    public int remove(){
	int root=heap[1];
	heap[1]=heap[heap[0]];
	heap[0]--;
	checkOrder(1);
	return root;
    }
	    
    public int peek(){
	return heap[1];
    }

    public void checkSize(){
	if(heap.length==heap[0]+2){
	    resize(true);
	}else if(heap.length/4>=heap[0]){
	    resize(false);
	}
    }
    
    public void resize(boolean k){
	int[] newHeap;
	if(k){
	    newHeap=new int[2*heap.length];
	}else{
	    newHeap=new int[heap.length/2];
	}
	for(int i=0;i<=heap[0]+1;i++){
	    newHeap[i]=heap[i];
	}
	heap=newHeap;
    }

    public String toString(){
	String data="Size: "+heap[0]+"\n";
	for(int i=1;i<=heap[0];i++){
	    // System.out.println(heap[i]);
	    data+=heap[i]+" ";
	}
	return data;
    }

    public static void main(String[]args){
	MyHeap f = new MyHeap(false);
	Random r=new Random();
	for(int i=0;i<15;i++){
	    f.add(r.nextInt(9)+1);
	}
	System.out.println(f.toString());
    }
}
