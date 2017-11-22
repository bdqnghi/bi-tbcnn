/*
Category: Dynamic Programming
Problem Introduction
This problem is about implementing an algorithm for the knapsack without repetitions problem.
Problem Description
Task. In this problem, you are given a set of bars of gold and your goal is to take as much gold as possible into your bag. There is just one copy of each bar and for each bar you can either take it or not (hence you cannot take a fraction of a bar).
Input Format. The first line of the input contains the capacity W of a knapsack and the number n of bars of gold. The next line contains n integers w0,w1,...,wn−1 defining the weights of the bars of gold.
Constraints. 1 ≤ W ≤ 104; 1 ≤ n ≤ 300; 0 ≤ w0,...,wn−1 ≤ 105.
Output Format. Output the maximum weight of gold that fits into a knapsack of capacity W.
Time Limits.
language    C C++ Java Python C# Haskell JavaScript Ruby Scala
time in seconds 2   2   3   10  3   4   10  10  6
Memory Limit. 512Mb.

*/


import java.util.*;
public class Knapsack {
    static int optimalWeight(int W, int[] w) {
       int table[][] = new int[W+1][w.length+1];
       for(int i =1;i<=w.length;i++){
           for (int j = 1; j <= W; j++) {
            if(j<w[i-1]){
                table[j][i] = table[j][i-1];
            }
            else{
                table[j][i] = Math.max(table[j-w[i-1]][i-1]+w[i-1], table[j][i-1]);
            }
        }
       }
       return table[W][w.length];
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
        scanner.close();
    }
}

