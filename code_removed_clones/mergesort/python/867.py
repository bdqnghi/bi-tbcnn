
"conquer"
def merge(left, right):
    result = []
    i,j = 0,0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1
    if i < len(left):
        result.extend(left[i:])
    if j < len(right):
        result.extend(right[j:])
    return result

"divide"
def mergesort(ls):
    if len(ls) <= 1:
        return ls

    middle = len(ls)/2
    left = mergesort(ls[0:middle])
    right = mergesort(ls[middle:])
    return merge(left, right)

