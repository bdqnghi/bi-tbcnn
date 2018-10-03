
package quicksort;

public class Heap {
    Heap(){
}
    public void Heap(int array[], int max){
	    int i, o;
	        int lChild, rChild, mChild, root, temp;
	    root = (max-1)/2;

	    for(o = root; o >= 0; o--){
	      for(i=root;i>=0;i--){
	        lChild = (2*i)+1;
	                rChild = (2*i)+2;
	        if((lChild <= max) && (rChild <= max)){
	          if(array[rChild] >= array[lChild])
	            mChild = rChild;
	          else
	            mChild = lChild;
	        }
	                else{
	          if(rChild > max)
	            mChild = lChild;
	          else
	            mChild = rChild;
	        }

	        if(array[i] < array[mChild]){
	          temp = array[i];
	          array[i] = array[mChild];
	                    array[mChild] = temp;
	        }
	      }
	    }
	    temp = array[0];
	    array[0] = array[max];
	    array[max] = temp;
	    return;
	  }
}


