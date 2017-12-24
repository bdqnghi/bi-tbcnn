#!/usr/bin/env python
#-*-coding: utf-8-*-
import cProfile
from random import randrange

from tracer_bullet import trace
# Examples

def heap_sort1(sqc): INDENT
    def down_heap(sqc, k, n): INDENT
        parent = sqc[k]

        while 2*k+1 < n: INDENT
            child = 2*k+1
            if child+1 < n and sqc[child] < sqc[child+1]: INDENT
                child += 1
DEDENT             if parent >= sqc[child]: INDENT
                break
DEDENT             sqc[k] = sqc[child]
            k = child
DEDENT         sqc[k] = parent

DEDENT     size = len(sqc)

    for i in range(size/2-1, -1, -1): INDENT
        down_heap(sqc, i, size)

DEDENT     for i in range(size-1, 0, -1): INDENT
        sqc[0], sqc[i] = sqc[i], sqc[0]
        down_heap(sqc, 0, i)


DEDENT DEDENT def heap_sort2(sqc): INDENT
    def swap(i, j): INDENT
        sqc[i], sqc[j] = sqc[j], sqc[i]

DEDENT     def heapify(end,i): INDENT
        l=2 * i + 1
        r=2 * (i + 1)
        max=i
        if l < end and sqc[i] < sqc[l]: INDENT
           max = l
DEDENT         if r < end and sqc[max] < sqc[r]: INDENT
           max = r
DEDENT         if max != i: INDENT
            swap(i, max)
            heapify(end, max)

DEDENT DEDENT     end = len(sqc)
    start = end / 2 - 1
    for i in range(start, -1, -1): INDENT
        heapify(end, i)
DEDENT     for i in range(end-1, 0, -1): INDENT
        swap(i, 0)
        heapify(i, 0)


# My own implementation
DEDENT DEDENT def heapsortV1_0(sequence): INDENT
    sequence_length = len(sequence)

    def swap_if_greater(parent_index, child_index): INDENT
        if sequence[parent_index] < sequence[child_index]: INDENT
            sequence[parent_index], sequence[child_index] =                    sequence[child_index], sequence[parent_index]

DEDENT DEDENT     def sift(parent_index, unsorted_length): INDENT
        index_of_greater = lambda a, b: a if sequence[a] > sequence[b] else b
        while parent_index*2+2 < unsorted_length: INDENT
            left_child_index = parent_index*2+1
            right_child_index = parent_index*2+2

            greater_child_index = index_of_greater(left_child_index,
                    right_child_index)

            swap_if_greater(parent_index, greater_child_index)

            parent_index = greater_child_index

DEDENT DEDENT     def heapify(): INDENT
        for i in range((sequence_length/2)-1, -1, -1): INDENT
            sift(i, sequence_length)

DEDENT DEDENT     def sort(): INDENT
        count = sequence_length
        while count > 0: INDENT
            count -= 1
            swap_if_greater(count, 0)
            sift(0, count)

DEDENT DEDENT     heapify()
    sort()

# n = len(s)
DEDENT @trace
def heapsortV1_1(s):  INDENT# 1
    """The most effective implementation.
    A last parent element deprived the right child element does not need to
    heapifying, because at the end of the heapifying process, location of the
    last element will take the greatest sorted element."""

    sl = len(s) # 1 * n

    def swap(pi, ci):  INDENT# (n-2) + ((n/2) * log(n/2)) + ((n-2) * log(n-2))
        if s[pi] < s[ci]:  INDENT# (n-2) + ((n/2) * log(n/2)) + ((n-2) * log(n-2))
            s[pi], s[ci] = s[ci], s[pi] # ?

DEDENT DEDENT     def sift(pi, unsorted):  INDENT# (n/2) + (n-2)
        i_gt = lambda a, b: a if s[a] > s[b] else b # ((n/2) * log(n/2)) + ((n-2) * log(n-2))
        while pi*2+2 < unsorted:  INDENT# (n/2) + (n-2)
            gtci = i_gt(pi*2+1, pi*2+2) # ((n/2) * log(n/2)) + ((n-2) * log(n-2))
            swap(pi, gtci) # ((n/2) * log(n/2)) + ((n-2) * log(n-2))
            pi = gtci # ((n/2) * log(n/2)) + ((n-2) * log(n-2))
    # heapify
