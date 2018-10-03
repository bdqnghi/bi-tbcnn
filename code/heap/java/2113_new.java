package com.andyp.algorithms.sorting;

import java.util.Arrays;

public class HeapSort {

	public static void main(String args[]){
		new HeapSort().run();
	}
	
	public void run(){
	
		// initial array
		int [] a = { 1, 4, 10, 8, 7, 9, 3, 2, 44, 16};
		
		Heap heap = new Heap(a, 0, a.length);
		System.out.println("Before: " + Arrays.toString(heap.a));
		
		buildHeap(heap);
		
		System.out.println("After buildHeap: " + Arrays.toString(heap.a));
		
		heapSort(heap);
		
		System.out.println("after heapSort: " + Arrays.toString(heap.a));
		
		
	}
	

	
	private void heapSort(Heap heap){
		buildHeap(heap);
		
		for(int i=heap.length -1; i > 2; i--){
			int tmp = heap.a[1];
			heap.a[1] = heap.a[i];
			heap.a[i] = tmp;
			heap.heapSize--;
			maxHeapify(heap, 1);
		}
	}
	
	private void buildHeap(Heap heap){
		heap.heapSize = heap.length - 1;
		
		int mid = Double.valueOf(Math.floor(heap.heapSize/2)).intValue();
		
		for(int i = mid; i > 0; i--){
			maxHeapify(heap, i);
		}
		
	}
	
	private void maxHeapify(Heap heap, int i){
		int l = left(i);
		int r = right(i);
		int largest = -1;
		
		if(l <= heap.heapSize && heap.a[l] > heap.a[i])
			largest = l;
		else
			largest = i;
		
		if( r <= heap.heapSize && heap.a[r] > heap.a[largest])
			largest = r;
		
		if(largest != i){
			// swap a[i] with a[largest]
			int tmp = heap.a[i];
			heap.a[i] = heap.a[largest];
			heap.a[largest] = tmp;
			
			maxHeapify(heap, largest);
		}
		
	}
	
	private int parent(int i){
		return Double.valueOf(Math.floor(i/2)).intValue();
	}
	
	private int left(int i){
		return i<<1;
	}
	
	private int right(int i){
		return (i<<1) +  1;
	}
	
	class Heap{
		public int [] a;
		public int heapSize;
		public int length;
		
		public Heap(int [] arr, int heapSize, int length){
			this.a = arr;
			this.heapSize = heapSize;  // number of elements in heap
			this.length = length;		// number of elements in array
		}
	}

}
