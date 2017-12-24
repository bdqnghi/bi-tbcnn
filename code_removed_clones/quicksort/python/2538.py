"""
Quicksort

Definition: (...) is an efficient sorting algorithm, serving as a systematic
method for placing the elements of an array in order. Developed by Tony Hoare
in 1959, with his work published in 1961, it is still a commonly used
algorithm for sorting. When implemented well, it can be about two or three
times faster than its main competitors, merge sort and heapsort.

Worst-case: O(n^2)
Best-case: O(n log n) / O(n) (three-way partition and equal keys)

Reference: https://en.wikipedia.org/wiki/Quicksort

"""
import random


def quicksort(array, p=0, r=None):
    if r is None:
        r = len(array) - 1

    if p >= r:
        return array

    q = _partition(array, p, r)
    quicksort(array, p, q - 1)
    quicksort(array, q, r)

    return array


def _partition(array, p, r):
    pivot = random.randint(p, r)
    q = p

    _swap(array, pivot, r)

    for i in range(p, r):
        if array[i] <= array[r]:
            _swap(array, i, q)
            q += 1

    _swap(array, q, r)
    return q


def _swap(array, a, b):
    c = array[a]
    array[a] = array[b]
    array[b] = c


if __name__ == '__main__':
    a = [5, 2, 10, 2, -3, 1]
    print('unsorted ', a)

    quicksort(a)

    print('sorted ', a)
