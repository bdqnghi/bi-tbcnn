inversions = 0

def merge(l, r):
    global inversions

    left_len = len(l)
    right_len = len(r)

    merged = []
    merged_len = left_len + right_len

    l_idx = 0
    r_idx = 0

    for i in range(0, merged_len):
        if r_idx >= right_len:
            merged.append(l[l_idx])
            l_idx+=1
        elif l_idx >= left_len:
            merged.append(r[r_idx])
            r_idx+=1
        elif l[l_idx] <= r[r_idx]:
            merged.append(l[l_idx])
            l_idx+=1
        else:
            inversions += (left_len - l_idx)
#            print "incremented by %d for %d" % (left_len - l_idx, r[r_idx])
            merged.append(r[r_idx])
            r_idx+=1

    return merged


def mergesort(int_list):
    global inversions

    length = len(int_list)
    
    if (length == 1):
        return int_list
    elif (length == 2):
        if int_list[0] <= int_list[1]:
            return int_list
        else:
#            print "incremented by 1 for %d" % int_list[1]
            inversions += 1
            return [int_list[1],int_list[0]]

    mid = length/2
    left_list = int_list[:mid+1]
    right_list = int_list[mid+1:]

    left_list_sorted = mergesort(left_list)
    right_list_sorted = mergesort(right_list)
    
    merged_sorted_list = merge(left_list_sorted, right_list_sorted)

    return merged_sorted_list

def err_str_gen(int_list):
    err_str = "Wrong # of inversions for "+ str(int_list)
    return err_str

def test():
    global inversions

#    int_list = [2, 5, 1, 20, 8, 4, 3, -10]
    int_list = [1,3,5,2,4,6]
    inversions = 0
    mergesort(int_list)
    assert(inversions == 3), err_str_gen(int_list)

    int_list = [1,2,3,4,5,6]
    inversions = 0
    mergesort(int_list)
    assert(inversions == 0), err_str_gen(int_list)
    
    int_list = [1,5,3,2,4]
    inversions = 0
    mergesort(int_list)
    assert(inversions == 4), err_str_gen(int_list)

    int_list = [5,4,3,2,1]
    inversions = 0
    mergesort(int_list)
    assert(inversions == 10), err_str_gen(int_list)

    int_list = [1,6,3,2,4,5]
    inversions = 0
    mergesort(int_list)
    assert(inversions == 5), err_str_gen(int_list)
    
    int_list = [1]
    inversions = 0
    mergesort(int_list)
    assert(inversions == 0), err_str_gen(int_list)

def load_integers_into_list(filename):
    l = []

    f = open(filename, 'r')

    for line in f:
        l.append(int(line))

    f.close()

    return l

if __name__ == "__main__":
    int_list = load_integers_into_list('IntegerArray.txt')
    inversions = 0
    mergesort(int_list)

    print inversions
