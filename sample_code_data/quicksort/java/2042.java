package algo;

public class quicksort {

	
	public static void main(String[] args){
		long start,end;
		
		int[] s0 = {1,2,3};
		int[] s1 = {1,2,3,4,5};
		int[] s2 = {1,2,3,4,5,6,8};
		int[] s3 = {1,2,3,4,5,6,7,8,9,10};
		int[] s4 = {1,2,3,4,5,6,7,8,9,10,11,12,13};
		int[] s5 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
		int[] s6 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
		int[] s7 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		int[] s8 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
		int[] s9 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
		
		start = System.nanoTime();
		qsort(s0,0,s0.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		qsort(s1,0,s1.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));

		start = System.nanoTime();
		qsort(s2,0,s2.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		qsort(s3,0,s3.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		qsort(s4,0,s4.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		qsort(s5,0,s5.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		qsort(s6,0,s6.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		qsort(s7,0,s7.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		qsort(s8,0,s8.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		qsort(s9,0,s9.length-1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
	}
	
	static int partition(int arr[], int left, int right)
	{
	      int i = left, j = right;
	      int tmp;
	      int pivot = arr[(left + right) / 2];
	     
	      while (i <= j) {
	            while (arr[i] < pivot)
	                  i++;
	            while (arr[j] > pivot)
	                  j--;
	            if (i <= j) {
	                  tmp = arr[i];
	                  arr[i] = arr[j];
	                  arr[j] = tmp;
	                  i++;
	                  j--;
	            }
	      };
	     
	      return i;
	}
	 
	static void qsort(int arr[], int left, int right) {
		
	      int index = partition(arr, left, right);
	      if (left < index - 1)
	            qsort(arr, left, index - 1);
	      if (index < right)
	            qsort(arr, index, right);
	      
	}
	
	}