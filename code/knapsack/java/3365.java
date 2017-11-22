package dynprog;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import util.Creator;

public class Knapsack {
  
  // value > 0
  public static class Item {
    private int weight;
    private int value;
    private int count;
    public Item(int weight, int value, int count) {
      this.weight = weight;
      this.value = value;
      this.count = count;
    }
    public Item(int weight, int value) {
      this(weight, value, 1);
    }
    public Item(int weight) {
      this(weight, weight, 1);
    }
    public int getWeight() {
      return weight;
    }
    public int getValue() {
      return value;
    }
    public int getCount() {
      return count;
    }
  }
  
  public static int zeroOneKnapsack(Item[] items, int capacity, boolean full,
      List<Integer> pack) {
    int[] value = new int[capacity + 1];
    if (full) {
      for (int i = 1; i < value.length; ++i) {
        value[i] = -1;
      }
    }
    
    List<List<Integer>> record = null;
    if (pack != null) {
      record = Creator.create2DArray(capacity + 1);
    }
    int[] combNum = new int[capacity + 1];
    for (int i = 0; i < value.length; ++i) {
      combNum[i] = 1;
    }
    for (int i = 0; i < items.length; ++i) {
      int weight = items[i].getWeight();
      for (int j = capacity; j >= weight; --j) {
        if (value[j - items[i].getWeight()] != -1) {
          int v = value[j - items[i].getWeight()] + items[i].getValue();
          if (v == value[j]) {
            combNum[j] += combNum[j - items[i].getWeight()];
          } else if (v > value[j]) {
            value[j] = v;
            if (pack != null) {
              List<Integer> r = record.get(j);
              r.clear();
              r.addAll(record.get(j - items[i].getWeight()));
              r.add(i);
            }
            combNum[j] = combNum[j - items[i].getWeight()];
          }
        }
      }
    }
    if (pack != null) {
      pack.addAll(record.get(capacity));
    }
    return combNum[capacity];
  }
  
  public static void main(String[] argv) {
    Random rand = new Random(0);
    final int N = 4;
    Item[] items = new Item[N];
    for (int i = 0; i < N; ++i) {
      items[i] = new Item(i + 1, rand.nextInt(10) + 1);
      System.out.println(i + ": " + "(" + items[i].getWeight() + "," + items[i].getValue() + ")");
    }
    List<Integer> pack = new ArrayList<Integer>();
    int combNum = zeroOneKnapsack(items, 4, false, pack);
    System.out.println(combNum);
    System.out.println(pack);
  }

}
