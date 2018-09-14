package lecture8;

import java.util.ArrayList;

public class bubblesort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array = { 5, 2, 3, 4, 1 };
		int[] array2={5,2,3};
		//bsort(array);
		isort(array);
		lecture6.arrays.display(array);
		System.out.println(binarysearch(array,5));
		ArrayList<Integer> n=new ArrayList<Integer>();
		n=intersection(array,array2);
		 
		System.out.println(n);
	}

	public static void bsort(int[] array)
	{
		int counter=1;
		while(counter<=array.length)
		{
			for(int i=0;i<array.length-counter;i++)
			{
				if(array[i+1]<array[i])
				{
					int temp=array[i+1];
					array[i+1]=array[i];
					array[i]=temp;
				}
					
			}
			counter++;
		}
	}
	public static void ssort(int[] array)
	{
		int counter=1;
		while(counter<=array.length)
		{
			for(int i=counter;i<=array.length-1;i++)
			{
				if(array[i]<array[counter-1])
				{
					int temp=array[i];
					array[i]=array[counter-1];
					array[counter-1]=temp;
				}
					
			}
			counter++;
		}
	}
	public static void isort(int[] array)
	{
		int counter=1;
		while(counter<=array.length-1)
		{
			for(int i=counter;i>0;i--)
			{
				if(array[i]<array[i-1])
				{
					int temp=array[i];
					array[i]=array[i-1];
					array[i-1]=temp;
				}
				else
					break;
					
			}
			counter++;
		}
	}
	public static int binarysearch(int[] array,int key)
	{
		int start=0,end=array.length-1,mid=(start+end)/2;
		while(start<=end)
		{
			if(array[mid]==key)
				return mid;
			if(array[mid]<key)
			{
				start=mid+1;
				mid=(start+end)/2;
			}
			if(array[mid]>key)
			{
				end=mid-1;
				mid=(start+end)/2;
			}
		}
		return -1;
	}
	public static ArrayList<Integer> intersection(int[] array1,int[] array2)
	{
		ArrayList<Integer> nlist=new ArrayList<Integer>();
		isort(array1);
		isort(array2);
		for(int i=0,j=0;i<array1.length-1||j<array2.length-1;)
		{
			
			if(array1[i]==array2[j])
			{
						nlist.add(array1[i]);
						i++;j++;
			}
			if(array1[i]>array2[j])
			{
						j++;
			}
			if(array1[i]<array2[j])
			{
						i++;
			}
		}
		return nlist;
		
	}
	

}
