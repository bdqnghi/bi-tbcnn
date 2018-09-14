import java.util.*;

public class Knapsack{
	
	public static void main(String[] args){
		// w = the total weight
		// i = item i
		// m[i, w] = maximum value attained with weight <= w using items up to i
		//
		// recurrence relation:
		// m[0, w] = 0, if there's zero items, the sum is zero
		// m[i, w] = m[i-1, w], if w(i) > w, the new item's weight > current weight limit
		// m[i, w] = max(m[i-1, w],
		// 				 m[i-1, w-w(i)] + v(i), if w(i) <= w
		//
		//
		ArrayList<Item> items = new ArrayList<Item>();

		items.add(new Item(10, 60));
		items.add(new Item(20, 100));
		items.add(new Item(30, 120));

		System.out.println(knapsack(items.size()-1, 50, items));
	}

	public static int knapsack(int i, int w, ArrayList<Item> items){
		if(i < 0){
			return 0;
		}else if(items.get(i).weight > w){
			return knapsack(i-1, w, items);
		}else if(items.get(i).weight <= w){
			return Math.max(knapsack(i-1, w, items),
							knapsack(i-1, w-items.get(i).weight, items) + items.get(i).value);
		}else{
			System.out.println("wut");
			return 0;
		}
	}

}

class Item{
	public int weight;
	public int value;

	public Item(int weight, int value){
		this.weight = weight;
		this.value = value;
	}
}
