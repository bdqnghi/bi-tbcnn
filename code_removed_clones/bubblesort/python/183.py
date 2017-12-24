from timeit import Timer
import random

def bubbleSort(alist):
  for passnum in range(len(alist)-1, 0, -1):
    for i in range(passnum):
      if alist[i] > alist[i+1]:
        temp = alist[i]
        alist[i] = alist[i+1]
        alist[i+1] = temp

def shortBubbleSort(alist):
  exchanges = True
  passnum = len(alist) - 1
  while passnum > 0 and exchanges:
    exchanges = False
    for i in range(passnum):
      if alist[i] > alist[i+1]:
        exchanges = True
        temp = alist[i]
        alist[i] = alist[i+1]
        alist[i+1] = temp
    passnum = passnum - 1

if __name__ == '__main__':
  alist = random.sample(xrange(100), 10)
  t1 = Timer("bubbleSort(alist)", "from __main__ import bubbleSort, alist")
  print alist
  print t1.timeit(number=1000), "ms"
  print alist
  t2 = Timer("shortBubbleSort(alist)", "from __main__ import shortBubbleSort, alist")
  print t2.timeit(number=1000), "ms"
