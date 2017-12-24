def main():
    print("Enter [q] to quit")
    print("Welcome to the linked-list interface! Here are the methods: " +
          "insert, delete, search, size, display")

    linkedList = LinkedList()

    while True:
        i = input("Enter a command (insert, delete, search, size, display): " )
        if i == "q": break

        if i == "insert":
            e = input("Name the element you want to insert: ")
            linkedList.insert(e)

        if i == "delete":
            e = input("Name the element you want to delete: ")
            try:
                linkedList.delete(e)
                print(e + " deleted")
            except ValueError:
                print("Element not found in list")

        if i == "search":
            e = input("Name the element you're searching for: ")
            try:
                o = linkedList.search(e)
                print(o)
            except ValueError:
                print("Element not found in list")

        if i == "size":
            s = linkedList.size()
            print(s)

        if i == "display":
            linkedList.display()

class Node(object):

    def __init__(self, data=None, nextNode=None):
        self.data = data
        self.nextNode = nextNode

    def get_data(self):
        return self.data

    def get_next(self):
        return self.nextNode

    def set_next(self, newNext):
        self.nextNode = newNext

# LinkedList interfaces Node, user interfaces LinkedList
class LinkedList(object):

    def __init__(self, head=None):
        self.head = head

    # Insert into front of list
    def insert(self, data):
        newNode = Node(data)
        newNode.set_next(self.head)
        self.head = newNode

    def size(self):
        curr = self.head
        count = 0
        while curr:
            count += 1
            curr = curr.get_next()
        return count

    def search(self, data):
        curr = self.head
        found = False
        while curr and found is False:
            if curr.get_data() == data:
                found = True
            else:
                curr = curr.get_next()
        if curr is None:
            raise ValueError("Data not in list")
        return found

    def delete(self, data):
        curr = self.head
        previous = None
        found = False
        while curr and found is False:
            if curr.get_data() == data:
                found = True
            else:
                previous = curr
                curr = curr.get_next()
        if curr is None:
            raise ValueError("Data not in list")
        if previous is None:
            self.head = curr.get_next()
        else:
            previous.set_next(curr.get_next())

    def display(self):
        curr = self.head
        while curr:
            print(curr.get_data())
            curr = curr.get_next()

if __name__ == "__main__":
    main()
