import java.util.*;

public class Knapsack {
    /**
    * Return maximum value that can be stolen in a knapsack.
    */
    public int solve(int numItems, int[] weights, int[] values, int totalWeight) {
        if (numItems == 0 || totalWeight == 0) {
            return 0;
        }

        // if weight of this item exceeds maximum weight allowed, skip this item.
        if (weights[numItems-1] > totalWeight) {
            return solve(numItems-1, weights, values, totalWeight);
        }

        return Math.max(values[numItems-1] + solve(numItems-1, weights, values, totalWeight - weights[numItems-1]),
            solve(numItems-1, weights, values, totalWeight));
    }

    public static void main(String[] args) {
        Knapsack knapsack = new Knapsack();
        int totalItems = Integer.parseInt(args[0]);
        int totalWeight = Integer.parseInt(args[1]);
        int[] weights = knapsack.getRandomArray(totalItems, 10);
        int[] values = knapsack.getRandomArray(totalItems, 100);
        System.out.println("Weights:\t" + Arrays.toString(weights));
        System.out.println(" Values:\t" + Arrays.toString(values));
        System.out.println("Max value to carry: " + knapsack.solve(totalItems, weights, values, totalWeight));
    }

    public int[] getRandomArray(int totalItems, int maxValue) {
        Random rand = new Random();
        int[] arr = new int[totalItems];
        for (int i = 0; i < totalItems; i++) {
            arr[i] = rand.nextInt(maxValue);
        }
        return arr;
    }
}
