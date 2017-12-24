

r"""

# Try constructing a heap and popping its elements

>>> h = Heap()
>>> h.add(5, "Foo")
>>> h.pop()
(5, 'Foo')
>>> h.empty()
True

# Intertwining insertions and deletions

>>> h = Heap()
>>> h.add(7, "Bar")
>>> h.add(15, "Baz")
>>> h.pop()
(7, 'Bar')
>>> h.pop()
(15, 'Baz')
>>> h.empty()
True
>>> h.add(9, "Bam")
>>> h.add(7, "Bar")
>>> h.add(15, "Baz")
>>> h.add(5, "Foo")
>>> h.pop()
(5, 'Foo')
>>> h.add(3, "Frap")
>>> h.pop()
(3, 'Frap')
>>> h.pop()
(7, 'Bar')
>>> h.add(8, "Murk")
>>> h.pop()
(8, 'Murk')
>>> h.pop()
(9, 'Bam')
>>> h.pop()
(15, 'Baz')

# Heapifying input

>>> h = Heap([(5,5),(9,9),(2,2),(8,8),(4,4),(6,6),(3,3),(1,1)])
>>> h.size()
8
>>> h.pop()
(1, 1)
>>> h.pop()
(2, 2)
>>> h.pop()
(3, 3)
>>> h.pop()
(4, 4)
>>> h.pop()
(5, 5)
>>> h.pop()
(6, 6)
>>> h.pop()
(8, 8)
>>> h.pop()
(9, 9)

"""

class Heap(object): INDENT
    _array = list([None])

    def __init__(self, initial=None): INDENT
        if initial is None: INDENT
            self._array = [None]
DEDENT         else: INDENT
            self._array = [None] + initial
            for i in xrange(len(initial) / 2, 0, -1): INDENT
                self._heapify(i)

DEDENT DEDENT DEDENT     def _swap(self, index): INDENT
        parent_index = index / 2
        (self._array[index], self._array[parent_index]) =                 (self._array[parent_index], self._array[index])

DEDENT     def _upheap(self, index): INDENT
        parent_index = index / 2
        if parent_index == 0: INDENT
            return
DEDENT         if self._array[parent_index][0] > self._array[index][0]: INDENT
            self._swap(index)
            self._upheap(parent_index)

DEDENT DEDENT     def _downheap(self, index): INDENT
        left_child_index = index * 2
        right_child_index = index * 2 + 1
        if right_child_index < len(self._array): INDENT
            (min_value, min_index) = min(
                    (self._array[left_child_index][0],
                        left_child_index),
                    (self._array[right_child_index][0],
                        right_child_index))
            if min_value < self._array[index]: INDENT
                self._swap(min_index)
                self._downheap(min_index)
DEDENT DEDENT         else: INDENT
            if left_child_index < len(self._array): INDENT
                if self._array[left_child_index][0] <                         self._array[index][0]: INDENT
                    self._swap(left_child_index)

DEDENT DEDENT DEDENT DEDENT     def _heapify(self, index): INDENT
        left_child_index = index * 2
        right_child_index = index * 2 + 1
        if left_child_index > len(self._array): INDENT
            return
DEDENT         if right_child_index < len(self._array): INDENT
            (min_value, min_index) = min(
                    (self._array[left_child_index][0],
                        left_child_index),
                    (self._array[right_child_index][0],
                        right_child_index))
            if min_value < self._array[index][0]: INDENT
                self._swap(min_index)
                self._heapify(min_index)
DEDENT DEDENT         elif left_child_index < len(self._array): INDENT
            if self._array[left_child_index][0] <                     self._array[index][0]: INDENT
                self._swap(left_child_index)
                self._heapify(left_child_index)

DEDENT DEDENT DEDENT     def add(self, key, value): INDENT
        self._array.append((key, value))
        self._upheap(len(self._array) - 1)

DEDENT     def pop(self): INDENT
        if self.empty(): INDENT
            raise IndexError, 'Can\'t pop from empty heap'
DEDENT         try: INDENT
            return self._array[1]
DEDENT         finally: INDENT
            self._array[1] = self._array[-1]
            self._array.pop()
            self._downheap(1)

DEDENT DEDENT     def size(self): INDENT
        return len(self._array) - 1

DEDENT     def empty(self): INDENT
        return len(self._array) == 1


DEDENT DEDENT 
