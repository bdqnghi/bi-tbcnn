def mergesort(l):
    if len(l) == 1:
        return l
    else:
        left = mergesort(l[:len(l)/2])
        right = mergesort(l[len(l)/2:])
        return _merge(left, right)

def _merge(a, b):
    if not a:
        return b
    elif not b:
        return a
    elif a[0] < b[0]:
        return [a[0]] + _merge(a[1:], b)
    else:
        return [a[0]] + _merge(a, b[1:])


