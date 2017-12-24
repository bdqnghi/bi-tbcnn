# -*- coding: utf-8 -*-
"""
Created on Tue Apr 07 21:33:02 2015

@author: zhyfly711
"""
'''First, let's look at the greedy algorithm'''
class Item(object):
    
    def __init__(self, n, v, w):
        self.name = n
        self.value = v
        self.weight = w
    
    def getName(self):
        return self.name
    
    def getValue(self):
        return self.value
    
    def getWeight(self):
        return self.weight
    
    def __str__(self):
        result = '<' + self.name + ', ' + str(self.value)\
                 + ', ' + str(self.weight) + '>'
        return result

def buildItems():
    names = ['clock', 'painting', 'radio', 'vase', 'book', 'computer']
    vals = [175, 90, 20, 50, 10, 200]
    weights = [10, 9, 4, 2, 1, 20]
    Items = []
    for i in range(len(vals)):
        Items.append(Item(names[i], vals[i], weights[i]))
    return Items
    
'''Greedy algorithm'''
def greedy(Items, maxWeight, keyFcn):
    assert type(Items) == list and maxWeight >= 0
    ItemsCopy = sorted(Items, key = keyFcn, reverse = True)
    '''use keyFcn parameter lets us generalize one procedure
    to use different measure so goodness. Just requires that
    keyFcn definess an ordering on the list of elements. Then
    use this to create an ordered list. Use sorted to create 
    a copy of this list'''
    #reverse = True means sort them in a decreasing order
    result = []
    totalVal = 0.0
    totalWeight = 0.0
    i = 0
    while totalWeight < maxWeight and i < len(Items):
        if (totalWeight + ItemsCopy[i].getWeight()) <= maxWeight:
            result.append((ItemsCopy[i]))
            totalWeight += ItemsCopy[i].getWeight()
            totalVal += ItemsCopy[i].getValue()
        i += 1
    return (result, totalVal)

def value(item):
    return item.getValue()

def weightInverse(item):
    return 1.0/item.getWeight()

def density(item):
    return item.getValue()/item.getWeight()

def testGreedy(Items, constraint, getKey):
    taken, val = greedy(Items, constraint, getKey)
    print ('Total value of items taken = ' + str(val))
    for item in taken:
        print ' ', item


def testGreedys(maxWeight = 20):
    Items = buildItems()
    print('Items to choose from: ')
    for item in Items:
        print ' ', item
    print 'Use greedy by value to fill a knapsack of size', maxWeight
    testGreedy(Items, maxWeight, value)
    print 'Use greedy by weight to fill a knapsack of size', maxWeight
    testGreedy(Items, maxWeight, weightInverse)
    print 'Use greedy by density to fill a knapsack of size', maxWeight
    testGreedy(Items, maxWeight, density)

'''Now let's get all the subsets of a list'''

def get_all_subsets(some_list):
    '''returns all subsets of size 0 - len(some_list) for some_list'''
    if len(some_list) == 0:
        return[[]]
    subsets = []
    first_elt = some_list[0]
    rest_list = some_list[1:]
    for partial_subset in get_all_subsets(rest_list):
        subsets.append(partial_subset)
        next_subset = partial_subset[:] + [first_elt]
        subsets.append(next_subset)
    return subsets
    
    
'''Integer programming idea: each item in represented by a pair (value, weight)
and total weight cannot exceed w. A vector L of length n represents the set of 
available items. Each element of the vector is an item. A vector V of length n
is used to indicate wheter or not each item is taken, so V[i] = 0 or V[i] = 1.
Find a V that maximizes the sume of V[i] *(L[i].value) with V[i]*(L[i].weight)
not exceding w.'''

'''Method 1: find the power set, remove all the combos whose weights exceeds
the allowed weight, then choose the biggest from the remaining.'''

'''The brute force Approach'''

#Fist get the binary string for the number n
def dToB(n, numDigits):
    '''requires: n is a natural num less than 2**numDigits, returns a binary
    string of length numDigits representing the decimal number n.'''
    assert type(n) == int and type(numDigits) == int\
        and n >= 0 and n < 2**numDigits
    bStr = ''
    while n > 0:
        bStr = str(n % 2) + bStr
        n = n//2
    while numDigits - len(bStr) > 0:
        bStr = '0' + bStr
    return bStr

## Then get the powerset. Here is another way to get the powerset
def genPset(Items):
    numSubsets = 2**len(Items)
    templates = []
    for i in range(numSubsets):
        templates.append(dToB(i, len(Items)))
    pset = []
    for t in templates:
        elem = []
        for j in range(len(t)):
            if t[j] == '1':
                elem.append(Item[j])
        pset.append(elem)
    return pset

def chooseBest(pset, constraint, getVal, getWeight):
    bestVal = 0.0
    bestSet = None
    for Items in pset:
        ItemsVal = 0.0
        ItemsWeight = 0.0
        for item in Items:
            ItemsVal += getVal(item)
            ItemsWeight += getWeight(item)
        if ItemsWeight <= constraint and ItemsVal > bestVal:
            bestVal = ItemsVal
            bestSet = Items
    return (bestSet, bestVal)

def testBest():
    Items = buildItems()
    pset = genPset(Items)
    taken, val = chooseBest(pset, 20, Item.getValue, Item.getWeight)
    print ('Total value of items taken = ' + str(val))
    for item in taken:
        print ' ', item
        

'''A different approach is to use the binary tree， recursive implementation'''

def maxVal(toConsider, avail):
    if toConsider == [] or avail == 0:
        result = (0, ())
    elif toConsider[0].getWeight() > avail:
        result = maxVal(toConsider[1:], avail)
    else:
        nextItem = toConsider[0]
        #Explore left branch
        withVal, withToTake = maxVal(toConsider[1:], avail - nextItem.getWeight())
        withVal += nextItem.getValue()
        #Explore right branch
        withoutVal, withoutToTake = maxVal(toConsider[1:], avail)
        #Choose better branch
        if withVal > withoutVal:
            result = (withVal, withToTake + (nextItem,))
        else:
            result = (withoutVal, withoutToTake)
    return result

def smallTest():
    Items = buildItems()
    val, taken = maxVal(Items, 20)
    for item in taken:
        print item
    print 'Total value of items taken = ' + str(val)
    
# Optimize Fibonacci by memoization
def fastFib(x, memo):
    assert type(x) == int and x >= 0 and type(memo) == dict
    if x == 0 or x == 1:
        return 1
    if x in memo:
        return memo[x]
    result = fastFib(x - 1, memo) + fastFib(x - 2, memo)
    memo[x] = result
    return result
    






























    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    