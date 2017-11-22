package com.hkr;

import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

/**
 * Created by chyvn on 29-10-2016.
 */
public class BFS {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        while (n > 0) {
            --n;
            int nodes = scanner.nextInt();
            int array[][] = new int[nodes][nodes];
            for (int i = 0; i < nodes; i++) {
                for (int j = 0; j < nodes; j++)
                    array[i][j] = 0;
            }
            int edges = scanner.nextInt();

            while (edges > 0) {
                --edges;
                int from = scanner.nextInt() - 1;
                int to = scanner.nextInt() - 1;
                array[from][to] = 1;
                array[to][from] = 1;
            }

            int s = scanner.nextInt();

            int distance[] = new int[nodes];
            boolean visited[] = new boolean[nodes];
            for (int i = 0; i < nodes; i++) {
                distance[i] = -1;
                visited[i] = false;
            }
            distance[s - 1] = 0;
            visited[s - 1] = true;
            Queue<Integer> queue = new PriorityQueue<>();
            Queue<Integer> parentWeight = new PriorityQueue<>();
            queue.add(s - 1);
            parentWeight.add(0);
            while (!queue.isEmpty()) {
                int item = queue.remove();
                int weight = parentWeight.remove();
                for (int i = 0; i < nodes; i++) {
                    if (array[item][i] != 0 && !visited[i]) {
                        queue.add(i);
                        distance[i] = weight + 6;
                        parentWeight.add(distance[i]);
                        visited[i] = true;
                    }
                }
            }
            for (int i = 0; i < nodes; i++) if (distance[i] != 0) System.out.print(distance[i] + " ");
            System.out.println();
        }
    }
}
