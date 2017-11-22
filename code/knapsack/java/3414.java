package week5;

import java.util.Scanner;

public class Knapsack {

    public static int optimalWeight(int W, int[] weights) {
        int n = weights.length; //no of items
        int[][] values = new int[n+1][W+1];
        for (int i=0; i < values.length; i++) {
            for (int w = 0; w < values[0].length; w++) {
                if (i == 0 || w == 0) {
                    values[i][w] = 0;
                    continue;
                }
                values[i][w] = values[i - 1][w]; //not picking item i
                if (weights[i - 1] <= w) {
                    int value = values[i - 1][w - weights[i - 1]] + weights[i - 1]; //if picking item i
                    if (values[i][w] < value) {
                        values[i][w] = value;
                    }
                }
            }
        }
        return values[n][W];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int W, n;
        W = scanner.nextInt();
        n = scanner.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }
        System.out.println(optimalWeight(W, w));
    }
}

