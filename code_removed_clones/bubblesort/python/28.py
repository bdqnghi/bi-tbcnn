"""
Author: Alan Lai

Task:
Implements bubble sort algorithm

>>> bubble_sort([2, 3, 4, 1])
[1, 2, 3, 4]
>>> bubble_sort([1])
[1]
"""


def bubble_sort(nums):
    sorted = False
    while not sorted:
        sorted = True
        for i in range(1, len(nums)):
            if nums[i - 1] > nums[i]:
                sorted = False
                nums[i - 1], nums[i] = nums[i], nums[i - 1]
    return nums


if __name__ == '__main__':
    import doctest
    doctest.testmod()
