package geek.livingstone.problems.dp;

public class Knapsack {
  private int[][] M;
  private int[] weight;
  private int[] value;
  public Knapsack(int[] weight, int[] value, int W) {
    assert weight.length == value.length;
    this.weight = weight;
    this.value = value;
    M = new int[weight.length+1][W+1]; // i items with weight j
    for (int i=1;i<=weight.length;i++)
      for (int j=1;j<=W;j++)
        M[i][j] = Integer.MIN_VALUE;
    System.out.println("Maximum value is " + getMaxValue(weight.length, W));
  }

  private int getMaxValue(int i, int j) {
    if (i<=0 || j<=0)
      return 0;
    if (M[i][j] == Integer.MIN_VALUE)
    {
      M[i][j] = getMaxValue(i-1, j);
      if (j-weight[i-1] >= 0)
        M[i][j] = Math.max(M[i][j], getMaxValue(i-1, j-weight[i-1]) + value[i-1]);
    }
    assert M[i][j] != Integer.MIN_VALUE;
    return M[i][j];
  }

  public static void main(String[] args) {
    int[] wt = {1,1,1};
    int[] val = {10,20,30};
    new Knapsack(wt, val, 2);

    val = new int[] {50};
    wt = new int[] {50};
    new Knapsack(wt, val, 50);
  }

}
