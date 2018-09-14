import java.io.*;
import java.util.*;

public class Bubblesort {
	public static int swapzaehler=0;
	public static void main(String[] args){
		int elemente=100;
		
		Random rand = new Random();
		int[] liste = new int[elemente];

		for (int i=0; i<liste.length;i++){
			liste[i]=rand.nextInt(1000);
		}
		//ausdrucker(liste);
		//System.out.println("\n");
		//ausdrucker(sortierer(liste));
		sortierer(liste);
	}

	
	public static int[] sortierer(int[] liste){
		boolean unsortiert = true;
		while (unsortiert){
			unsortiert=false;
			for (int i=0;i<liste.length-1;i++){
				if (liste[i]>liste[i+1]){
					int temp=liste[i];
					liste[i]=liste[i+1];
					liste[i+1]=temp;
					unsortiert = true;
					swapzaehler++;
				}	
			}
		}
		System.out.println(swapzaehler);
		return liste;
	}
	
	public static void ausdrucker(int[] liste){
		int i=0;
		while (i!=(liste.length-1)){
			System.out.print(liste[i]+" ");
			i++;
		}
	}
}
