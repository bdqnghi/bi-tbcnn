__author__ = 'neetujoshi'

class Node:

    def __init__(self, init_data):
        self.data = init_data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, new_data):
        self.data = new_data

    def set_next(self, new_next):
        self.next = new_next

class LinkedList:

    def __init__(self, head=None):
        self.head = head

    def insert(self, data):
        #5 is current node and self.head
        #5-->4-->3-->2-->1-->Head
        new_node = Node(data) #create new node
        new_node.set_next(self.head)  #link new
        self.head = new_node

    def list_node(self):
        current_node = self.head
        while current_node:
            print current_node.data
            current_node = current_node.get_next()

    def size(self):
        current_node = self.head
        count=0
        while current_node:
            count +=1
            current_node = current_node.get_next()
        return count

    def delete(self, data):
        current_node = self.head
        previous = None
        while current_node:
            if current_node.get_data() == data:
                if previous == None:
                    self.head = current_node.get_next()
                else:
                    previous.set_next(current_node.get_next())
                return None
            else:
                previous = current_node
                current_node = current_node.get_next()
        return "element not found"

    def search(self, data):
        current_node = self.head
        while current_node is not None:
            if current_node.get_data() == data:
                return current_node.get_data()
            else:
                current_node = current_node.get_next()
        return "element Not found"


l = LinkedList()
print "all nodes:", l.list_node()
l.insert(1)
l.insert(2)
l.insert(3)
l.insert(4)
l.insert(7)
l.list_node()
print "current Node Data", l.head.get_data()
print "size", l.size()
print "search item", l.search(7)
"delete item", l.delete(7)
print "current_node", l.head.get_data()






