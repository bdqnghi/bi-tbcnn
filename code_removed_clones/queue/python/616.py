# -*- coding: UTF-8 -*-

#队列
class Queue: INDENT
    def __init__(self,size = 16): INDENT
        self.queue = []
        self.size = size
        self.front = 0
        self.rear = 0
DEDENT     def isEmpty(self): INDENT
        return self.rear == 0
DEDENT     def isFull(self): INDENT
        if (self.front - self.rear +1) == self.size: INDENT
            return True
DEDENT         else: INDENT
            return False
DEDENT DEDENT     def first(self): INDENT
        if self.isEmpty(): INDENT
            raise Exception("QueueIsEmpty")
DEDENT         else: INDENT
            return self.queue[self.front]
DEDENT DEDENT     def last(self): INDENT
        if self.isEmpty(): INDENT
            raise Exception("QueueIsEmpty")
DEDENT         else: INDENT
            return self.queue[self.rear]
DEDENT DEDENT     def add(self,obj): INDENT
        if self.isFull(): INDENT
            raise Exception("QueueOverFlow")
DEDENT         else: INDENT
            self.queue.append(obj)
            self.rear += 1
DEDENT DEDENT     def delete(self): INDENT
        if self.isEmpty(): INDENT
            raise Exception("QueueIsEmpty")
DEDENT         else: INDENT
            self.rear -=1
            return self.queue.pop(0)
DEDENT DEDENT     def show(self): INDENT
        print(self.queue)
DEDENT DEDENT q = Queue(3)
q.add(1)
q.add(2)
q.show()
q.delete()
q.show()
