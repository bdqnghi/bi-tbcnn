package bubblesort;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

public class Bubblesort {
    public static void main(String[] args) throws FileNotFoundException {
        File input = new File(args[0]);
        Scanner scanner = new Scanner(input);
        ArrayList<Integer> list = new ArrayList<>();
        
        while (scanner.hasNextInt())
        {
            list.add(scanner.nextInt());
        }
        bubbleSort(list);
        
        list.stream().forEach((s) -> {
            System.out.print(s + " ");
        });
        System.out.println();
    }
    
    private static void bubbleSort(ArrayList<Integer> list)
    {
        for (int i = list.size() - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (list.get(j) > list.get(j+1))
                    Collections.swap(list, j, j + 1);
            }
        }
    }
}
