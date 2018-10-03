
public class Heapsort {
	private int[] heap;
	private int length;
	private int comparison;
	private int exchange;
	
	public Heapsort(int[] array)
	{
		comparison = exchange = 0;
		heap = array;
	    length = array.length;
	    makeHeap();
	}
	
	public void makeHeap()
	{
		for(int i = 1; i<length; i++)
	    {
	    	Upheap(i);
	    }
	}
	
	public void Upheap(int i)
	{
		int j;
		int temp;
		while(i >= 1)
		{
			j = i/2;
			
			if(heap[i] <= heap[j])
			{
				return;
			}
			
			temp = heap[i];
			heap[i] = heap[j];
			heap[j] = temp;
			i = j;
		}
	}
	
	public void Downheap(int size)
	{
		int i = 0;
		int j = 1;
		int temp;
		comparison++;
		while(i<=length)
		{
			comparison++;
			j = (j*2);
			comparison++;
			if(j > length-1 || j >= size)
			{
				if(!(j>length-1))
				{
					comparison++;
				}
				comparison++;
				if(heap[i]>heap[size])
				{
					temp = heap[i];
					exchange++;
					heap[i] = heap[size];
					exchange++;
					heap[size] = temp;
					exchange++;
				}
				return;
			}
			
			
			if((i < length) && (heap[j] > heap[j-1]))
			{
				comparison += 2;
				temp = heap[i];
				exchange++;
				heap[i] = heap[j];
				exchange++;
				heap[j] = temp;
				exchange++;
				i = j;
				j++;
			}else if((i < length) && (heap[j] < heap[j-1])){
				comparison += 4;
				temp = heap[i];
				exchange++;
				heap[i] = heap[j-1];
				exchange++;
				heap[j-1] = temp;
				exchange++;
				i = j-1;
			}else{
				comparison += 4;
				return;
			}
		}
	}
	
	public int[] heapsort()
	{
		comparison++;
		for(int i = length-1; i>=2; i--)
		{
			comparison++;
			int temp = heap[0];
			exchange++;
			heap[0] = heap[i];
			exchange++;
			heap[i] = temp;
			exchange++;
			Downheap(i);
		}
		return heap;
	}
	
	public int[] data()
	{
		int data[] = new int[2];
		data[0] = comparison;
		data[1] = exchange;
		return data;
	}
}
