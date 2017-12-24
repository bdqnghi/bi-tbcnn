from collections import deque


def merge_sort(lst):
    """Sort list using the mergesort method."""
    half = len(lst) // 2
    left_side = lst[:half]
    right_side = lst[half:]

    while left_side and right_side:
        if left_side:
            merge_sort(left_side)
        if right_side:
            merge_sort(right_side)

        i = 0
        left_side = deque(left_side)
        right_side = deque(right_side)
        while left_side and right_side:
            if left_side[0] > right_side[0]:
                lst[i] = right_side.popleft()
            else:
                lst[i] = left_side.popleft()
            i += 1

        for side in (left_side, right_side):
            while side:
                lst[i] = side.popleft()
                i += 1


if __name__ == "__main__":
    import timeit
    from random import randint
    times = 500

    def test1():
        merge_sort([2, 1])

    def test2():
        merge_sort([randint(0, 1000000) for i in range(1000)])

    avg_time = timeit.Timer(test1).timeit(times)
    avg_time_big = timeit.Timer(test2).timeit(times)

    print("""Merge sort recursively splits the list in half and creates
a new list by comparing items from left to right in each of those lists.""")
    print("""Best case is an already sorted list.
        Best case time complexity is O(nlogn). This is roughtly the same as
        worst case""")
    print()

    print("Input: [2, 1]")
    print("\tnumber of runs: {}".format(times))
    print("\taverage time  : {}".format(avg_time))
    print()
    print("Input: [randint(0, 1000000) for i in range(1000)]")
    print("\tnumber of runs: {}".format(times))
    print("\taverage time  : {}".format(avg_time_big))
