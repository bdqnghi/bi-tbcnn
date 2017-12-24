# 快速排序


# 递归方式
def quick_sort(data, start, end):
    # print('Use quick sort with recursion'
    if start >= end:
        return
    mid = partition(data, start, end)
    quick_sort(data, start, mid)
    quick_sort(data, mid + 1, end)


# 非递归方式
def quick_sort2(data, start, end):
    print('Use quick sort without recursion')
    sub_sequences = [(start, end)]
    while sub_sequences:
        i, j = sub_sequences.pop()
        mid = partition(data, i, j)
        if mid > i:
            sub_sequences.append((i, mid))
        if j > mid + 1:
            sub_sequences.append((mid + 1, j))


def partition(data, start, end):
    basic = data[start]
    left, right = start, end
    while left < right:
        while left < right and data[right] >= basic:
            right -= 1
        data[left] = data[right]
        while left < right and data[left] <= basic:
            left += 1
        data[right] = data[left]
    data[left] = basic
    return left


if __name__ == '__main__':
    import random

    data = [i for i in range(100)]
    random.shuffle(data)
    print('src', data)
    # data = [1, 8, 5, 2, 3]
    quick_sort2(data, 0, len(data) - 1)
    print('after sort:', data)
