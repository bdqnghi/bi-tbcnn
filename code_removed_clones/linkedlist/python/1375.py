#!/usr/bin/python
# -*- coding: utf-8 -*-


class Node(object):
    def __init__(self, d, n=None):
        self.data = d
        self.next_node = n

    def get_next(self):
        return self.next_node

    def set_next(self, n):
        self.next_node = n

    def get_data(self):
        return self.data

    def set_data(self, d):
        self.data = d


class LinkedList(Node):
    def __init__(self, r=None):
        self.root = r
        self.size = 0

    def get_size(self):
        return self.size

    def add(self, d):
        new_node = Node(d, self.root)
        self.root = new_node
        self.size += 1

    def remove(self, d):
        current_node = self.root
        prev_node = None
        while current_node:
            if current_node.get_data() == d:
                if prev_node:
                    prev_node.set_next(current_node.get_next())
                else:
                    self.root = current_node
                self.size -= 1
                return True
            else:
                prev_node = current_node
                current_node = current_node.get_next()
        return False

    def find(self, d):
        current_node = self.root
        while current_node:
            if current_node.get_data() == d:
                return d
            else:
                current_node = current_node.get_next()
        return None
