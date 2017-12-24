from linkedlist import LinkedList, Node


class DoublyLinkedList(LinkedList):

    def __init__(self, items=None):
        LinkedList.__init__(self, items)

    def __str__(self):
        """Return a formatted string representation of this linked list."""
        items = ['({!r})'.format(item) for item in self.items()]
        return '[{}]'.format(' -> '.join(items))

    def length(self):
        '''Return the size of the matrix'''
        # how many linkedlists it has
        columns = len(self.items())
        rows = 0
        for node in self:
            linkedlist = node.data
            # how many node each linkedlist has
            row = len(linkedlist.items())
            # the largest number of row is gonna be number of rows of the matrix
            if row > rows:
                rows = row
        return '{} by {} matrix'.format(rows, columns)

    def append(self, item, number_of_columns=0):
        """Insert the given item at the tail of this linked list.
        TODO: Running time: O(1) Why and under what conditions?"""
        # TODO: Create new node to hold given item
        node = Node(item)
        if type(item) is list:
            node.data = LinkedList(node.data)
            # TODO: Append node after tail, if it exists
            if self.tail is None:
                self.head = node
                self.tail = node
            else:
                self.tail.next = node
                self.tail = node
        else:
            # start from first column
            columns = 0
            for node in self:
                if columns == number_of_columns:
                    linkedlist = node.data
                    linkedlist.append(item)
                    break
                else:
                    # count columns
                    columns += 1

    def prepend(self, item, number_of_columns):
        """Insert the given item at the head of this linked list.
        TODO: Running time: O(1) Why and under what conditions?"""
        # TODO: Create new node to hold given item
        node = Node(item)
        if type(item) is list:
            node.data = LinkedList(node.data)
            # TODO: Prepend node before head, if it exists
            if self.is_empty():
                self.head = node
                self.tail = node
            else:
                node.next = self.head
                self.head = node
        else:
            columns = 0
            for node in self:
                if columns == number_of_columns:
                    linkedlist = node.data
                    linkedlist.prepend(item)
                    break
                else:
                    # count columns
                    columns += 1

    def find(self, quality):
        """Return an item from this linked list satisfying the given quality.
        TODO: Best case running time: O(???) Why and under what conditions?
        TODO: Worst case running time: O(???) Why and under what conditions?"""
        # TODO: Loop through all nodes to find item where quality(item) is True
        # TODO: Check if node's data satisfies given quality function
        for node in self:
            linkedlist = node.data
            for node in linkedlist:
                if quality(node.data):
                    item = node.data
                    return item

    def delete(self, item):
        """Delete the given item from this linked list, or raise ValueError.
        TODO: Best case running time: O(???) Why and under what conditions?
        TODO: Worst case running time: O(???) Why and under what conditions?"""
        # TODO: Loop through all nodes to find one whose data matches given item
        # TODO: Update previous node to skip around node with matching data
        # TODO: Otherwise raise error to tell user that delete has failed
        # Hint: raise ValueError('Item not found: {}'.format(item))
        previous_node = None
        # Loop until node is None, which is one node too far past tail
        find_item = self.find(lambda item_: item_ == item)
        if find_item is None:
            raise ValueError('Item not found: {}'.format(item))
        else:
            for node in self:
                linkedlist = node.data
                for node in linkedlist:
                    if node == self.head:
                        if node.data == item:
                            self.head = node.next
                            if node == self.tail:
                                self.tail = previous_node
                            break
                        else:
                            previous_node = node
                    else:
                        if node.data == item:
                            previous_node.next = node.next
                            if node == self.tail:
                                self.tail = previous_node
                            break
                        else:
                            previous_node = node

def test_doubly_linked_list():
    dll = DoublyLinkedList()
    print('list: {}'.format(dll))

    print('\nTesting append:')
    for item in [['A', 'B', 'C'], ['D', 'E', 'F']]:
        print('append({!r})'.format(item))
        dll.append(item)
        print('list: {}'.format(dll))

    print('head: {}'.format(dll.head))
    print('tail: {}'.format(dll.tail))
    print('length: {}'.format(dll.length()))

    item = 'G'
    print('append({!r})'.format(item))
    dll.append(item, 0)
    print('list: {}'.format(dll))

    item = ['S', 'T', 'U']
    print('append({!r})'.format(item))
    dll.append(item, 0)
    print('list: {}'.format(dll))

    number = 0

    for item in ['X', 'Y', 'Z']:
        print('append({!r})'.format(item))
        dll.prepend(item, number)
        print('list: {}'.format(dll))
        number += 1

    print('head: {}'.format(dll.head))
    print('tail: {}'.format(dll.tail))
    print('length: {}'.format(dll.length()))

    print(dll.find(lambda item: item == 'B'))
    print(dll.find(lambda item: item > 'B'))
    print(dll.find(lambda item: item < 'B'))

    print('\nTesting delete:')
    for item in ['B', 'C', 'A']:
        print('delete({!r})'.format(item))
        dll.delete(item)
        print('list: {}'.format(dll))

    print('head: {}'.format(dll.head))
    print('tail: {}'.format(dll.tail))
    print('length: {}'.format(dll.length()))

if __name__ == '__main__':
    test_doubly_linked_list()
