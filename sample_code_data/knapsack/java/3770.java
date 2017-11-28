package com.nastra.algorithms;

/**
 * Solves the 0/1 Knapsack problem using Dynamic Programming. Complexity O(cN), where c is the max capacity of the pack, and N is the total number of
 * items
 * 
 * @author nastra - Eduard Tudenhoefner
 */
public class Knapsack {

    private static int[][] solution;

    public static int optimalValue(int numberOfItems, int capacity, int[] weight, int[] value) {
        solution = new int[numberOfItems + 1][capacity + 1];
        for (int i = 1; i <= numberOfItems; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (weight[i] <= w) {
                    solution[i][w] = Math.max(solution[i - 1][w], solution[i - 1][w - weight[i]] + value[i]);
                } else {
                    solution[i][w] = solution[i - 1][w];
                }
            }
        }
        return solution[numberOfItems][capacity];
    }
}
