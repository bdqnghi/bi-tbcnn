#!/usr/bin/env python
# (c) Aleksandar Topuzovic <aleksandar.topuzovic@gmail.com>

class heap(object): INDENT
    '''Simple healp implementation using a list'''
    def __init__(self): INDENT
        self.data = []

DEDENT     def push(self, item): INDENT
        '''
        Insert an item into the heap

        @param item: Item to insert
        '''
        i = len(self.data)
        self.data.append(item)

        while i > 0: INDENT
            p = i/2  # Parent
            if self.data[i] < self.data[p]:   INDENT# Bubble up
                self.data[p], self.data[i] = self.data[i], self.data[p]
                i = p
DEDENT             else: INDENT
                break

DEDENT DEDENT DEDENT     def pop(self): INDENT
        data = self.data[0]

        return data
                
DEDENT     def __str__(self): INDENT
        '''String representation of the heap'''
        return ' '.join(map(str, self.data))

DEDENT     def min(self): INDENT
        '''Minimum element in the heap'''
        try: INDENT
            return self.data[0]
DEDENT         except IndexError: INDENT
            raise Exception('Empty heap')

DEDENT DEDENT     def as_list(self): INDENT
        return self.data

DEDENT DEDENT if __name__ == '__main__': INDENT
    h = heap()
    h.push(2)
    print h
    h.push(5)
    h.push(6)
    h.push(4)
    print h
    h.push(1)
    print h.min()
DEDENT 
