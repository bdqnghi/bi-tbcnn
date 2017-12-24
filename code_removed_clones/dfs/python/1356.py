#Author : Joshua Wang. Date 10/24 2013
import sys
import tree
from collections import deque
from Warehouse import Warehouse
from Inputhandler import Inputhandler
from tree import tree, node
import time
import copy

class DFS(object):  INDENT# do DFS
        def __init__(self, root): INDENT
                self.explored=set()
                self.frontier=deque()  # use deque to implement stack
                self.frontier.append(root)
                self.searchtree=tree(root)
                self.numofnodegenbefore=0
                self.numofnodeonfringe=1



DEDENT         def search(self): INDENT
                start=time.time()
                while (1): INDENT
                 if len(self.frontier)==0: INDENT
                        finish=time.time()  # then print statistics 
                        print("number of nodes generated: "+str(self.searchtree.getnumofnodes()))
                        print("number of nodes containing generated states: "+str(self.numofnodegenbefore))
                        print("number of nodes on the fringe: "+str(len(self.frontier)))
                        print("number of nodes in the explored list: "+str(len(self.explored)))
                        print("run time: "+str(finish-start))
                        return "failure"
DEDENT                  parentnode= self.frontier.pop()
                 self.explored.add(parentnode)

                 for action in ["u", "l", "d", "r"]:   INDENT# scrumble actions to prevent loops (actually no need in graph search)
                        newstate=parentnode.content.move(action)[0]
                        if not newstate=="ILLEGAL_MOVE":  INDENT#exclude illegal move:
                                child=self.searchtree.addandreturnnode(parentnode, newstate, action)
                                if  not self.inexplored(child) and not self.infrontier(child):  INDENT# use graph search
                                        if newstate.allgoalremoved: INDENT
                                                finish=time.time() # then print statistics
                                                print("number of nodes generated: "+str(self.searchtree.getnumofnodes()))
                                                print("number of nodes containing states generated before: "+str(self.numofnodegenbefore))
                                                print("number of nodes on the fringe: "+str(len(self.frontier)))
                                                print("number of nodes in the explored list: "+str(len(self.explored)))
                                                print("run time: "+str(finish-start))
                                                return child.path
DEDENT                                         self.frontier.append(child) 
DEDENT                                 else:   INDENT# in explored ot frontier
                                        self.numofnodegenbefore+=1 
                
                


DEDENT DEDENT DEDENT DEDENT DEDENT         def infrontier(self, thenode): INDENT
                for element in self.frontier: INDENT
                        if element.content==thenode.content: INDENT
                                return 1
DEDENT DEDENT                 return 0

DEDENT         def inexplored(self, thenode): INDENT
                for element in self.explored: INDENT
                        if element.content==thenode.content: INDENT
                                return 1
DEDENT DEDENT                 return 0


# if __name__=="__main__":
# 	inputhandler=Inputhandler()
# 	MAP=inputhandler.filetostr("big.txt")
# 	warehouse=Warehouse(MAP)
# 	warehouse.setiniworkerposi()
# 	warehouse.show()

# 	root=node(warehouse)
# 	dfs=DFS(root)
# 	print(dfs.search())
DEDENT DEDENT 
