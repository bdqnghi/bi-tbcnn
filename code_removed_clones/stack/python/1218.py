#!/usr/bin/env python
# encoding: utf-8
"""
stack.py

Created by Andrew Lenox on 2010-09-21.
Copyright (c) 2010 __MyCompanyName__. All rights reserved.
"""

import sys
import os
import unittest


class stack:  INDENT#Using a list as a stack
        def __init__(self): INDENT
                self.p = []
                self.index = 0
                
DEDENT         def __iter__(self): INDENT
                return self
        
DEDENT         def next(self): INDENT
                if self.index == 0: INDENT
                        raise StopIteration
DEDENT                 self.index = self.index - 1
                return self.p[self.index]
                
DEDENT         def push(self,t): INDENT
                self.p.append(t)
                        
DEDENT         def pop(self): INDENT
                return self.p.pop()
                
DEDENT         def top(self): INDENT
                if self.p: INDENT
                        return self.p[-1]
                
DEDENT DEDENT         def remove(self): INDENT
                self.p.pop(0)
        
DEDENT         def clear(self): INDENT
                while self.size() > 0: INDENT
                        self.p.pop()
                
DEDENT DEDENT         def isEmpty(self): INDENT
                return (len(self.p)==0)
                
DEDENT         def printStack(self): INDENT
                print self.p
                
DEDENT         def isFull(self): INDENT
                return (len(self.p) >= 5)
                                
DEDENT         def size(self): INDENT
                return len(self.p)
        
DEDENT         def equal(self, s): INDENT
                return self.p == s.p
                
DEDENT DEDENT class stackTests(unittest.TestCase): INDENT
        def setUp(self): INDENT
                self.s = stack()
        
DEDENT         def test_iterable(self): INDENT
                stack = self.s
                stack.push(1)
                stack.push(2)
                stack.push(3)
                i = 1
                for s in stack: INDENT
                        self.assertEqual(i, s)
                        i -= 1
                        
DEDENT DEDENT         def test_clear(self): INDENT
                stack = self.s
                stack.push(1)
                stack.push(2)
                stack.push(3)
                self.assertTrue(stack.size() == 3)
                stack.clear()
                self.assertTrue(stack.size() == 0)

DEDENT DEDENT if __name__ == '__main__': INDENT
        unittest.main()
DEDENT 
