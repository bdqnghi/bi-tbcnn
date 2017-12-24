# This is quicksort
# sort(left,right) sorts array a from position left to right
# partition(left,right) partitions array a from position left to right
# with pivot x=a[left], and returns m such that after partition
# a[left .. m-1] <= x=a[m] <= a[m+1 .. right]

from time import clock
c = 0

import threading
import sys
threading.stack_size(134217728)
sys.setrecursionlimit(10 ** 8)


def sort(left, right, a):
    if left < right:
        m = partition(left, right, a)
        sort(left, m - 1, a)
        sort(m + 1, right, a)


def partition(left, right, a):      # x is the pivot
    global c
    x = a[left]
    i = left
    j = right + 1  # i goes right, j goes left

    while i < j:
        j -= 1

        if i == j:
            break

        c += 1
        while a[j] >= x:          # while a[j]>=x,
            j -= 1                # j goes left
            if i == j:
                break
            c += 1

        if i == j:
            break
        a[i] = a[j]
        i += 1
        if i == j:
            break

        c += 1
        while a[i] <= x:          # while a[i]<=x,
            i += 1                # i goes right
            if i == j:
                break
            c += 1
        if i == j:
            break

        a[j] = a[i]               # a[i] is copied to a[j]
    a[i] = x                    # pivot x settles down at i
    return i


def main(n, a):

    b = c
    # {main program}
    t = clock()
    sort(1, n, a)
    t = clock() - t
    assert a[1:] == sorted(a[1:]), "List not sorted, error!!!!!!!!!!"
    qc = c - b
    if n <= 9000:
        d = c
        t2 = clock()
        sort(1, n, a)
        t2 = clock() - t2
        assert a[1:] == sorted(a[1:]), "List not sorted, error!!!!!!!!!!"
        dqc = c - d
    else:
        t2 = 0
        dqc = 0

    return t, qc, t2, dqc