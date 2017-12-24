def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) / 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + (middle) + quicksort(right)

print quicksort([3, 5, 6, 7, 8, 9, 3, 4, 5, 6, 7, 8, 3, 2, 4, 5 ,4, 3, 2])