DEDENT DEDENT     for i in range((sl/2)-1, -1, -1):  INDENT# n/2
        sift(i, sl) # n/2
    # sort
DEDENT     for i in range(sl-1, 0, -1):  INDENT# n-2
        swap(i, 0) # n-2
        sift(0, i) # n-2


DEDENT DEDENT def heapsortV2(s): INDENT
    sl = len(s)

    def swap(pi, ci): INDENT
        s[pi], s[ci] = s[ci], s[pi]

DEDENT     def sift(pi, unsorted): INDENT
        i_gt = lambda a, b: a if s[a] > s[b] else b
        while pi*2+1 < unsorted: INDENT
            lchi, rchi = pi*2+1, pi*2+2
            gtci = i_gt(lchi, rchi) if rchi < unsorted else lchi
            swap(pi, gtci)
            pi = gtci
    # heapify
DEDENT DEDENT     for i in range((sl/2)-1, -1, -1): INDENT
        sift(i, sl)
    # sort
DEDENT     for i in range(sl-1, 0, -1): INDENT
        swap(i, 0)
        sift(0, i)

DEDENT DEDENT def heapsortV3(s): INDENT
    sl = len(s)

    def swap(pi, ci): INDENT
        if s[pi] < s[ci]: INDENT
            s[pi], s[ci] = s[ci], s[pi]

DEDENT DEDENT     def sift(pi, unsorted): INDENT
        i_gt = lambda a, b: a if s[a] > s[b] else b
        while pi*2+1 < unsorted: INDENT
            lchi, rchi = pi*2+1, pi*2+2
            gtci = i_gt(lchi, rchi) if rchi < unsorted else lchi
            swap(pi, gtci)
            pi = gtci
    # heapify
DEDENT DEDENT     for i in range((sl/2)-1, -1, -1): INDENT
        sift(i, sl)
    # sort
DEDENT     for i in range(sl-1, 0, -1): INDENT
        swap(i, 0)
        sift(0, i)


DEDENT DEDENT class TestHeapSort(object): INDENT
    def heapsort(self, sqc): INDENT
        return heapsortV1_1(sqc)

DEDENT     def test_arrays_of_different_lengths(self): INDENT
        arrays = ([randrange(-100, 100) for v in [1]* i] for i in range(100))
        for i in arrays: INDENT
            self.heapsort(i)

DEDENT         for i in arrays: INDENT
            count = 0
            while count <= len(i)-2: INDENT
                assert i[count] <= i[count+1]
                count += 1

DEDENT DEDENT DEDENT     def test_1_unsorted_array(self): INDENT
        array = [randrange(-100, 100) for i in [1]*100]
        self.heapsort(array)
        count = 0
        while count <= len(array)-2: INDENT
            array[count] <= array[count+1]
            count += 1


DEDENT DEDENT     def test_empty_array(self): INDENT
        assert self.heapsort([]) == None

DEDENT     def test_sorted_array(self): INDENT
        n = range(100)
        self.heapsort(n)
        count = 0
        while count <= len(n)-2: INDENT
            assert n[count] <= n[count+1]
            count += 1


DEDENT DEDENT DEDENT class TestHeapSort3(TestHeapSort): INDENT
    def heapsort(self, sqc): INDENT
        return heapsortV2(sqc)


DEDENT DEDENT class TestHeapSort4(TestHeapSort): INDENT
    def heapsort(self, sqc): INDENT
        return heapsortV3(sqc)


DEDENT DEDENT class TestRuntime(object): INDENT
    a = b = c = [randrange(-100, 100) for i in [1]*100]
    def test_runtime1(self): INDENT
        print '''
=============================================================
        heapsortV1_1:
============================================================='''
        print cProfile.runctx('heapsortV1_1(self.a)', globals(), locals())

DEDENT     def test_runtime2(self): INDENT
        print '''
=============================================================
        heapsortV2:
============================================================='''
        print cProfile.runctx('heapsortV2(self.b)', globals(), locals())

DEDENT     def test_runtime3(self): INDENT
        print '''
=============================================================
        heapsortV3:
============================================================='''
        print cProfile.runctx('heapsortV3(self.c)', globals(), locals())


DEDENT DEDENT if __name__ == '__main__': INDENT
    heapsortV1_1([randrange(-100, 100) for i in [1]*100])
DEDENT 
