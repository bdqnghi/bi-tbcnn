package com.hackerrank.algorithms.dynamicprogramming;

import java.util.Scanner;

public class Knapsack {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			int[] array = new int[sc.nextInt()];
			int expectedSum = sc.nextInt();
			for (int j = 0; j < array.length; j++) {
				array[j] = sc.nextInt();
			}
			boolean[] solution = new boolean[expectedSum + 1];
			solution[0] = true;
			int maxSum = 0;
			for (int j1 = 1; j1 < expectedSum + 1; j1++) {
				for (int j2 = 0; j2 < array.length; j2++) {
					if (j1 >= array[j2] && solution[j1 - array[j2]]) {
						solution[j1] = true;
						maxSum = j1;
						break;
					}
				}
			}
			System.out.println(maxSum);
		}
		sc.close();
	}
}
