import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Quicksort {

    private static int comparisonsCount = 0;

    public static void main(String[] args) throws FileNotFoundException {
        List<Integer> input = loadData("data.txt");

        int number = quickSort(input, 0, input.size()-1);
        System.out.println(number);
    }

    public static List<Integer> loadData(String fileName) throws FileNotFoundException {
        List<Integer> result = new ArrayList<>();
        Scanner scan = new Scanner(new File(fileName));
        while(scan.hasNextLine()) {
            int element = Integer.parseInt(scan.nextLine());
            result.add(element);
        }

        return result;
    }

    public static int quickSort(List<Integer> array, int start, int end) {
        if (start >= end) {
            return 0;
        }

        int pivotIndex = chooseMedianPivot(array, start, end);
//        int pivotIndex = end;
//        int pivotIndex = chooseMedianPivot(array, start, end);
        int pivot = array.get(pivotIndex);

        swap(array, pivotIndex, start);
        int wallIndex = start +1 ;

        for (int i= start + 1; i <= end; i++) {
            if (array.get(i) < pivot) {
                swap(array, i, wallIndex);
                wallIndex++;
            }
        }
        wallIndex--;

        swap(array, start, wallIndex);
        return end - start + quickSort(array, start, wallIndex - 1) + quickSort(array, wallIndex + 1 , end);
    }

    public static void swap(List<Integer> array, int first, int second) {
        int temp1 = array.get(first);
        int temp2 = array.get(second);

        array.set(first, temp2);
        array.set(second, temp1);
    }

    public static int chooseMedianPivot(List<Integer> array, int start, int end) {
        int mid = (start + end) / 2;

        int min = Math.min(array.get(mid), Math.min(array.get(start), array.get(end) ));
        int max = Math.max(array.get(mid), Math.max(array.get(start), array.get(end) ));

        int median = array.get(mid) + array.get(start) + array.get(end) - min - max;

        int[] indexes = new int[]{start, mid, end};

        for (int i: indexes) {
            if (array.get(i) == median) {
                return i;
            }
        }

        return mid;
    }
}

