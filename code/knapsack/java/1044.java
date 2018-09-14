package com.home.geeks;

//http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
public class Knapsack {

	public static void main(String[] args) {
		int val[] = { 60, 100, 120 };
		int wt[] = { 10, 20, 30 };
		int w = 50;

		maximumValue(val, wt, w, val.length);

	}

	public static void maximumValue(int val[], int wt[], int W, int n) {
		int K[][] = new int[n + 1][W + 1];

		for (int i = 0; i <= n; i++) {
			for (int w = 0; w <= W; w++) {
				if (i == 0 || w == 0)
					K[i][w] = 0;
				else if (wt[i - 1] <= w)
					K[i][w] = Math.max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
				else
					K[i][w] = K[i - 1][w];
			}
		}

		for(int i = 0; i < K.length; i++){
			for(int j = 0; j < K[0].length; j++){
				System.out.print(K[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println(K[n][W]);
	}
}
