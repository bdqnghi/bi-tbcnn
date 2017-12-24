#!/usr/bin/env python

###########
# Mergesort
# Split list into halves until there are 1-unit lists, and then do an 
# ordered merge, where each list merged with be ordered.

def peek(list):
    try:
        return list[0]
    except:
        return None

def merge(l1, l2):
    to_return = []
    while len(l1) or len(l2):
        l1next = peek(l1)
        l2next = peek(l2)
        if l2next == None and l1next != None:
            to_return.append(l1.pop(0))
        elif l1next == None and l2next != None:
            to_return.append(l2.pop(0))
        elif l1next >= l2next:
            to_return.append(l2.pop(0))
        elif l1next < l2next:
            to_return.append(l1.pop(0))
            
    print "Returning %s" % to_return
    return to_return

def mergesort(list):
    if len(list) == 1:
        return list;
    midway = int(len(list) / 2)
    l1 = list[:midway]
    l2 = list[midway:]
    return merge(mergesort(l1), mergesort(l2))

if __name__ == '__main__':
    data = [1,4,6,8,5,2,1,5,6,7,8]
    print "Sorting %s" % data
    print mergesort(data)
