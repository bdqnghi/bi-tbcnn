/*
 * The MIT License
 *
 * Copyright 2013 Sada Kurapati <sadakurapati@gmail.com>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.sada.algorithms.dp;

import java.util.Arrays;

/**
 * Knapsack algorithm
 *
 * @author Sada Kurapati <sadakurapati@gmail.com>
 */
public class Knapsack {

  public static void main(String[] args) {
    int[] price = {6, 4, 5, 3, 9, 7};
    int[] weights = {4, 2, 3, 1, 6, 4};

    int sackCapacity = 10;
    boolean[][] keep = getItemsToPick(price, weights, sackCapacity);
    printSelectedItems(keep, sackCapacity, price, weights);
  }

  /**
   * price[] - value - $$$ Gain weights[] - weights sackCapacity - the maximum
   * weight knapsack can carry.
   */
  private static boolean[][] getItemsToPick(int[] price, int[] weights, int sackCapacity) {
    int nItems = price.length;
    //dp[i][w] - the maximum value of sub problem with i items and with w sack capacity.
    //no need to initialize with zeros as in java, the defalt values are 0 for int premitive type.
    int[][] dpTable = new int[nItems + 1][sackCapacity + 1];
    boolean[][] keep = new boolean[nItems][sackCapacity + 1];

    //iterate through all of the items
    for (int i = 1; i <= nItems; i++) {
      //calculate sub problem for all weights      
      for (int w = 1; w <= sackCapacity; w++) {
        if (weights[i - 1] > w) {
          // we cannt take this weight as it exceeds sub problem with weight w and i items
          dpTable[i][w] = dpTable[i - 1][w];
        } else {
          //Price if we include item i
          int pYes = price[i - 1] + dpTable[i - 1][w - weights[i - 1]];
          //Price if we include item i
          int pNo = dpTable[i - 1][w];
          if (pYes > pNo) {
            //this item MAY go into sack
            keep[i - 1][w] = true;
            dpTable[i][w] = pYes;
          } else {
            dpTable[i][w] = pNo;
          }
        }
      }
    }
    //printing dpTable
    System.out.println(Arrays.deepToString(dpTable));
    return keep;
  }

  public static void printSelectedItems(boolean[][] keep, int sackCapacity, int[] price, int[] weights) {
    //printing what items we picked
    System.out.println("Selected items:");
    int K = sackCapacity;
    int n = price.length;
    int wsel = 0;
    int vsel = 0;
    for (int i = n - 1; i >= 0; i--) { // need to go in the reverse order
      if (keep[i][K] == true) {
        System.out.println(i + "\tv=" + price[i] + "\tw=" + weights[i]);
        wsel += weights[i];
        vsel += price[i];
        K = K - weights[i];
      }
    }
    System.out.println("The overall value of selected items is " + vsel + " and weight " + wsel);
    System.out.println("Maximum weight was " + sackCapacity);
  }
}
