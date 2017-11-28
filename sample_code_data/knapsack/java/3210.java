package knapsack;

/**
 * Solves the knapsack problem. Determines maximum value given a set of weights
 * and values.
 * 
 * @author gphan
 * 
 */
public class Knapsack {

	static int[] weights = { 8, 5, 3, 5, 5, 4, 10, 15, 11, 9, 2, 6 };
	static int[] values = { 10, 7, 4, 10, 5, 11, 14, 15, 9, 9, 4, 5 };
	static final int W = 30;
	static int[] m = new int[W + 1];

	public static final void main(String[] args) {
		for (int i = 0; i < m.length; i++) {
			m[i] = 0;
		}

		for (int i = 0; i < weights.length; i++) {
			for (int j = 1; j <= W; j++) {
				if (weights[i] <= j) {
					m[j] = Math.max(m[j], m[j - weights[i]] + values[i]);
				}
			}
		}

		for (int i = 1; i < m.length; i++) {
			System.out.println(String.format("w: %d, m[w]: %d", i, m[i]));
		}
	}
}
