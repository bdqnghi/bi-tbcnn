package algorithmsDAA;

import java.util.Scanner;
class Knapsack
{

public static void main(String[] args) 
{
      
	@SuppressWarnings("resource")
	Scanner in = new Scanner(System.in);
		
	System.out.println(" Enter number of items :");
	int N = in.nextInt();
		
	System.out.println(" Enter Maximum weight :");
	int W = in.nextInt();
		
       	int[] Value = new int[N+1];
       	int[] weight = new int[N+1];

   	System.out.println("Enter values :");
	for (int n = 1; n <= N; n++) 
	{
           	Value[n] = in.nextInt();
       	}
		
	System.out.println("Enter weight : ");
	for (int n = 1; n <= N; n++) 
	{
           	weight[n] = in.nextInt();
       	}

       	int[][] opt = new int[N+1][W+1];
       	boolean[][] sol = new boolean[N+1][W+1];

       	for (int n = 1; n <= N; n++) 
	{
           	for (int w = 1; w <= W; w++) 
		{

               	int option1 = opt[n-1][w];
               	int option2 = Integer.MIN_VALUE;
           
		if (weight[n] <= w)
		 option2 = Value[n] + opt[n-1][w-weight[n]];
	
           
		 opt[n][w] = Math.max(option1, option2);
               	sol[n][w] = (option2 > option1);
              }
       }

       boolean[] take = new boolean[N+1];
       
       for (int n = N, w = W; n > 0; n--) 
       {
       	     if (sol[n][w]) 
	     {
		take[n] = true;  w = w - weight[n];
	      }
                 else           
	     {
		take[n] = false;                   
	       }
       }

       System.out.println("item" + "\t" + "Value" + "\t" + "weight" + "\t" + "take");
       
       for (int n = 1; n <= N; n++) 
      {
           System.out.println(n + "\t" + Value[n] + "\t" + weight[n] + "\t" + take[n]);
       }
   }
}
