# !/usr/bin/python
# -*- coding:utf-8 -*-
from collections import deque
graph = {}
graph['you'] = ['alice', 'bob', 'claire']
graph['bob'] = ['anuj', 'peggy']
graph['alice'] = ['peggy']
graph['claire'] = ['thom', 'jonny']
graph['peggy'] = []
graph['anuj'] = []
graph['thom'] = []
graph['jonny'] = []
record = []
def is_seller(item):
    return item == 'thom'
def search():
    search_deque = deque()
    search_deque += graph['you']
    while search_deque is not None:
        item = search_deque.popleft()
        if item not in record:
            record.append(item)
            if is_seller(item):
                print '%s is the seller' % item
                return True
            search_deque += graph[item]
    return False
if __name__ == '__main__':
    search()

# 这之间涉及到了列表，字典基本数据类型.
# 队列,图等多种数据结构
# 此算法为广度优先算法：
#               - 广度优先算法，解决是否有路径
#               -　以及最短路径
