import random
def _swap(l, i, j):
    temp = l[i]
    l[i] = l[j]
    l[j] = temp


def quicksort(l, p, r):
    if r - p > 0:
        q = partition(l, p, r)
        quicksort(l, p, q-1)
        quicksort(l, q+1, r)# DO LEAVE 'q' THERE


def partition(l, p, r):
    # ensure l[p:i] <= x;
    #        l[i:j] >= x;
    #        l[j:r] = unrestricted
    i = p
    pivot = l[r]
    for x in range(p, r):
        if l[x] <= pivot:
            _swap(l, i, x)
            i += 1
    _swap(l, i, r)
    return i


def randomized_quicksort(l, p, r):
    pivot_index = random.randint(p,r)
    _swap(l, pivot_index, r)
    quicksort(l, p, r)


if __name__ == "__main__":
    l = [3, 7, 4, 5, 11, 233, 5677, 8, 34, 56, 6]
    print(l)
    randomized_quicksort(l, 0, len(l)-1)
    print(l)