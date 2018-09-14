package com.ibm.assgnmnt;

public class Bubblesort {
	 void bubblesort(int arr[])
	    {
	        int n = arr.length;
	        for (int i = 0; i < n-1; i++)
	            for (int j = 0; j < n-i-1; j++)
	                if (arr[j] > arr[j+1])
	                {
	                    int temp = arr[j];
	                    arr[j] = arr[j+1];
	                    arr[j+1] = temp;
	                }
	    }
	 
	    void print(int arr[])
	    {
	        int n = arr.length;
	        for (int i=0; i<n; ++i)
	            System.out.print(arr[i] + " ");
	        System.out.println();
	    }		
		 public static void main(String args[])
		    {
		    	// TODO Auto-generated method stub
		        Bubblesort ob = new Bubblesort();
		        int arr[] = {4, 3, 5, 1, 2, 0, -1};
		        ob.bubblesort(arr);
		        System.out.println("Sorted array");
		        ob.print(arr);
		    }
		
	}


