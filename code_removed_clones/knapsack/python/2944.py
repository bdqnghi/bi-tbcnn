# -*- coding: utf-8 -*-
"""
Created on Sun Sep 21 20:12:36 2014

@author: kishor
"""
from copy import deepcopy
def knapsack_without_rep(w, v, BAG, OUT):
    #print w, v, BAG, OUT
    if len(w) == 0:
        return OUT
    if len(v) == 0:
        return OUT
    if BAG <= 0:
        return OUT
        
    w1 = deepcopy(w)
    wt = w1.pop()
    v1 = deepcopy(v)
    value = v1.pop()
    if BAG - wt < 0:
        return OUT
    k1 = knapsack_without_rep(w1, v1, BAG-wt, OUT+value)
    
    w2 = deepcopy(w)
    v2 = deepcopy(v)
    w2.pop()
    v2.pop()
    if BAG - wt < 0:
        return OUT
    k2 = knapsack_without_rep(w2, v2, BAG, OUT)
    
    return max(k1, k2)
    
def knapsack_with_rep(w, v, BAG, OUT):
    #print w, v, BAG, OUT
    if len(w) == 0 or len(v) == 0:
        return OUT
    if BAG <= 0:
        return OUT
    w1 = deepcopy(w)
    v1 = deepcopy(v)
    wt = w1.pop()
    val = v1.pop()
    if BAG - wt < 0:
        return OUT
    k1 = knapsack_with_rep(w, v, BAG-wt, OUT+val)
    
    w2 = deepcopy(w)
    v2 = deepcopy(v)
    w2.pop()
    v2.pop()
    if BAG - wt < 0:
        return OUT
    k2 = knapsack_with_rep(w2, v2, BAG, OUT)
    return max(k1, k2)

def knapsack_with_rep_dp(w, v, BAG):
    knap = list()
    knap.append(0)
    for i in xrange(1, BAG+1):
        max_val_wt = 0
        curr_val = 0        
        for j in xrange(0, len(w)):
            if i < w[j] < 0:
                continue
            if i - w[j] >= 0:
               curr_val = knap[i-w[j]] + v[j]
            if curr_val >= max_val_wt:
                max_val_wt = curr_val
        knap.append(max_val_wt)
        print i, knap
    return knap[-1]
            
import numpy as np
def knapsack_without_rep_dp(w, v, BAG):
    KM = np.zeros((len(w)+1) * (BAG+1))
    KM = KM.reshape(BAG+1, len(w)+1)
    print KM
    for WI in xrange(1, len(w)+1):
        for BS in xrange(1, BAG+1):
            if w[WI-1] > BS:
                KM[BS, WI] = KM[BS, WI-1]
            else:
                KM[BS, WI] = max(KM[BS, WI-1], KM[BS-w[WI-1], WI-1] + v[WI-1])
    print KM
    return KM[-1,-1]
if __name__ == '__main__':
     #print knapsack_without_rep([3,4,7,8,9], [4,5,10,11,13], 17, 0)  
     #print knapsack_without_rep([1,5,3,4], [15,10,9,5],8,0)
     #print knapsack_without_rep([3,4], [9,5],2,0)
     #print knapsack_with_rep([6,3,4,2], [30,14,16,9], 10, 0)
     print knapsack_without_rep([6,3,4,2],[30,14,16,9], 10, 0)
     print knapsack_without_rep_dp([6,3,4,2],[30,14,16,9], 10)