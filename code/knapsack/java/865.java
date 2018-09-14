import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * Created by yxy on 4/19/2015.
 */
public class Knapsack {
    public static long[] cache;
    public static Item[] items;

    public static void knapsack(String fileName) {

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String[] firstLine = br.readLine().split(" ");
            int knapsackSize = Integer.parseInt(firstLine[0]);
            int numOfItem = Integer.parseInt(firstLine[1]);

            cache = new long[knapsackSize+1];
            for (int i = 0; i < cache.length; i++)
                cache[i] = 0;
            items = new Item[numOfItem+1];
            items[0] = new Item();

            String line;
            int index = 1;
            while ((line = br.readLine()) != null) {
                String[] valueAndWeight = line.split(" ");
                int value = Integer.parseInt(valueAndWeight[0]);
                int weight = Integer.parseInt(valueAndWeight[1]);

                items[index++] = new Item(value, weight);
            }

            for (int i = 1; i <= numOfItem; i++) {
                long[] tempCache = new long[knapsackSize+1];
                for (int j = 0; j <= knapsackSize; j++) {
                    tempCache[j] = pickOptWithCache(j, i);
                }
                cache = tempCache;  // update cache
            }

            System.out.println(/*pickOpt(knapsackSize, numOfItem)*/ cache[knapsackSize]);

        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    // has to be run in a increasing order
    public static long pickOptWithCache(int currentKnapsackSize, int itemIndex) {
        long withThisItem;
        if (currentKnapsackSize >= items[itemIndex].weight) {
            withThisItem = cache[currentKnapsackSize - items[itemIndex].weight];
            withThisItem += items[itemIndex].value;
        }
        else {
            withThisItem = 0;
        }

        long withoutThisItem = cache[currentKnapsackSize];

        if (withoutThisItem >= withThisItem) {
            return withoutThisItem;
        }
        else {
            return withThisItem;
        }
    }

    /*public static long pickOpt(int currentKnapsackSize, int itemIndex) {
        if (itemIndex == 0) {
            return 0;
        }

        long withThisItem;
        if (currentKnapsackSize >= items[itemIndex].weight) {
            withThisItem = pickOpt(currentKnapsackSize - items[itemIndex].weight, itemIndex - 1);
            withThisItem += items[itemIndex].value;
        }
        else {
            withThisItem = 0;
        }

        long withoutThisItem = pickOpt(currentKnapsackSize, itemIndex - 1);

        if (withoutThisItem > withThisItem) {
            return withoutThisItem;
        }
        else {
            return withThisItem;
        }
    }*/
}
