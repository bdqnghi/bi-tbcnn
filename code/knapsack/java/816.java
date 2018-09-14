package com.hackerrank.algo.dynamic_programming;

import com.lqw.common.WebPath;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Knapsack {

    public static int weights[];

    public static int max_weights_with_con(int first, int weights_con) {
        if (first < 0) return 0;
        if (weights_con >= weights[first]) {
            return Math.max(max_weights_with_con(first, weights_con - weights[first]) + weights[first],
                    max_weights_with_con(first - 1, weights_con));
        } else {
            return max_weights_with_con(first - 1, weights_con);
        }
    }

    public static void main(String[] argv) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(WebPath.getAbsolutePathWithClass("/input.txt").getPath()));
        //        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        //        Scanner sc = new Scanner(System.in);
        //presolve
        //input
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            weights = new int[n];
            for (int i = 0; i < n; i++) {
                weights[i] = sc.nextInt();
            }
            Arrays.sort(weights);

            System.out.println(max_weights_with_con(n - 1, k));
        }

        //resolve

        //output
        sc.close();
    }
}
