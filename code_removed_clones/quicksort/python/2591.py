'''Sort a given array using quicksort algoritm'''

import copy
import random


def quicksort(a):
    '''Perform a quicksort'''
    if not a:
        return
    if len(a)==1:
        return a

    pivot_index = random.randrange(0, len(a))
    pivot = a[pivot_index]
    i = j = 1

    # Swap the first element to the pivot
    if not pivot_index ==0:
        a[pivot_index] = a[0]
        a[0] = pivot

    while j <= len(a)-1:

        if a[j] < pivot:
            swap_variable = a[i]
            a[i] = a[j]
            a[j] = swap_variable
            i += 1
        j += 1

    temp = a[i-1]
    a[i-1] = pivot
    a[0] = temp

    left = quicksort(a[:i-1])
    right = quicksort(a[i:])
    new_array = []
    if left:
        new_array.extend(left)
    if pivot:
        new_array.append(pivot)
    if right:
        new_array.extend(right)

    return new_array

