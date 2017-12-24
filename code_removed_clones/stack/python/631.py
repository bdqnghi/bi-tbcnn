#! usr/bin/python
# This is a module which will we used to handle tree structure.
# This function as two main functions
#  1) push(p,Q) pushes the given elements into stacts
#  2) pop() pops put the last element and return it
# and some other complimentery functions like
#  3) isempty() will return 1 is stack is empty 


class Cla_stack: INDENT
    def __init__(self):  INDENT#This is a constructor
        self.Storage = []
    ##~~~~~~~~~End of constructor~~~~~~~~~~~~~~~~~~~~~~##

DEDENT     def isempty(self): INDENT
        if len(self.Storage)==0: INDENT
            return 1
DEDENT         else: INDENT
            return 0

    ##~~~~~~~~~~End of function isempty~~~~~~~~~~~~~~~~~##


DEDENT DEDENT     def push(self,p,Q,SUBG):     INDENT# Storing a point and Q at that time
        self.Storage = self.Storage + [[[p],[Q],[SUBG]]]

    ##~~~~~~~~~~~End of function push~~~~~~~~~~~~~~~~~~~##


DEDENT     def pop(self): INDENT
        p_Q_SUBG = []
        if self.isempty()==0: INDENT
            p_Q_SUBG = self.Storage[len(self.Storage)-1]
DEDENT         del self.Storage[len(self.Storage)-1]
        return p_Q_SUBG

     ##~~~~~~~~~~~End of function pop~~~~~~~~~~~~~~~~~~~~##

DEDENT DEDENT 
