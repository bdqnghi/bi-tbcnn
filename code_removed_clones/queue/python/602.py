from linkedlist import *

class queue(object): INDENT
    """docstring for Queue"""
    def __init__(self): INDENT
        self._store = dlinkedlist()
        self._size = 0

DEDENT     def enqueue(self,value): INDENT
        self._store.backadd(value)
        self._size += 1

DEDENT     def dequeue(self): INDENT
        if(self.isEmpty()): INDENT
            return None
DEDENT         self._size -= 1
        return self._store.frontremove()

DEDENT     def peek(self): INDENT
        return self._store.get(0)

DEDENT     def size(self): INDENT
        return self._size 

DEDENT     def isEmpty(self): INDENT
        if self._size == 0: INDENT
            return True
DEDENT         else: INDENT
            return False 

DEDENT DEDENT     def discard(self): INDENT
        if self.isEmpty(): INDENT
            return None
DEDENT         self._size -= 1
        return self._store.backremove()

DEDENT     def extract(self): INDENT
        return self._store.extract()
DEDENT DEDENT 
