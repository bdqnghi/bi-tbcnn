package com.shashi.algo;

public class Knapsack {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int w[] = {2,3,4,5};
		//int b[] = {3,4,5,6};
		int b[] = {3,7,2,9};
		System.out.println(findMaxBenefit(w, b, 5, w.length));
 	}
	
	public static int findMaxBenefit(int w[], int b[], int M, int n)
	{
		int B[][] = new int[n+1][M+1];
		for(int r = 0; r < n+1;r++)
		{
			B[r][0] = 0;
		}
		for(int c = 0; c < M+1;c++)
		{
			B[0][c] = 0;
		}
		for(int r = 1; r < n+1; r++)
		{
			for(int c = 1 ; c<M+1; c++)
			{
				if(w[r-1] > c)
				{
					B[r][c] = B[r-1][c];
				}
				else
				{
					try {
						B[r][c] = Math.max(B[r-1][c], b[r-1] + B[r-1][c-w[r-1]]);
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
		}
		for(int r = 0; r < n+1; r++)
		{
			for(int c = 0 ; c<M+1; c++)
			{
				System.out.print(B[r][c] + "   ");
			}
			System.out.println();
		}
		return B[n][M];
	}

}
