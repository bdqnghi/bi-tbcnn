package de.masternoir.sort_algorithms.bubblesort;

import functions.functions;

public class bubblesort {
	
	/** Vergleichsbasierter Sortieralgorithmus.
	 * Sortiert in-place, stabil und hat eine O(n^2)-Laufzeit im 
	 * Durchschnitt.
	 * Wird in der Praxis kaum eingesetzt, da schlechte Performance.
	 */
	public static double[] bubblesort(double[] list, boolean ascending){
		
		double[] sortedList = list;
		double switchPos;
		boolean cont;
		
		do{
			cont  = false;
			for (int i = 0; i < sortedList.length-1; i++){
				if (!functions.compare(sortedList[i], sortedList[i+1], ascending)){
					cont = true;
					switchPos = sortedList[i];
					sortedList[i] = sortedList[i+1];
					sortedList[i+1] = switchPos;
				}
			}
		}while(cont);
		
		return sortedList;
	}
	
	
}
