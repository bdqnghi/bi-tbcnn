package alex.algorithms.graphs;

import java.util.LinkedList;
import java.util.List;

public class DFS {
    private static final int MAX = 1000;
    static int G[][] = new int[MAX + 1][MAX + 1];
    static int ans[] = new int[MAX + 1];
    static int vdepth[] = new int[MAX + 1];
    static int k = 2;

    public static boolean dfs(final int v, final int d) {
        ans[d] = v;
        vdepth[v] = d;
        List<Integer> n = adj(v);
        for (Integer vertex : n) {
            if (vdepth[vertex] == 0) {
                if (dfs(vertex, d + 1))
                    return true;
            } else if (d - vdepth[vertex] >= k) {
                System.out.printf("%d\n", d - vdepth[vertex] + 1);
                for (int j = vdepth[vertex]; j <= d; j++)
                    System.out.printf("%d ", ans[j]);
                return true;
            }
        }
        return false;
    }

    public static List<Integer> adj(final int v) {
        List<Integer> neig = new LinkedList<Integer>();
        for (int i = 0; i <= MAX; i++) {
            if (G[v][i] != 0) {
                neig.add(i);
            }
        }
        return neig;
    }

    /**
     * @param args
     */
    public static void main(final String[] args) {
        G[1][2] = 1;
        G[2][1] = 1;

        G[2][3] = 1;
        G[3][2] = 1;

        G[3][1] = 1;
        G[1][3] = 1;
        dfs(1, 1);
    }
}
