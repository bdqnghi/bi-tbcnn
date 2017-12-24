# in place
def quicksort(l):
    def quicksort_helper(l, first, last):
        if first < last: 
            pivot = sort_and_return_partition(l, first, last)
            # print l
            # pivot is in place, so don't need to touch it anymore
            quicksort_helper(l, first, pivot-1)
            quicksort_helper(l, pivot+1, last)

    # sorts l between first and last and returns a new pivot
    def sort_and_return_partition(l, first, last): 
        pivotval = l[first]
        lefti = first + 1 # left index
        righti = last # right index

        while lefti <= righti:
            while l[lefti] <= pivotval and lefti <= righti:
                lefti += 1
            while l[righti] >= pivotval and lefti <= righti:
                righti -= 1
            # at this point, lefti and righti are pointing to values that should be swapped
            # or lefti > righti
            if lefti > righti:
                break
            # if lefti > righti, swap values
            temp = l[lefti]
            l[lefti] = l[righti]
            l[righti] = temp
            lefti += 1
            righti -= 1
            # continue with while loop
        
        # at this point, lefti > righti. 
        # righti is pointing to an element smaller than the first element
        # Place in the pivot value, then return new pivot index. 

        # temp = l[righti]
        # l[righti] = pivotval
        # l[first] = temp
        l[righti], l[first] = l[first], l[righti]
        return righti # return an index value

    quicksort_helper(l, 0, len(l) - 1)
    return l

# this takes up extra space for the lists
# returns a new list, sorted. original list unchanged. 
def sort(array):
    less = []
    equal = []
    greater = []
    new_list = []

    if len(array) > 1:
        pivotval = array[0]
        for x in array:
            if x < pivotval:
                less.append(x)
            if x == pivotval:
                equal.append(x)
            if x > pivotval:
                greater.append(x)
        return sort(less) + equal + sort(greater)
    else:  # You need to hande the part at the end of the recursion - when you only have one element in your array, just return the array.
        return array

def main():
    a = [12,4,5,6,7,3,1,15]
    print sort(a)
    print a
    print quicksort(a)

if __name__ == "__main__":
    main()