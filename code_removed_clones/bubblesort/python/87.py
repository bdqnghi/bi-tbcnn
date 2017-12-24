"""Bubble sort.
Worst and Average case: O(n^2) .
Best case: O(n).
Space efficiency: O(1)"""

def bubble_sort(arr):
    if not arr:
        return

    end = len(arr) - 1
    pos = 0
    while end > 0:
        newEnd = 0
        left = arr[pos]
        right = arr[pos + 1]
        if left > right:
            arr[pos] = right
            arr[pos + 1] = left
            newEnd = pos
            #all elements after the last swap are sorted so this position
            #becomes the end
        pos += 1
        if pos >= end:
            pos = 0
            end = newEnd
    return arr
