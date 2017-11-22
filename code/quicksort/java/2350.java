package PV;

import java.util.Arrays;
import java.util.Scanner;

public class Quicksort {

	public static void main(String[]args){
		Scanner s = new Scanner(System.in);
		static int count = 0;
		int n = s.nextInt();
		
		int[]array = new int[n];
		
		for(int i = 0; i<n; i++){
			array[i] = s.nextInt();
		}
		
		System.out.println(Arrays.toString(array));
		
		int l = 0;
		int r = n-1;

		System.out.println("l: " + l + " r: " + r);
		quicksort(array,l,r);
		
		
	}
	
	public static void quicksort(int[] a, int l, int r){
		while(count<n){
		int i = partition(a,l,r);
		if(i>0 && i<r){
			quicksort(a,l,i-1);
			quicksort(a,i+1,r);
		} count++;
		}
	
	}
	
	public static int partition(int[]array, int l, int r){
//		System.out.println("entering method");
		System.out.println("r: " + r);
		int pivot = array[r];
		System.out.println("pivot: " + pivot);
		int i = l;
		int j = r-1;
		System.out.println("i: " + i + " j: " + j);
		System.out.println("l: " + l + " r: " + r);
		
		
		do{
		
			while(i<r && array[i] < pivot) i++;
			while(j>l && array[j] > pivot) j--;
			
			if(i<j){
				System.out.println("SWAP " + array[i] + " " + array[j]);
				int swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				System.out.println(Arrays.toString(array));
			}
		} while(i<j);//i>=j
		
		
		System.out.println("HIER: i: " + i + "j: " + j);
		System.out.println("SWAP " + array[i] + " " + array[r]);
		if(i>=j && array[i]>array[r]){
			int swap = array[i];
		array[i] = array[r];
		array[r] = swap;
		}
		
//		System.out.println("swapped again");
		System.out.println(Arrays.toString(array));
		System.out.println("return i: " + i);
		return i;
		
	}
}
