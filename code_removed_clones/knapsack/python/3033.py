class Item(object):
    def __init__(self, n, v, w):
        self.name = n
        self.value = float(v)
        self.weight = float(w)
    def getName(self):
        return self.name
    def getValue(self):
        return self.value
    def getWeight(self):
        return self.weight
    def __str__(self):
        return '<' + self.name + ', ' + str(self.value) + ', '\
                     + str(self.weight) + '>'

def buildItems():
    return [Item(n,v,w) for n,v,w in (('clock', 175, 10),
                                      ('painting', 90, 9),
                                      ('radio', 20, 4),
                                      ('vase', 50, 2),
                                      ('book', 10, 1),
                                      ('computer', 200, 20))]

def greedy(items, maxWeight, metric):
    knapsack = []
    totalW = 0
    # process items in order of metric, biggest first
    for item in sorted(items, key=metric, reverse=True):
        w = item.getWeight()
        # if item will fit in knapsack, take it!
        if w + totalW <= maxWeight:
            knapsack.append(item)
            totalW += w
    return knapsack
            
# metric: use item's value
def value(item):
    return item.getValue()

# metric: use item's "lightness" = inverse of weight
def weightInverse(item):
    return 1.0/item.getWeight()

# metric: use item's value/weight
def density(item):
    return item.getValue()/item.getWeight()

# try greedy algorithm with given metric, print result
def testGreedy(items, maxWeight, metric):
    taken = greedy(items, maxWeight, metric)
    val = sum(map(Item.getValue,taken))
    print 'Total value of items taken = ', val
    for item in taken:
        print '  ', item

# try greedy algorithm with all three metrics
def testGreedys(maxWeight = 20):
    items = buildItems()
    print 'Items to choose from:'
    for item in items:
        print '  ', item
    print 'Use greedy by value to fill a knapsack of size', maxWeight
    testGreedy(items, maxWeight, value)
    print 'Use greedy by weight to fill a knapsack of size', maxWeight
    testGreedy(items, maxWeight, weightInverse)
    print 'Use greedy by density to fill a knapsack of size', maxWeight
    testGreedy(items, maxWeight, density)

# generate all combinations of N items
def powerSet(items):
    N = len(items)
    # enumerate the 2**N possible combinations
    for i in xrange(2**N):
        combo = []
        for j in xrange(N):
            # test bit jth of integer i
            if (i >> j) % 2 == 1:
                combo.append(items[j])
        yield combo

# exhaustive search: evaluate each possible combination of items
def chooseBest(pset, maxWeight):
    bestVal = 0.0
    bestSet = None
    for set in pset:
        weight = sum(map(Item.getWeight,set))
        val = sum(map(Item.getValue,set))
        if weight <= maxWeight and val > bestVal:
            bestVal = val
            bestSet = set
    return (bestSet, bestVal)

# look for optimum solution to burglar's problem
def testBest():
    items = buildItems()
    pset = powerSet(items)
    taken, val = chooseBest(pset, 20)
    print 'Total value of items taken =',val
    for item in taken:
        print '  ', item

# build a list of n items of various weights and values
import random
def buildRandomItems(n):
    return [Item(str(i),10*random.randint(1,10),random.randint(1,10))
            for i in xrange(n)]

# determine average running time of chooseBest with n items
import time
def timeChooseBest(n,ntrials=10):
    # time how long it takes to run chooseBest(items,20)
    def howLong(items):
        pset = powerSet(items)
        start = time.clock()
        chooseBest(pset,20)
        stop = time.clock()
        return stop - start

    # run the specified number of trials
    times = [howLong(buildRandomItems(n))
             for i in xrange(ntrials)]

    print 'Average running time was',sum(times)/ntrials,'seconds.'


