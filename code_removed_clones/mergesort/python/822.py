def merge_sort(a):
    l = 0
    r = len(a)
    if l < (r-1):
        mid = (l+r)//2
        a = merge(merge_sort(a[l:mid]), merge_sort(a[mid:r]))
    return a


def merge(l_arr, r_arr):
    a = []
    pos_l = 0
    pos_r = 0
    while (pos_l < len(l_arr)) and (pos_r < len(r_arr)):
        if l_arr[pos_l] < r_arr[pos_r]:
            a.append(l_arr[pos_l])
            pos_l += 1
        else:
            a.append(r_arr[pos_r])
            pos_r += 1
    if(pos_l < len(l_arr)):
        a.extend(l_arr[pos_l:])
    if(pos_r < len(r_arr)):
        a.extend(r_arr[pos_r:])
    return a
