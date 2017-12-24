# Knapsack problem
import numpy
from collections import namedtuple

element = namedtuple('element', 'value weight')


def knapsack(a, v):
    W = len(v)
    n = len(a)

    for i, e in enumerate(a):
        for x in range(0, W+1):
            a[i][x] = max(a[i-1][x],
                          e.value + a[i-1][x - e.weight])

    return a


def import_file(f='test10'):
    f = open(f, 'r')

    l = f.readline().strip().split(' ')

    n = int(l[1])
    W = int(l[0])

    a = [[0] * (n + 1)] * W
    v = []
    for i, line in enumerate(f.readlines()):
        line = line.strip().split(' ')
        v.append((element(int(line[0]), int(line[1]))))
    return a, v


if __name__ == '__main__':
    a, v = import_file()

    a = knapsack(a, v)
    print(a)
    print(v)
