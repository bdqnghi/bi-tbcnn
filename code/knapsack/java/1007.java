/**
 * Title: Knapsack.java
 * Abstract: Solving Knapsack problem using a recursive call and dynamic programming.
 * Author: Arash Aria
 * ID: 4210
 * Date: 10/20/15
 */
import java.util.Scanner;

public class Knapsack {


	private static int knapsack(int[] valueOfItems, int[] weightOfItemsint, int numberOfItem, int capacity) {
	    if (numberOfItem < 0) {
		   	return 0;	        
	    }
	    if (weightOfItemsint[numberOfItem] > capacity) {
	    	
	    	return knapsack(valueOfItems, weightOfItemsint, numberOfItem-1, capacity);
	    } else {
	    	
	    	if (knapsack(valueOfItems, weightOfItemsint, numberOfItem-1, capacity)> 
	        		knapsack(valueOfItems, weightOfItemsint, numberOfItem-1, 
	        				capacity - weightOfItemsint[numberOfItem]) + valueOfItems[numberOfItem])
	    	{
	    		return	knapsack(valueOfItems, weightOfItemsint, numberOfItem-1, capacity);
	    	} else {
	    		return	knapsack(valueOfItems, weightOfItemsint, numberOfItem-1, 
        				capacity - weightOfItemsint[numberOfItem]) + valueOfItems[numberOfItem];
	    	}
	    	
	    }
	}
	
	public static void main(String[] args) {
		int numberOfItems = 0;
		int capacity = 0;
		int[] weightOfItems;
		int[] valueOfItems;
		Scanner myScanner = new Scanner(System.in);
		System.out.println("Enter a number of items:");
		numberOfItems = myScanner.nextInt();
		weightOfItems = new int[numberOfItems];
		valueOfItems = new int[numberOfItems];
		System.out.println("Enter knapsack capacity:");
		capacity = myScanner.nextInt();
		System.out.println("Enter weights and values of " + numberOfItems + " items:");
		for (int i = 0; i < numberOfItems; i++) {
			System.out.print("Item " + (i+1) + ": ");
			weightOfItems[i] = myScanner.nextInt();
			valueOfItems[i] = myScanner.nextInt();
			
		}
		System.out.print("List of weights---> {");
		for (int i = 0; i < numberOfItems; i++){
			System.out.print(weightOfItems[i]);
			System.out.print(",");
		}
		System.out.println("}");
		System.out.print("List of values---> {");
		for (int i = 0; i < numberOfItems; i++){
			System.out.print(valueOfItems[i]);
			System.out.print(",");
		}
		System.out.println("}");
		
		System.out.println("Capacity --->"+capacity);
		System.out.println("Value --->"+knapsack(valueOfItems,weightOfItems,numberOfItems-1,capacity));
	}

}
