#
#   GHOSTS & Pac-Man
#   By: Hunter Forsyth (c3forsyt) and "Lennox" Shou Hao Ho (g4hoshou)
#
#   Requires python2.7+ and pygame.
#

from node_class import *


'''
Simple queue class.

Used in bfs.
'''
class simple_queue:
    def __init__(self, lst):
        self.in_stack = lst
        self.out_stack = []

    def insert(self, obj):
        self.in_stack.append(obj)

    def extract(self):
        if not self.out_stack:
            self.in_stack.reverse()
            self.out_stack = self.in_stack
            self.in_stack = []
        return self.out_stack.pop()

    def __len__(self):
        return len(self.in_stack) + len(self.out_stack)


'''
Run BFS with a depth limit.
Return None if not possible.
'''
def depth_limited_bfs(start_node, target_coords, max_depth):

    #keep track of parents to enable backtracking later.
    parent = {}
    parent[start_node] = None

    #keep track of number of steps.
    steps = {}
    steps[id(start_node)] = 0

    #visited Nodes
    visited = set()

    queue = simple_queue([start_node])
    while len(queue) > 0:
        node = queue.extract()
        visited.add(node.get_coord())
        curr_steps = steps[id(node)]

        #depth check
        if curr_steps > max_depth:
            return None

        elif node.get_coord() in target_coords:
            journey = [node]
            while parent[node] != None:
                journey.append(parent[node])
                node = parent[node]

            journey.reverse()
            dir = gimme_direction(journey)

            return journey, dir

        neighbours = node.get_neighbours()

        for n in neighbours:
            if n.get_coord() not in visited:
                parent[n] = node
                steps[id(n)] = curr_steps + 1
                queue.insert(n)

    #failed
    return None


'''
Run unlimited depth BFS = limited depth BFS with depth limit = inf.
'''
def bfs(start_node, target_coord):
    return depth_limited_bfs(start_node, [target_coord], float('Inf'))


'''
Run unlimited depth BFS on more than one target.
Function returns the path and dir to the first target encountered.
'''
def multiple_target_bfs(start_node, target_coords):
    return depth_limited_bfs(start_node, target_coords, float('Inf'))