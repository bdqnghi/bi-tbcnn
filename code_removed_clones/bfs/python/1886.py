'''
Created on Jan 29, 2017

@author: saumitra
'''

from collections import deque
from sets import Set
from Utlis import compareState
from Result import Result 


class BFS():
    '''
    Search state space tree using Breadth First Search
    '''
    
    def __init__(self,initialState):
        '''
        Constructor
        '''
        self.initialSate=initialState

    #Algorithm for BFS to search
    def searchAlgo(self):
        fringe=deque()
        fringeBoard=Set()
        explored=[]
        exploredBoard=Set()
        fringe.append(self.initialSate)
        fringeBoard.add(self.initialSate.boardConfig)
        maxfringeSize=1
        maxSearchDepth=self.initialSate.cost
        while fringe:
            if len(fringe) > maxfringeSize:
                maxfringeSize=len(fringe)
            state=fringe.popleft()
            fringeBoard.remove(state.boardConfig)
            explored.append(state)
            exploredBoard.add(state.boardConfig)
            if state.isGoal():
                result=Result(state,explored,fringe,maxfringeSize,maxSearchDepth)
                return result
            for neighbour in state.neighbour():
                temp=compareState(neighbour.boardConfig,fringeBoard,exploredBoard)
                if temp == False:  
                    fringe.append(neighbour)
                    fringeBoard.add(neighbour.boardConfig)
                    if neighbour.cost > maxSearchDepth :
                        maxSearchDepth = neighbour.cost
        return None