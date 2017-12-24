# Merge Sort
# divide and conquer strategy
# reference: http://interactivepython.org/courselib/static/pythonds/SortSearch/TheMergeSort.html?highlight=merge%20sort

def merge(lefthalf, righthalf):
    '''
    this function is used to merge two list 
    '''

    i=0
    j=0
    k=0
    # copy lefthalf and righthalf to merged with sorted order
    merged = lefthalf + righthalf

    # left and righthalf may have different length
    while i < len(lefthalf) and j < len(righthalf):
        if lefthalf[i] < righthalf[j]:
            merged[k]=lefthalf[i]
            i=i+1
        else:
            merged[k]=righthalf[j]
            j=j+1
        k=k+1

    # Copy the remaining elements of left
    while i < len(lefthalf):
        merged[k]=lefthalf[i]
        i=i+1
        k=k+1

    # Copy the remaining elements of right
    while j < len(righthalf):
        merged[k]=righthalf[j]
        j=j+1
        k=k+1

    return merged

def mergesort(alist):

    if len(alist) == 0 or len(alist) == 1:
        return alist
    else:
        mid = len(alist)//2
        lefthalf = mergesort(alist[:mid])
        righthalf = mergesort(alist[mid:])
    return merge(lefthalf, righthalf)


if __name__ == '__main__':
    alist = [54,26,93,17,77,31,44,55,20]
    a = mergesort(alist)
    print (alist)
    print (a)

