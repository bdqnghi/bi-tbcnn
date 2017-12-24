#!/usr/bin/env python

'''
Bubblesort - Not my favorite interview question because it is an O(n**2) operation, and really, who uses it outside of a 1st year CS student.
However, it does illustrate basic concepts of sorting and allows one to easily look at an algorithm and do analysis on the runtime.

Runtime O(n**2)
Space O(n)

So we can see a list as small as three elements takes 9 iterations or 3**2 to be sorted.

Python 2.7.3 (default, Apr 20 2012, 22:44:07) 
[GCC 4.6.3] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> import random
>>> execfile('bubblesort.py')
>>> bubblesort([random.randint(1,10) for i in range(3)])
i	j	l
0	0	[8, 3, 9]
0	1	[8, 3, 9]
0	2	[8, 3, 9]
1	0	[9, 3, 8]
1	1	[3, 9, 8]
1	2	[3, 9, 8]
2	0	[3, 9, 8]
2	1	[3, 9, 8]
2	2	[3, 8, 9]
[3, 8, 9]

We can further refine this, eliminating the comparison of an element with itself and only performing
n-1 comparisons when passed an already sorted list, however n**2 - n still yields O(n**2) for the worst case runtime
as n**2 quickly outstrips any gains made as n tends towards infinity.

>>> bubblesort2([random.randint(1,10) for i in range(3)])
0	1	[5, 5, 7]
1	2	[5, 5, 7]
[5, 5, 7]
>>> bubblesort2([random.randint(1,10) for i in range(3)])
0	1	[10, 2, 3]
1	2	[2, 10, 3]
0	1	[2, 3, 10]
1	2	[2, 3, 10]
[2, 3, 10]
'''

def showstate(i, j, l):
    print '%d\t%d\t%s' % (i, j, l)

def bubblesort(l):
    '''bubblesort(l) - inefficiently sort a list'''
    i = 0
    print 'i\tj\tl'
    while i < len(l):
        j = 0
        while j < len(l):
            showstate(i,j,l)
            if l[j] > l[i]:
                l[i], l[j] = l[j], l[i]
            j += 1
        i += 1
    return l

def bubblesort2(l):
    is_sorted = False
    while not is_sorted:
        is_sorted = True
        for i in range(len(l)-1):
            showstate(i, i+1, l)
            if l[i] > l[i+1]:
                l[i], l[i+1] = l[i+1], l[i]
                is_sorted = False
    return l
