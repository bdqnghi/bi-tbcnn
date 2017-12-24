# -*- encoding: utf-8 -*-


class LinkedList(object):
    def __init__(self):
        self.head, self.tail = None, None
        self.size = 0

    def push_back(self, node):
        node.prev = self.tail

        if self.tail is None:
            assert self.head is None
            self.head = node
        else:
            self.tail.next = node

        self.tail = node
        self.size += 1

    def pop_back(self):
        last_node = self.tail
        self.tail = self.tail.prev
        last_node._detach()
        self.size -= 1
        if self.size == 0:
            assert self.tail is None
            self.head = None
        return last_node

    def push_front(self, node):
        node.next = self.head

        if self.head is None:
            assert self.tail is None
            self.tail = node
        else:
            self.head.prev = node

        self.head = node
        self.size += 1

    def pop_front(self):
        first_node = self.head
        self.head = self.head.next
        first_node._detach()
        self.size -= 1
        if self.size == 0:
            assert self.head is None
            self.tail = None
        return first_node

    def remove_node(self, node):
        if node == self.head:
            return self.pop_front()
        if node == self.tail:
            return self.pop_back()

        prev, next = node.prev, node.next
        prev.next = next
        next.prev = prev
        node._detach()
        self.size -= 1
        return node

    def __len__(self):
        return self.size


class LinkedListNode(object):
    def __init__(self, data):
        self._detach()
        self.data = data

    def _detach(self):
        self.next, self.prev = None, None
