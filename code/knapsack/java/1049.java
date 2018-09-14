import java.util.*;

public class Knapsack {
    static int optimalWeight(int W, int[] w) {
        //write you code here
        int[][] solnArr = new int[W + 1][w.length + 1];
        for(int i = 0; i< W+1; i++) {
            solnArr[i][0] = 0;
        }
        for(int i = 0; i< w.length+1; i++) {
            solnArr[0][i] = 0;
        }

        for(int n = 1; n <= w.length; n++) {
            for(int i = 1; i <= W; i++) {
                int wn = w[n-1];
                int max = solnArr[i][n - 1];
                // System.out.println("max: " + max);
                if(wn <= i) {                    
                    int a = solnArr[i - wn][n-1] + w[n - 1];
                    // System.out.println("a: " + a);
                    if(a > max) max = a;
                }
                // System.out.println("max after: " + max);
                solnArr[i][n] = max;                
                // System.out.println("solution["+i+"]["+n+"]"+": " + solnArr[i][n]);
            }
        }

        return solnArr[W][w.length];
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

