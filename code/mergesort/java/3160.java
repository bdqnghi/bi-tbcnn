package algo;
import java.util.*;
public class mergesort {
	
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
		merge(s0);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		merge(s1);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));

		start = System.nanoTime();
		merge(s2);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		merge(s3);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		merge(s4);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		merge(s5);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		merge(s6);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		merge(s7);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		merge(s8);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
		
		start = System.nanoTime();
		merge(s9);
		end = System.nanoTime();
		System.out.println("수행시간 : " + (end-start));
	}
	
	public static void merge(int arr[]) {
		int m_arr [] = new int[arr.length];
		int length = arr.length;
		int a,b;
		if (length == 1) return;
		m_arr = arr;
		a= length/2; b = length-a; 
		int a_arr[] = new int[a]; int b_arr[] = new int[b];
		
		for(int i=0;i<a_arr.length;i++) {
			a_arr[i]=m_arr[i];
		}
		for(int j=0;j<b_arr.length;j++) {
			b_arr[j]=m_arr[a];
			a++;
		}
		
		merge(a_arr);
		merge(b_arr);
		mergemerge(a_arr,b_arr,m_arr);
	}
	public static void mergemerge(int arr1[],int arr2[],int arr3[]) {
		int index1=0,index2=0,index3=0;
		
		while(index1 != arr1.length && index2 != arr2.length) {
			if(arr1[index1] < arr2[index2]){
				arr3[index3]=arr1[index1];
				index3++; index1++;
			}
			else {
				arr3[index3] = arr2[index2];
				index3++; index2++;
			}
		}
		if(arr1.length == index1) {
			
			while(index2!=arr2.length) {
				arr3[index3] = arr2[index2];
				index3++; index2++;
			}
			
		}
		if(arr2.length == index2) {
			
			while(index1!=arr1.length) {
				arr3[index3] = arr1[index1];
				index3++; index1++;
			}
			
		}
	}
}
