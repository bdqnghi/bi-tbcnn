
public class HeapFunction {
public int [] heapify(int[] heap, int i, int mode)
{
	int temp;
	if(i<0)
		return heap;
	if (2*i +1 < heap.length-mode)
	{	
		if(2*i +2 < heap.length-mode && heap[2*i+2]>heap[i] && heap[2*i+2]>heap[2*i+1])
		{
			temp = heap[2*i+2];
			heap[2*i+2] = heap[i];
			heap[i] = temp;
			heap = heapify(heap, 2*i+2, mode);
		}
		else if(heap[2*i+1]>heap[i])
		{
			temp = heap[2*i+1];
			heap[2*i+1] = heap[i];
			heap[i] = temp;
			heap = heapify(heap, 2*i+1,mode);
		}
		i--;
		return heapify(heap, i,mode);
	}
	else
	{
		return heap;
	}
}

public int [] alteration(int heap[], int i)
{
	int temp;
	if(i <= 0)
		return heap;
	else 
	{
		int index = (i%2==0)? (i-2)/2 : (i-1)/2 ; 
		if(heap[index]>heap[i])
		{
			temp = heap[index];
			heap[index] = heap[i];
			heap[i] = temp;
			heap = alteration(heap, index);
		}
	}
		return heap;	
}

public int[] sortarray(int heap[])
{
	int index;
	int temp;
	int i;
	for(i=0;i<heap.length-1;i++)
	{
		if((heap.length-i)%2==1)
		{
			index = (heap.length-1-i)/2 - 1;
		}
		else
		{
			index = (heap.length-1-i)/2;
		}
		heap = heapify(heap, index,i);
		temp = heap[0];
		heap[0] = heap[heap.length-1-i];
		heap[heap.length-1-i] = temp;
	}
	return heap;
}

public int [] add(int heap[], int element)
{
	int []newheap = new int [heap.length +1];
	for(int i=0;i<heap.length;i++)
	{
		newheap[i] = heap[i];
	}
	newheap[heap.length] = element;
	
	newheap = alteration(newheap, heap.length);
	newheap = sortarray(newheap);
	return newheap;
}
}
