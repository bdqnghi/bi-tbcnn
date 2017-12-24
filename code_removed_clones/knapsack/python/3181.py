#!/usr/bin/env python
"""
knapsack.py
Author: Brian Boates

Use dynamic programming to solve the 
infamous "knapsack" problem
"""

class item:
    """
    items that can be placed in the knapsack
    """
    def __init__(self, w, v):
        """
        params:
            w: int   | positive integer weight of item
            v: float | value of item
        """
        self.w = w
        self.v = v
    


def knapsack(W, items):
    """
    return: float | optimal value that can fit in
                    knapsack of max weight W
    params:
          W: int        | positive integer max weight of knapsack
      items: list[item] | list of available items for knapsack
    """
    # initialize max value and inBag variables
    m     = [0 for i in range(W+1)]
    inBag = [[] for i in range(W+1)]
    
    # loop over all max bag weights up to and including W
    for k in range(1, W+1):
        
        # first guess for k's optima is previous optima
        m[k] = m[k-1]
        inBag[k] = inBag[k-1]
        
        # loop over the items
        for i, x in enumerate(items):
            
            # make sure not to consider negative W
            if k - x.w >= 0:
            
                # make sure not to use unavailable items
                # inBag tracks indices of items in the bag for a given k
                if i not in inBag[k - x.w]:
                
                    # optima for smaller bag plus new item's value
                    mtmp   = m[k - x.w] + x.v
                    bagtmp = inBag[k - x.w] + [i]
                
                    # check to see if value is better than before, if so, update
                    if mtmp > m[k]:
                        m[k]     = mtmp
                        inBag[k] = bagtmp
    
    return m[W]


def main():
    
    # raw list of items; (w,v) pairs
    raw   = [(1,2), (2,1), (2,3), (5,7), (5,8), (10,14)]
    items = [item(r[0], r[1]) for r in raw]
        
    ####################################
    # max weight for the knapsack      #
    W = range(12)                      #
    for w in W:                        #    
        print w, knapsack(w, items)    #
    #                                  #
    # solutions should be              #
    # 0 0                              #
    # 1 2                              #
    # 2 3                              #
    # 3 5                              #
    # 4 5                              #
    # 5 8                              #
    # 6 10                             #
    # 7 11                             #
    # 8 13                             #
    # 9 13                             #
    # 10 15                            #
    # 11 17                            #
    ####################################

    
if __name__ == '__main__':
    main()