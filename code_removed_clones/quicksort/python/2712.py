"""
    Quickort algorithm implementation.
    Description: http://en.wikipedia.org/wiki/Quicksort
    
    This is a naive version that requires O(n) auxiliary space.
    The in-place version proposed by Sedgewick uses O(log n) space.
"""

def quicksort(x):
    if len(x) <= 1:
        return x
    pivot = x[0]
    left = quicksort([e for e in x[1:] if e < pivot])
    right = quicksort([e for e in x[1:] if e >= pivot])
    return left + [pivot] + right
