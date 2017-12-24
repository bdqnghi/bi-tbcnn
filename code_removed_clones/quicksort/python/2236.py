# implemented from the pseudocode in Wikipedia

def partition(A, lo, hi):
    pivot = A[hi]
    i = lo
    for j in range(lo, hi):
        if A[j] < pivot:
            A[i], A[j] = A[j], A[i]
            i += 1
    A[i], A[hi] = A[hi], A[i]
    return(i)

def quicksort(A, lo, hi):
    if lo < hi:
        p = partition(A, lo, hi)
        quicksort(A, lo, p-1)
        quicksort(A, p+1, hi)

# testing
bases = [
[],
[1],
[1,2,3,4,5],
[2,1],
[4,1,7,32,9,1,0.5]
]

for base in bases:
    quicksort(base, 0, len(base)-1)
    print(base)
