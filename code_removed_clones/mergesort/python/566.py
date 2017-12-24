# Sorting a List using Mergesort in Python

def mergeSort(toSort):
    """
    This is the main mergesort funcition.
    """
    if len(toSort) <= 1:
        return toSort

    mIndex = len(toSort) / 2
    left = mergeSort(toSort[:mIndex])
    right = mergeSort(toSort[mIndex:])

    result = []
    while len(left) > 0 and len(right) > 0:
        if left[0] > right[0]:	
            result.append(right.pop(0))
        else:
            result.append(left.pop(0))

    if len(left) > 0:
        result.extend(mergeSort(left))
    else:
        result.extend(mergeSort(right))

    return result


if __name__ == '__main__':
    l = [1, 6, 7, 2, 76, 45, 23, 4, 8, 12, 11]
    sortedList = mergeSort(l)
    print sortedList
