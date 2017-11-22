package ga;

import java.util.Random;

/**
 * @author Nirari
 * 
 * This class will generate the objects in the knapsack problem to be used in the MPGA
 *
 */
public class Knapsack {
	
	public double[] weights;
	public double[] profits;
	public int[] order;
	private int number;
	private int value;
	public int capacity;
	private Random rand;
	
	public Knapsack(int num, int val) {
		number = num;
		value = val;
		capacity = 2 * val;
		weights = new double[num];
		profits = new double[num];
		order = new int[num];
		rand = new Random();
		rand.setSeed(987654321);
		for (int i = 0; i < num; i++) {
			weights[i] = rand.nextDouble()*(val-1) + 1;
			profits[i] = rand.nextDouble()*(val-1) + 1;
			//weights[i] = 1;
			//profits[i] = 5;
		}
		//setting top objects
		for (int i = 0; i < 20; i++) {
			weights[(int)(i*12.5)] = 1;
			profits[(int)(i*12.5)] = 10;
		}
		//setting traps
		//for (int i = 0; i < 10; i++) {
			//weights[(int)(i*25 + 1)] = 1;
			//profits[(int)(i*25 + 1)] = 9.5;
		//}
		printBest();
	}
	
	public void printBest() {
		double[] p_to_w = new double[number];
		for (int i = 0; i < number; i++) {
			p_to_w[i] = profits[i] / weights[i];
			order[i] = i;
		}
		sort(p_to_w, order);
		System.out.println("Top thirty objects:");
		for (int i = 0; i < 30; i++) {
			System.out.println("Object " + order[i] + " with ratio " + p_to_w[order[i]] + 
					" W: " + weights[order[i]] + " P: " + profits[order[i]]);			
		}
		int[] vec = new int[number];
		for (int i = 0; i < number; i++) {
			vec[i] = rand.nextBoolean()? 1: 0;
		}
		int sum = 0;
		int weight = 0;
		for (int i = 0; i < number; i++) {
			if (vec[i] == 1) {
				sum += profits[i];
				weight += weights[i];
			}
		}
		System.out.println("Random Vector: profit = " + sum + " , weight = " + weight);
		if (weight > capacity) {
			System.out.println("Applying repair...");
			weight = 0;
			sum = 0;
			for (int i = 0; i < number; i++) {
				if (vec[order[i]] == 1) {
					if (weight + weights[order[i]] <= capacity) {
						weight += weights[order[i]];
						sum += profits[order[i]];
					} else {
						vec[order[i]] = 0;
					}
				}
			}
		}
		System.out.println("New Vector: profit = " + sum + " , weight = " + weight);
		
		
		
	}
	
	private void sort(double[] arg, int[] arg2) {
		boolean done = true;
		for (int i = 0; i < arg.length - 1; i++) {
			double a = arg[arg2[i]];
			double b = arg[arg2[i+1]];
			if (b > a) {
				int temp = arg2[i];
				arg2[i] = arg2[i+1];
				arg2[i+1] = temp;
				done = false;
			}
		}
		if (done)
			return;
		else
			sort(arg, arg2);
	}

}
