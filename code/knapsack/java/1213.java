package algorithms;

import java.util.ArrayList;
import java.util.List;

class Item {

    int value;
    int weight;

    Item(int value, int weight) {
        this.value = value;
        this.weight = weight;
    }

    @Override
    public String toString() {
        return "(value=" + value + ", weight=" + weight + ")";
    }
}

public class Knapsack {

    private int maxCapacity;
    private List<Item> items;
    private int[][] memoizationTable;

    public Knapsack(List<Item> items, int maxCapacity) {
        this.items = items;
        this.maxCapacity = maxCapacity;
        this.memoizationTable = buildMemoizationTable();
    }

    public int maxValue() {
        return memoizationTable[items.size()][maxCapacity];
    }

    public List<Item> elementsInBag() {
        List<Item> elements = new ArrayList<>();
        int i = items.size();
        int j = maxCapacity;
        while (i > 0) {
            Item item = items.get(i - 1);
            if (memoizationTable[i][j] != memoizationTable[i - 1][j]) {
                elements.add(item);
                j -= item.weight;
            }
            i -= 1;
        }
        return elements;
    }

    private int[][] buildMemoizationTable() {
        int nItems = items.size();

        // +1 to store 0th row and column
        int[][] memoizationTable = new int[nItems + 1][maxCapacity + 1];
        for (int i = 1; i <= nItems; i++) {
            for (int j = 1; j <= maxCapacity; j++) {
                Item item = items.get(i - 1);
                int result;
                if (j < item.weight) {
                    result = memoizationTable[i - 1][j];
                } else {
                    result = Math.max(item.value
                            + memoizationTable[i - 1][j - item.weight],
                                      memoizationTable[i - 1][j]);
                }
                memoizationTable[i][j] = result;
            }
        }
        return memoizationTable;
    }
}
