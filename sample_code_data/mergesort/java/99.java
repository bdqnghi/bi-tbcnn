package com.solid;

public class Mergesort extends Sorter {

    public Mergesort() {
        super.type = SortType.MERGESORT;
    }

    @Override
    protected void sort() {
        System.out.println("Sorting with merge sort...");
    }
}
