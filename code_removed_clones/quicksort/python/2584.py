#!/usr/bin/env python3
import random


def partition(arr, lo, hi):
    mid_index = lo
    pivot = arr[hi]

    for i in range(lo, hi):
        if arr[i] <= pivot:
            arr[i], arr[mid_index] = arr[mid_index], arr[i]
            mid_index += 1

    arr[mid_index], arr[hi] = arr[hi], arr[mid_index]
    return mid_index


def hoare_partition(arr, lo, hi):
    pivot = arr[lo]
    i = lo - 1
    j = hi + 1

    while True:
        while True:
            j -= 1
            if arr[j] <= pivot:
                break

        while True:
            i += 1
            if arr[i] >= pivot:
                break

        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
        else:
            return j


def randomized_partition(arr, lo, hi):
    rand = random.randint(lo, hi)
    arr[hi], arr[rand] = arr[rand], arr[hi]
    return partition(arr, lo, hi)


def quick_sort(arr, lo, hi):
    if lo < hi:
        mid = partition(arr, lo, hi)
        quick_sort(arr, lo, mid - 1)
        quick_sort(arr, mid + 1, hi)


def quick_sort_hoare(arr, lo, hi):
    if lo < hi:
        mid = hoare_partition(arr, lo, hi)
        quick_sort_hoare(arr, lo, mid)
        quick_sort_hoare(arr, mid + 1, hi)


def quick_sort_random(arr, lo, hi):
    if lo < hi:
        mid = randomized_partition(arr, lo, hi)
        quick_sort_random(arr, lo, mid-1)
        quick_sort_random(arr, mid + 1, hi)


def quick_sort_init(arr):
    quick_sort(arr, 0, len(arr) - 1)


def quick_sort_hoare_init(arr):
    quick_sort_hoare(arr, 0, len(arr) - 1)


def quick_sort_random_init(arr):
    quick_sort_random(arr, 0, len(arr) - 1)


def main():
    arr = []
    size = input('How many numbers do you want to sort? ')

    for i in range(int(size)):
        arr.append(random.randint(0, 100))

    print(arr)
    quick_sort_init(arr)
    print(arr)


if __name__ == "__main__":
    main()
