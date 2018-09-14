package practise.programs;

import java.util.Scanner;

public class Quicksort 
{
	
	static void display(int arr[],int low,int up)
	{
	int i;
	for(i=low;i<=up;i++)
	System.out.print(arr[i]+"  ");
	}
	static void quick(int arr[],int low,int up)
	{
	int piv,temp,left,right;
	 boolean pivot_placed=false;
	//setting the pointers
	System.out.println("low : "+low+" up :  "+up);
	left=low;
	right=up;
	piv=low; /*Take the first element of sublist as piv */
	if (low>=up)
	return;
	System.out.println("sub list : ");
	display(arr,low,up);
	/*Loop till pivot is placed at proper place in the sublist*/
	while(pivot_placed==false)
	{
	/*Compare from right to left  */
	while( arr[piv]<=arr[right] && piv!=right )
	right=right-1;
	if ( piv==right )
	      pivot_placed=true;
	if ( arr[piv] > arr[right] )
	{
	temp=arr[piv];
	arr[piv]=arr[right];
	arr[right]=temp;
	piv=right;
	}
	/*Compare from left to right */
	while( arr[piv]>=arr[left] && left!=piv )
	left=left+1;
	if (piv==left)
	pivot_placed=true;
	if ( arr[piv] < arr[left] )
	{
	temp=arr[piv];
	arr[piv]=arr[left];
	arr[left]=temp;
	piv=left;
	}
	}/*End of while */
	System.out.println();
	System.out.println("pivot placed is  "+arr[piv]);
	display(arr,low,up);
	System.out.println();
	quick(arr,low,piv-1);
	quick(arr,piv+1,up);
	}/*End of quick()*/

	public static void main(String[] args) 
	{
		int array[]=new int[30];
		int n,i;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of elements : ");
		n=sc.nextInt();
		for (i=0;i<n;i++)
		{
		System.out.println("Enter element : "+(i+1));
		array[i]=sc.nextInt();
		}
		System.out.println("Unsorted list is");
		System.out.println();
		display(array,0,n-1);
		System.out.println();
		quick (array,0,n-1);
		System.out.println("sorted list is");
		System.out.println();
		display(array,0,n-1);
	}

}
