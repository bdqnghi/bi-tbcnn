# -*- encoding: UTF-8 -*-
# Binary heap (max-heap)
# (c) ane 2009 <ane@iki.fi>

import time, random

class Heap: INDENT
    def __init__(self): INDENT
        self.store = []
        self.count = 0
        
    # Inserts an element
DEDENT     def insert(self, element): INDENT
        self.store.append(element)
        self.ascend(-1)   
      
    # Ascends (sifts up) an item to the top
DEDENT     def ascend(self, loc): INDENT
        if loc < 0: INDENT
            child = len(self.store) - 1
DEDENT         else: INDENT
            child = loc
DEDENT         parent = self.parent(child)
        while parent < child and self.better(child, parent): INDENT
            self.swap(child, parent)
            child = parent
            parent = self.parent(child)
    
DEDENT DEDENT     def parent(self, child): INDENT
        if child == 0: INDENT
            return 0
DEDENT         return (child - 1) / 2
    
    # Swaps two items
DEDENT     def swap(self, a, b): INDENT
        self.store[a], self.store[b] = self.store[b], self.store[a]
    
    # A dummy comparison
DEDENT     def better(self, a, b, d=False): INDENT
        if d: print(a, b)
        return self.store[a] > self.store[b]

    # Returns the smaller child of node at position loc
DEDENT     def better_child(self, loc): INDENT
        a = 2*loc+1
        b = 2*loc+2
        count = len(self.store)
        if a < count and b < count: INDENT
            if self.better(a, b): INDENT
                return a
DEDENT             else: INDENT
                return b
DEDENT DEDENT         elif a < count: INDENT
            return a
DEDENT         else:  INDENT
            return loc
    
    # Sifts an item down
DEDENT DEDENT     def lower(self, loc): INDENT
        p = loc
        child = self.better_child(p)
        while p < child and self.better(child, p): INDENT
            self.swap(child, p)
            p = child
            child = self.better_child(p)
    
    # Heapifies the tree
DEDENT DEDENT     def heapify(self): INDENT
        start = int((len(self.store) - 2) / 2)
        while start >= 0: INDENT
            self.lower(start)
            start = start - 1

    # Adds an element 
DEDENT DEDENT     def push(self, element): INDENT
        self.store.append(element)
    
    # Removes the smallest element
DEDENT     def delete_min(self): INDENT
        if self.is_empty(): INDENT
            return None
DEDENT         res = self.store[0]
        last = self.store.pop()
        if not self.is_empty(): INDENT
            self.store[0] = last
            self.lower(0)
DEDENT         return res
   
DEDENT     def is_empty(self): INDENT
        return len(self.store) == 0
DEDENT     def min(self): INDENT
        return self.store[0]
DEDENT     def items(self): INDENT
        return self.store
    
DEDENT DEDENT if __name__ == '__main__': INDENT
    times = []
    heap = Heap()
    bla = range(100)
    for i in bla: INDENT
        heap.push(bla[random.randint(0,99)])
DEDENT     print(heap.items())
    start = time.clock()
    heap.heapify()
    end = time.clock() - start
    print(heap.items())
    print("Heapifying took", end*1000, "milliseconds for",len(heap.items()),"elements")

DEDENT 
