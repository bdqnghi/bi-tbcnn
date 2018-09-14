// Bubblesort.java

import java.util.Scanner;
import java.util.Random;

/**
 * Bubblesort liesst ganze Zahlen ein und sortiert sie aufsteigend.
 * 
 * Liesst zu sortierende Zahlen entweder von der Standardeingabe
 * oder durch den Zufallsgenerator erzeugten Zahlen, ein.
 * 
 * @author H.Drachenfels
 * @version 6.3.2013
 */
public final class Bubblesort {
    private Bubblesort() { }

    /**
     * main ist der Startpunkt des Programms.
     * @param args wird nicht verwendet.
     */
    public static void main(final String[] args) {
        final Scanner stdin = new Scanner(System.in);
        final Random random = new Random();

        //----------------------------------------------- Feldgroesse einlesen
        if (args.length != 1) {
            System.err.println("Aufruf: java Bubblesort Anzahl");
            return;
        }

        final int n = Integer.parseInt(args[0]);

        //---------------------------------------------------- Zahlen einlesen
        final int[] a = new int[n];
        System.out.printf("Bitte %d ganze Zahlen eingeben: ", n);

        for (int i = 0; i < a.length; ++i) {
            if (stdin.hasNextInt()) {
                a[i] = stdin.nextInt();
            } else {
                a[i] = random.nextInt();
                System.out.println(a[i]);
            }
        }

        //--------------------------------------------------- Zahlen sortieren
        for (int i = a.length; i > 1; i--) {
            // groessten Wert nach hinten schieben
            for (int j = 0; j < i - 1; ++j) {
                if (a[j] > a[j + 1]) {
                    // Werte tauschen
                    int tmp = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = tmp;
                }
            }
        }

        //---------------------------------------------------- Zahlen ausgeben
        System.out.println("Sortierte Zahlenfolge: ");

        for (int i = 0; i < a.length; ++i) {
            System.out.println(a[i]);
        }
    }
}

