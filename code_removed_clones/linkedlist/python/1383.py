#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
Created on Sep 15, 2015

@author: mhuang1
'''
import sys
from py_algo.exception import *

class LinkedList(object):
    
    def __init__(self):
        self._head = None
        self._tail = None
        
    def purge(self):
        self._head = None
        self._tail = None

    def gettail(self):
        return self._tail
    
    tail = property(fget = lambda self: self.gettail())

    def gethead(self):
        return self._head
    
    head = property(fget = lambda self: self.gethead())
    
    def getempty(self):
        return self._head is None
    
    isempty = property(fget = lambda self: self.getempty())

    def getlength(self):
        len = 0
        pre = self._head
        while pre is not None:
            pre = pre._next
            len = len + 1
        return len
    
    length = property(fget = lambda self: self.getlength())
    
    def getheaddata(self):
        if self._head is None:
            raise ContainerEmpty
        return self._head._data
    headdata = property(fget = lambda self: self.getheaddata())
    
    def gettaildata(self):
        if self._tail is None:
            raise ContainerEmpty
        return self._tail._data
    taildata = property(fget = lambda self: self.gettaildata())
    
    def prepend(self, data):
        tmp = self.Element(self, data, self._head)
        if self._head is None:
            self._tail = tmp
        self._head = tmp
        
    def append(self, data):
        tmp = self.Element(self, data, None)
        if self._head is None:
            self._head = tmp
        else:
            self._tail._next = tmp
        self._tail = tmp
        
    def __copy__(self):
        result = LinkedList()
        pre = self._head
        while pre is not None:
            result.append(pre._data)
            pre = pre._next
        return result
    
    def extract(self, data):
        target = self._head
        pre = None
        while target is not None and target._data is not data:
            pre = target
            target = target._next
        if target is None:
            raise KeyError
        if target == self._head:
            self._head = target._next
        else:
            pre._next = target._next
        if target == self._tail:
            self._tail = pre
        
    def __str__(self):
        string = "LinkedList {"
        ptr = self._head
        while ptr is not None:
            string = string + str(ptr._data)
            if ptr._next is not None:
                string = string + ", "
            ptr = ptr._next
        string = string + "}"
        return string        
        
    
    class Element(object):
        def __init__(self, list, data, next):
            self._list = list
            self._data = data
            self._next = next
            
        def getdata(self):
            return self._data
        data = property(fget = lambda self: self.getdata())
        
        def getnext(self):
            return self._next
        next = property(fget = lambda self: self.getnext())
        
        def insertafter(self, data):
            self._next = LinkedList.Element(self._list, data, self._next)
            if self._list._tail is self:
                self._list._tail = self._next
        
        def insertbefore(self, data):
            tmp = LinkedList.Element(self._list, data, self)
            if self is self._list._head:
                self._list._head = tmp
            else:
                pre = self._list._head
                while pre is not None and pre._next is not self:
                    pre = pre._next
                pre._next = tmp
                
        def extract(self):
            pass
        
 
        
            
            
            
            
            
            
            
            