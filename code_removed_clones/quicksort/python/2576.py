import random


def hoare_partition(ls, p, r):
    x = ls[p]
    i = p-1
    j = r+1
    while True:
        j=j-1
        while ls[j] > x:
            j=j-1
        i=i+1
        while ls[i] < x:
            i=i+1
        if i < j:
            ls[i], ls[j] = ls[j], ls[i]
        else:
            return j

def quicksort_hoare(ls, p, r):
    if p < r:
        q = hoare_partition(ls, p, r)
        # Hoare's partitioning algorithm puts the pivot element
        # in one of the partitions.
        quicksort_hoare(ls, p, q)
        quicksort_hoare(ls, q+1, r)


def partition(ls, p, r):
    x = ls[r]
    i = p-1
    for j in range(p, r):
        if ls[j] <= x:
            i = i+1
            ls[j], ls[i] = ls[i], ls[j]
    ls[r], ls[i+1] = ls[i+1], ls[r]
    return i+1

def quicksort(ls, p, r):
    if p < r:
        q = partition(ls, p, r)
        # The simple partitioning algorithm puts the pivot element
        # exactly between the partitions.
        quicksort(ls, p, q-1)
        quicksort(ls, q+1, r)

def partition_eq(ls, p, r):
    x = ls[r]
    i = p-1
    l = r
    j = p
    while j < l:
        if ls[j] < x:
            i = i+1
            ls[j], ls[i] = ls[i], ls[j]
            j = j+1
        elif ls[j] == x:
            l = l-1
            ls[l], ls[j] = ls[j], ls[l]
        elif ls[j] > x:
            j = j+1
    q = i+1
    while l <= r:
        ls[q], ls[l] = ls[l], ls[q]
        l = l+1
        q = q+1
    return (i+1, q)

def quicksort_eq(ls, p, r):
    if p < r:
        (q, t) = partition_eq(ls, p, r)
        # partition_eq puts elements equal to the pivot in [q...r-1]
        # and ignores them during the sorting procedure.
        quicksort_eq(ls, p, q-1)
        quicksort_eq(ls, t, r)


ls = [13,19,19,21,12,4,4,4,11,2,6,13]
#quicksort(ls, 0, len(ls)-1)
#ls = [5,6,6,6,13,5,1,6]
#ls = [6,6,6,6,6,6,6,6]
ls = random.sample(range(10000), 10000)
j = quicksort_eq(ls, 0, len(ls)-1)
print str((j, ls))
