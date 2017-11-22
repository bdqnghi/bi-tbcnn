package Sort;

import java.util.Arrays;

public class bubblesort {

	public static void main(String[] args) {
		int[] arr = new int[]{5,7,1,6,8,3,2,4};
		
		
		dobubblesort(arr);
		
		System.out.println(Arrays.toString(arr));
	}
	
	private static void dobubblesort(int[] myarr)
	{
		for(int i = 0;i<myarr.length;i++)
		{
			for(int j = 1;j<myarr.length-i;j++)
			{
				if(myarr[j-1]>myarr[j])
				{
					swap(myarr,j-1,j);
				}	
			}
		}
	}
	
	private static void swap(int[] myarr, int i, int j) 
	{
		int temp = myarr[i];
		myarr[i] = myarr[j];
		myarr[j] = temp;		
	}
}
