package singlethreaded;

import interfaces.SortingBase;

public class Bubblesort implements SortingBase {

  /**
   * Sortiert ein int-Array mit Bubblesort
   *
   * @param numbers int[]
   */
  @Override
  public void sort(int[] numbers) {
    for (int i = 0; i < numbers.length - 1; i++) {
      for (int j = numbers.length - 2; j >= i; j--) {
        if (numbers[j] > numbers[j + 1]) {
          swap(numbers, j, j + 1);
        }
      }
    }
  }

  /**
   * Tauscht zwei Elemente im Array
   *
   * @param numbers int[]
   * @param j int
   * @param i int
   */
  private void swap(int[] numbers, int j, int i) {
    int tmp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = tmp;
  }

  @Override
  public String getName() {
    return "Bubblesort";
  }
}
