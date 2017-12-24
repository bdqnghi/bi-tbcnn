#exec(open("linkedlist.py").read())
class LinkedList:
	"""A singly linked list to be implemented as a stack"""

	class Node:
		__slots__ = "_value","_next"
		def __init__(self, v, n):
			self._value = v
			self._next = n

	def __init__(self):
		"""Initialized list containing only a blank node"""
		self._tail = self.Node(None,None)
		self._head = self.Node(None,self._tail)
		self._size = 0

	def push(self, v):
		"""Adds a value to the top of the list"""
		self._head = self.Node(v,self._head)
		self._size += 1

	def pop (self):
		"""Pulls the last value from the list"""
		if (self._size):
			popped = self._head._value
			self._head = self._head._next
			self._size -= 1
			return popped

	def __iter__(self):
		"""An iterator generator to visit the values in sequence"""
		current = self._head
		while current is not None:
			yield str(current._value)
			current = current._next

	def top (self):
		"""Retrives the last value without popping it"""
		return self._head._value

	def is_empty (self):
		"""Returns whether the list is empty or not"""
		return (self._size == 0)

	def __len__ (self):
		"""Number of elements in the list"""
		return self._size

	def __str__(self):
		"""When called as a string, returns a separated list of the values"""
		return ' '.join(list(iter(self)))