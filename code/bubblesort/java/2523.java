package akshit1;

import java.io.IOException;
import java.util.Scanner;

public class Bubblesort {
	public static void main(String[] args) throws IOException{

		int intArray[];    //declaring array
		intArray = new int[15];
		System.out.println("enter input array ");
		Scanner sc= new Scanner(System.in);
		int i;
		for(i=0;i<15;i++)
		{
			intArray[i]=sc.nextInt();
		}
		int temp;
		int j;
		for(i=0;i<15;i++)
		{
			for (j=0;j<15-1-i;j++)
			{
				if(intArray[j]>intArray[j+1])
				{
					temp=intArray[j];
				    intArray[j]=intArray[j+1];
					intArray[j+1]=temp;
					
				}
			}
		}
		System.out.println("sorted array is");
		for(i=0;i<15;i++) {
		System.out.println(intArray[i]);
		}
		
		}
	  //sc.close();

}
