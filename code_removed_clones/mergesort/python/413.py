# This is mergesort
# mergesort(p,q) sorts array a from position p to q


from time import clock


c = 0


def mergesort(p, q, a, b):
    if p < q:
        m = int((p + q) / 2)
        mergesort(p, m, a, b)
        mergesort(m + 1, q, a, b)
        merge(p, m + 1, q + 1, a, b)

# merge(p,m,q) merges array a from position p to m
# and position m+1 to q


def merge(p, r, q, a, b):
    global c   # c is comparison counter
    i = p
    j = r
    k = p
    while i < r and j < q:
        c += 1
        if a[i] <= a[j]:
            b[k] = a[i]
            i += 1
        else:
            b[k] = a[j]
            j += 1
        k += 1
    while i < r:
        b[k] = a[i]
        i += 1
        k += 1
   
    while j < q:
        b[k] = a[j]
        j += 1
        k += 1
    for k in range(p, q):
        a[k] = b[k]


def main(n, a):
    d = c
    #{ main program }
    b = []
    for i in range(0, n + 1):
        b += [0]
    t = clock()
    mergesort(1, n, a, b)
    t = clock() - t
    assert a[1:] == sorted(a[1:]), "List not sorted, error!!!!!!!!!!"
    return t, c - d