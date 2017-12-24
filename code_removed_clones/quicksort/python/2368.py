def quick_sort(list, size):

    print 'Sorting list of size', size
    
    list_left  = []
    count_left = 0
    list_right = []
    count_right = 0
    pivot = [list[0]]
    sorted_list = []
    for i in range(1,len(list)):
        if (list[i]) > pivot[0]:
            list_right.append(list[i])
            count_right += 1
        elif (list[i] < pivot[0]):
            list_left.append(list[i])
            count_left += 1
        else:
            pivot = pivot + [list[i]]

    if count_left > 0:
        sorted_list = quick_sort(list_left, count_left) + pivot
    else:
        sorted_list = pivot

    if count_right > 0:
        sorted_list = sorted_list + quick_sort(list_right, count_right)

    return sorted_list
