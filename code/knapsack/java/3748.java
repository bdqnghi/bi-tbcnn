package codeground.note;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Knapsack {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		int[] V = new int[N+1];
		int[] W = new int[N+1];
		
		for(int n = 1; n <= N; ++n) {
			V[n] = sc.nextInt();
			W[n] = sc.nextInt();
		}
		
		int[][] cache = new int[N+1][K+1];
		for(int n = 1; n <= N; ++n) {
			for(int k = 0; k <= K; ++k) {
				if(W[n] > k) {
					cache[n][k] = cache[n-1][k];
				}
				else if(cache[n-1][k - W[n]] + V[n] > cache[n-1][k]) {
					cache[n][k] = cache[n-1][k - W[n]] + V[n];
				}
				else {
					cache[n][k] = cache[n-1][k];
				}
			}
		}
		
		int ans = 0;
		for(int k = 0; k <= K; ++k)
			if(ans < cache[N][k])
				ans = cache[N][k];
		
		System.out.println(ans);
	}
}
