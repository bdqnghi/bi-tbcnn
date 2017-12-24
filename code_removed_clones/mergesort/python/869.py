from collections import deque

def merge(left, right):
    if not left: return right
    if not right: return left
    if left[0] <= right[0]:
        return [left[0]] + merge(left[1:], right)
    else:
        return [right[0]] + merge(left, right[1:])

def mergesort(l):
    q = deque()
    for i in xrange(len(l)):
        q.append([l[i]])

    while len(q) > 1:
        q.append(merge(q.popleft(), q.popleft()))

    return q.popleft()


print mergesort([1,5,2,3,10,6])



