package DynamicProgramming;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Given a bag which can only take certain weight W. Given list of items with their weights and price. How do you fill this bag to maximize value of items in the bag.
 * Time complexity is O(n^2)
 */
public class Knapsack {

	public static void main(String[] args) {
		List<Item> items = new ArrayList<Item>();
		items.add(new Item(1, 1));
		items.add(new Item(3, 4));
		items.add(new Item(4, 5));
		items.add(new Item(5, 7));
		
		int capacity = 7;
		
		Knapsack k = new Knapsack();
		List<Item> optimalItems = k.getItemsForMax(items, capacity);
		System.out.println(optimalItems);
	}
	
	public List<Item> getItemsForMax(List<Item> items, int capacity) {
		List<Item> solution = new ArrayList<Item>();
		if (capacity == 0 || items.isEmpty()) {
			return solution;
		}
		
		Collections.sort(items);
		
		int[][] cache = new int[items.size()][capacity + 1];
		
		for (int i = 0; i < items.size(); i++) {
			for (int j = 1; j < capacity + 1; j++) {
				if (i == 0) {
					if (j == items.get(i).weight) {
						cache[i][j] = items.get(i).value;
					}
					else {
						cache[i][j] = cache[i][j - 1];
					}
				}
				else {
					if (j < items.get(i).weight) {
						cache[i][j] = cache[i - 1][j];
					}
					else {
						cache[i][j] = Math.max(cache[i - 1][j], items.get(i).value + cache[i - 1][j - items.get(i).weight]);
					}
				}
			}
		}
		
		print2dArray(cache, items, capacity);
		System.out.println();
		
		int i = items.size() - 1;
		int j = capacity;
		int maxValue = cache[i][j];
		
		while (j > 0) {
			for (int k = 0; k < i + 1; k++) {
				if (cache[k][j] == maxValue) {
					solution.add(items.get(k));
					maxValue -= items.get(k).value;
					j -= items.get(k).weight;
					break;
				}
			}
		}
		
		return solution;
	}
	
	public void print2dArray(int[][] array, List<Item> items, int capacity) {
		for (int i = 0; i < capacity + 1; i++) {
			System.out.printf("\t%d", i);
		}
		System.out.println();
		
		for (int i = 0; i < array.length; i++) {
			System.out.printf("(%d) %d", items.get(i).value, items.get(i).weight);
			for (int j = 0; j < array[i].length; j++) {
				System.out.printf("\t%d", array[i][j]);
			}
			System.out.println();
		}
	}
	
}

class Item implements Comparable<Item> {
	
	int weight;
	int value;
	
	public Item(int weight, int value) {
		this.weight = weight;
		this.value = value;
	}
	
	@Override
	public int compareTo(Item o) {
		return Integer.compare(this.value, o.value);
	}
	
	@Override
	public String toString() {
		return "{weight: " + weight + ", value: " + value + "}";
	}
	
}