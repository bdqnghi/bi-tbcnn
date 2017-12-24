from operator import itemgetter
class Heap: INDENT
        def __init__(self): INDENT
                """Implementation of a min-heap."""
                self.heapArray = []

DEDENT         def add(self, item, heapValue): INDENT
                """Adds a value to the heap. Item is a label, heapValue is its corresponding value."""
                heapEntry = (item, heapValue)
                self.heapArray.append(heapEntry)
                self._siftUp(heapEntry)

DEDENT         def pop(self): INDENT
                """Removes the top entry in the heap (the entry with the minimum value)
		   and reorders the heap."""

                 # Should throw exception if list is empty
                popped_value = self.heapArray[0]
                new_root = self.heapArray.pop()
                if self.getSize() == 0: INDENT
                        return popped_value[0]
DEDENT                 self.heapArray[0] = new_root
                self._siftDown(new_root)
                return popped_value[0]

DEDENT         def getSize(self): INDENT
                """Returns the size of the heap."""
                return len(self.heapArray)

DEDENT         def _siftUp(self, heapEntry): INDENT
                parent = self._parent(heapEntry)
                if parent == None or heapEntry[1] > parent[1]: INDENT
                        return
DEDENT                 else: INDENT
                        self._swap(heapEntry, parent)
                        self._siftUp(heapEntry)

DEDENT DEDENT         def _siftDown(self, heapEntry): INDENT
                children = self._children(heapEntry)
                if children[0] == None: INDENT
                        return
DEDENT                 elif children[1] == None: INDENT
                        minChild = children[0]
DEDENT                 else: INDENT
                        minChild = sorted(children, key = itemgetter(1))[0]
DEDENT                 if heapEntry[1] < minChild[1]: INDENT
                        return
DEDENT                 else: INDENT
                        self._swap(heapEntry, minChild)
                        self._siftDown(heapEntry)


DEDENT DEDENT         def _swap(self, heapEntry1, heapEntry2): INDENT
                ## This is extremely inefficient. Re-write without the call to List.index
                ## List.index is O(n) in the length of the list.
                """Swaps the position of two entries in the heap."""
                first_index = self.heapArray.index(heapEntry1)
                second_index = self.heapArray.index(heapEntry2)
                self.heapArray[first_index] = heapEntry2
                self.heapArray[second_index] = heapEntry1

DEDENT         def _parent(self, heapEntry): INDENT
                """Returns the parent of the given heap entry."""
                index = self.heapArray.index(heapEntry)
                ## Best practices: Avoid multiple points of return
                if index == 0: INDENT
                        return None
DEDENT                 parent = self.heapArray[(index - 1)/2]
                return parent

DEDENT         def _children(self, heapEntry): INDENT
                """Returns a list of the children of the given heapEntry.
			List will contain None in entries with no child present."""
                ## Return a tuple not a list. Tuples more memory efficient, and immutable -
                ## both benefits for this use case
                index = self.heapArray.index(heapEntry)
                childIndex = (2*index) + 1
                childList = [] # Do not build up, introduces room for errors. Instead assign all at once.
                ## This is extremely inefficient. Just use arithmetic not data structures.
                ## This adds a needless O(n) factor to your code. Should be O(1)
                allEntries = xrange(len(self.heapArray))
                ## Avoid multiple points of return
                if childIndex not in allEntries: INDENT
                        childList = [None, None] # Good (but use tuple instead)
                        return childList
DEDENT                 childList.append(self.heapArray[childIndex])
                if (childIndex + 1) not in allEntries: INDENT
                        childList.append(None) # Bad, very bad, needless confusion
                        return childList
DEDENT                 childList.append(self.heapArray[childIndex + 1])
                return childList
                # Totally refactor this code to run in O(1) with a single return point


DEDENT DEDENT def mkHeap(*arg): INDENT
        h = Heap()
        for item in arg: INDENT
                h.add(item[0], item[1])
DEDENT         return h

DEDENT def testHeap(): INDENT
        h = Heap()
        h.add('a', 3)
        h.add('b', 9)
        h.add('c', 4)
        assert h.pop() == 'a'
        assert h.pop() == 'c'
        assert h.pop() == 'b'
        assert h.getSize() == 0
DEDENT 
