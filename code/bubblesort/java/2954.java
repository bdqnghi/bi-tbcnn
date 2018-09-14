package firstjavaprogram;

import java.util.Scanner;

public class bubblesort {
	public static void main(String args[])
	{
		int n,i,temp,j;
		System.out.println("enter n value");
		Scanner s=new Scanner(System.in);
		n=s.nextInt();
		int a[]=new int[n];
		System.out.println("enter array values");
		for(j=0;j<n;j++)
		{
			a[j]=s.nextInt();
		}
		for(j=0;j<n;j++)
		{
			for(i=0;i<n-1;i++)
			{
				if(a[i]>a[i+1])
				{
					temp=a[i+1];
					a[i+1]=a[i];
					a[i]=temp;
				}
			}
		}
		System.out.println("sorted array is:");
		for(j=0;j<n;j++){
			System.out.println(a[j]);
		}
	}
}
