import java.util.*;

public class Knapsack {
    static int optimalWeight(int W, int[] w) {
        int m[][] = new int[w.length+1][W+1];
        
        for(int i=0;i<W+1;++i) {
            m[0][i] = 0;
        }
        for(int j=0;j<(w.length+1);++j) {
            m[j][0] = 0;
        }
        
        for(int i=1;i<w.length+1;++i) {
            for(int j=1;j<W+1;++j) {
                m[i][j] = m[i-1][j];
                if (w[i-1]<=j) {
                    int val = m[i-1][j-w[i-1]] + w[i-1];
                    if (m[i][j] < val)
                        m[i][j] = val;
                }
            }
        }
        
        return m[w.length][W];
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

