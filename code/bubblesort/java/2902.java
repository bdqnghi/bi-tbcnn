package de.htw.felix.sorting.sort;

import java.util.List;

/**
 * Created by Felix on 02.06.2016.
 *
 * @author Felix
 */
public class Bubblesort<T> implements Sortable<T> {

    public void sort(List<T> list, Comparator<T> comparator) {
        for (int i = 1; i < list.size(); i++) {
            for (int j = 0; j < list.size(); j++) {
                if (comparator.compareTo(list.get(j), list.get(j + 1)) > 0) {
                    swap(list, j, j + 1);
                }
            }
        }
    }

    private void swap(List<T> list, int i, int j) {
        T temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    }

}
