import java.util.Scanner;


public class Bubblesort {

	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int no;
		System.out.println("Enter array size :");
		no=sc.nextInt();
		
		int list []=new int[no];
		int list1 []=new int[no];
		for(int i=0;i<no;i++){
			list[i]=sc.nextInt();
		}
		
		Bubblesort b =new Bubblesort();
       list1=b.bubbleSort(list, no);
       for(int i=0;i<no;i++){
			System.out.print("     ->"+list1[i]);
		}
		sc.close();
	}
	//bubble sort for integers
	public int[] bubbleSort(int list[],int no)
	{
		int i,j,temp;
		for(i=0;i<no;i++)
		{
			for(j=0;j<no-i-1;j++)
			{
			//bubble sort logic
				if(list[j]>list[j+1])
				{
				temp=list[j+1];
				list[j+1]=list[j];
				list[j]=temp;
				}
			}
		}
		return list;
	}
}
