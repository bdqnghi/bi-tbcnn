"""
mergesort.py 
Logan Davis

    Part of my Mid-term

2/27/15 | Python 2.7 | MIT License 
"""
def mergesort(array):
    """
    This function merge sorts an array.
    Arguments (1):
        array = the list you with to have sorted.
    Returns (1):
        it returns a sorted version of array.
    ----------------------------------------------
    EXAMPLE:
    >>> array = [3,6,5,8,2,4556]
    >>> mergesort(array)
    [2,3,5,6,8,4556]
    """
    length = len(array)
    index_right,index_left,max_right,max_left = 0,0,0,0
    merged = False
    sorted_list = []
    if length <= 1:
        return array
    else:
        midpoint = length/2
        rightside = mergesort(array[midpoint:])
        leftside = mergesort(array[:midpoint])
        max_left = (len(leftside))
        max_right = (len(rightside))
        while not merged:
            if index_left != max_left and index_right != max_right:
                if leftside[index_left] < rightside[index_right]:
                    sorted_list.append((leftside[index_left]))
                    index_left += 1
                elif rightside[index_right] < leftside[index_left]:
                    sorted_list.append((rightside[index_right]))
                    index_right += 1
                elif leftside[index_left] == rightside[index_right]:
                    sorted_list.append(rightside[index_right])
                    sorted_list.append(leftside[index_left])
                    index_right += 1
                    index_left += 1
            elif index_left == max_left and index_right != max_right:
                sorted_list.append(rightside[index_right])
                index_right += 1
            elif index_left != max_left and index_right == max_right:
                sorted_list.append(leftside[index_left])
                index_left += 1
            else:
                merged = True
        return sorted_list
