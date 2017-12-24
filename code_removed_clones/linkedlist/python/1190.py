class Node(object):

	def __init__(self,data):
		self.data = data
		self.next = None

	def setNext(self, node):
		self.next = node

	def getNext(self):
		return self.next

	def __str__(self):
		return '|{}|->{}'.format(self.data, self.next)

	def __repr__(self):
		return '|{}|->{}'.format(self.data, self.next)

a = Node(3)
b = Node(4)
c = Node(023)
d = Node(232)

a.setNext(b)
b.setNext(c)
c.setNext(d)
print a

class LinkedList(object):

	def __init__(self,data):
		node = Node(data)
		self.head = node
		self.next = None
		self.last = node

	def add(self,data):
		node = Node(data)
		self.last.setNext(node)
		self.last = node


	def addBeginning(self,data):
		temp = self.head
		self.head = Node(data)
		self.head.setNext(temp)

	def getLast(self):
		return self.last.data

	def __str__(self):
		return repr(self.head)

l = LinkedList(4)
l.add(2)
l.add(0)
l.add(1)

print l
print l.getLast()

from platform import node

class TreeNode(object):

    def __init__(self, data):
        self.right = None
        self.left = None
        self.data = data

class Tree(object):

    def __init__(self):
        self.root = None
        self.left  = None
        self.right = None

    def add(self, data):
        node = TreeNode(data)
        if self.root == None:
            self.root = node
        else:
            self._add(node, self.root)

    def _add(self, node, root):

        if node.data > root.data:
            if root.right == None:
                root.right = node
            else:
                self._add(node, root.right)

        if node.data < self.root.data:
            if root.left ==None:
                root.left = node
            else:
                self._add(node, root.left)

    def inOrder(self):
        node = self.root
        
        if node != None:
            self._inOrder(node)
            
    def _inOrder(self, node):
        
        if node !=None:
            self._inOrder(node.left)
            print node.data,
            self._inOrder(node.right)
            
    
    def postOrder(self):
        node = self.root
        
        if node != None:
            self._postOrder(node)
            
    def _postOrder(self, node):
        
        if node !=None:
            self._postOrder(node.left)
            self._postOrder(node.right)
            print node.data,

    def preOrder(self):
        node = self.root
        
        if node != None:
            self._preOrder(node)
            
    def _preOrder(self, node):
        
        if node !=None:
            print node.data,
            self._preOrder(node.left)
            self._preOrder(node.right)

    def height(self):

    	return self._height(self.root)

    def _height(self, node):

        if node == None:
            return 0
        
        lheight = self._height(node.left)
        rheight = self._height(node.right)
        
        if lheight > rheight:
            return lheight + 1 
        else:
            return rheight + 1         


t = Tree()
t.add(10)
t.add(15)
t.add(23)
t.add(233)
t.add(1)
t.add(-9)
t.add(21)
t.add(0)

t.inOrder()
print 
t.postOrder()
print 
t.preOrder()
print
print t.height()





