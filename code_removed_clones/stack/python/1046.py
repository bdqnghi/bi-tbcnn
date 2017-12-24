#!/usr/bin/python

from linked_list import LinkedList, Node

class Stack(object): INDENT
  def __init__(self, *args): INDENT
    self.tail = None
    for elem in args: INDENT
      self.push(elem)

DEDENT DEDENT   def push(self, elem): INDENT
    node = Node(elem)
    if not self.tail: INDENT
      self.tail = node
DEDENT     self.tail.next = node
    node.prev = self.tail
    self.tail = node

DEDENT   def pop(self): INDENT
    if not self.tail: INDENT
      print 'Stack is empty'
      return
DEDENT     ret_elem = self.tail.data
    self.tail = self.tail.prev
    self.tail.next = None
    print ret_elem

DEDENT DEDENT 
