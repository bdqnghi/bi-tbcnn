package pack;
import java.util.Scanner;

public class bubblesort {
public static void main(String[] args){
	int temp;
	System.out.println("Enter array size");
	Scanner s1=new Scanner(System.in);
	int x=s1.nextInt();
	int array[]=new int[x];
	
	System.out.println("Enter"+x+"integers");
	for(int i=0;i<x;i++){
		array[i]=s1.nextInt();
		}
 
	try{for(int m=1;m<x;m++){
		
	   for(int n=0;n<x-m;n++){
		   if(array[n]>array[n+1]){
			   temp=array[n];
			   array[n]=array[n+1];
			   array[n+1]=temp;
	     }   
	   }
   }
   for(int j=0;j<x;j++){
   System.out.println(array[j]);
   }}catch(Exception e){System.out.println("error");}

	}
}