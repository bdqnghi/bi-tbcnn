# Dome info about operations in heap
# http://en.wikipedia.org/wiki/Binary_heap

import random
import networkx as nx
import matplotlib.pyplot as plt


class Node: INDENT
        def __init__(self,left,right,value): INDENT
                self.left = left
                self.right = right
                self.value = value
        
DEDENT         def get_left(self): INDENT
                return self.left

DEDENT         def get_right(self): INDENT
                return self.right

DEDENT         def get_value(self): INDENT
                return self.value

DEDENT         def set_value(self,value): INDENT
                self.value = value

DEDENT         def set_left(self,value): INDENT
                # If value equals None, remove left node
                if value == None: INDENT
                        self.left = None
DEDENT                 else: INDENT
                        self.left = Node(None,None,value)

DEDENT DEDENT         def set_right(self,value): INDENT
                # If value equals None, remove right node
                if value == None: INDENT
                        self.right = None
DEDENT                 else: INDENT
                        self.right = Node(None,None,value)

DEDENT DEDENT         def isLeaf(self): INDENT
                if self.left == None and self.right == None: INDENT
                        return True
DEDENT                 else: INDENT
                        return False

DEDENT DEDENT DEDENT class Heap: INDENT
        def __init__(self): INDENT
                self.root = None


DEDENT         def attach_at_bottom(self,node,value): INDENT
                # this will give me random position at the end of the heap
                
                if self.root == None: INDENT
                        self.root = Node(None,None,value)
DEDENT                 elif node.isLeaf(): INDENT
                        node.set_left(value)
DEDENT                 elif node.get_left() == None: INDENT
                        node.set_left(value)
DEDENT                 elif node.get_right() == None: INDENT
                        node.set_right(value)
DEDENT                 else: INDENT
                        new_node = random.sample([node.get_left(),node.get_right()],1)[0]
                        self.attach_at_bottom(new_node,value)
                
DEDENT DEDENT         def swap(self,node): INDENT
                if self.root == None: INDENT
                        print "Heap is empty"
                        return None
DEDENT                 elif self.root.isLeaf(): INDENT
                        print "Heap has only root"
                        return None
                
                # Go down
DEDENT                 if node.get_left() != None: INDENT
                        if not node.get_left().isLeaf(): INDENT
                                print "go left"
                                self.swap(node.get_left())
                        
DEDENT                         if node.get_value() < node.get_left().get_value(): INDENT
                                print "swap left"
                                tmp = node.get_value()
                                node.set_value(node.get_left().get_value())
                                node.get_left().set_value(tmp)

                # Go down
DEDENT DEDENT                 if node.get_right() != None: INDENT
                        if not node.get_right().isLeaf(): INDENT
                                print "go right"
                                self.swap(node.get_right())
                        
DEDENT                         if node.get_value() < node.get_right().get_value(): INDENT
                                print "swap right"
                                tmp = node.get_value()
                                node.set_value(node.get_right().get_value())
                                node.get_right().set_value(tmp)

        



# Non class functions
# Testing functions
DEDENT DEDENT DEDENT DEDENT def build_heap(mylist): INDENT
        if len(mylist) == 0: INDENT
                print "List is empty"
                return None
DEDENT         else: INDENT
                h = Heap()
                for l in mylist: INDENT
                        h.attach_at_bottom(h.root,l)
                        h.swap(h.root)
DEDENT                 return h

DEDENT DEDENT def get_nodes(root,G): INDENT
        if root != None: INDENT
                G.add_node(root.get_value())

                if (root.get_right() != None): INDENT
                        get_nodes(root.get_right(),G)
                        G.add_edge(root.get_value(),root.get_right().get_value())

DEDENT                 if (root.get_left() != None): INDENT
                        get_nodes(root.get_left(),G)
                        G.add_edge(root.get_value(),root.get_left().get_value())


DEDENT DEDENT DEDENT def plot_tree(root): INDENT
        # http://stackoverflow.com/questions/11479624/is-there-a-way-to-guarantee-hierarchical-output-from-networkx
        G = nx.DiGraph()
        get_nodes(root,G)
        if len(G.nodes())==0: INDENT
                print "Tree is empty"
DEDENT         else: INDENT
                pos=nx.graphviz_layout(G,prog='dot')
                nx.draw(G,pos,with_labels=True,arrows=False,node_size=1000)
                plt.show()

DEDENT DEDENT h = build_heap([5,3,20,1,4,10,25,12,11,2,7,22,21,8,9,13])
plot_tree(h.root)

#h = build_heap([5,3,20,30])
#h.swap(h.root)
#plot_tree(h.root)


