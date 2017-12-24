import heapq #for priority queue

from functions import attach_and_eval as a_a_e
from functions import generate_all_successors as g_a_s
from functions import manhattan_distance as m_h
from functions import propagate_path_improvements as p_p_i

import board_manipulation as b_m
from search_node import search_node


def main():
    board = b_m.generate_board(input('board 1-1 to 1-4 or 2-1 to 2-4:'))
    goal_location = b_m.locate(board, 'B')

    closed = {}
    open_d = {}

    existing = {}

    n0 = search_node(G = 0, Parent = None) # initiate n0 node
    n0.location = b_m.locate(board, 'A')
    n0.h = m_h(n0.location, goal_location)
    n0.f = n0.h + n0.g

    existing[n0.location] = n0 # adds n0 to existing dictionary, with key on node.location
    open_d[n0.location] = n0   # adds n0 to open dictionary, with key on node.location

    # stores in a first in first out q to get bfs
    fifo_q = [n0.location]

    n0.status = 'open_d' # states that n0 is opened
    solution = None

    # AGENDA LOOP
    while (solution is None):

        # check if there are no open nodes
        if (len(open_d.values()) == 0):
            print('fail')
            return 'fail'

        # assign node from fifo queue
        x = open_d[fifo_q.pop()]
        open_d.pop(x.location)

        # add x to closed dictionary
        closed[x.location] = x
        x.status = 'closed'

        # if manhattan distance is 0, reacehd goal
        if (m_h(x.location, goal_location)) == 0:
            print('success', x.state)
            return b_m.success(board, x, open_d, closed) # does not check other solution

        # generate all child noes to node x
        succssessors = g_a_s(board, x)

        # iterate childnode S to X
        for S in succssessors:

            # if childnode S already exist, set the node as closed,
            # else add the node to existing dictionary
            if (S in existing.keys()):
                succssessors[S].status = 'closed'
            else:
                existing[S] = succssessors[S]

            # add the child nodes to x.children list
            x.children.append(succssessors[S])

            # check if S is not closed and not open
            if succssessors[S].status is not 'open_d' and succssessors[S].status is not 'closed':

                # attach and eval routine
                a_a_e(board, succssessors[S], x, goal_location)

                # push S onto open dictionary (easy indexing) and fifo queue
                open_d[S] = succssessors[S]
                succssessors[S].status = 'open_d'
                fifo_q.insert(0,succssessors[S].location)

            # check if there is a cheaper way to S
            elif (x.g + b_m.calculate_g(board, succssessors[S])) < succssessors[S].g:

                #attach and eval routine
                a_a_e(board, succssessors[S], x, goal_location)

                #check if S is in the closed dictionary
                if S in closed:

                    # propagate path improvements
                    p_p_i(board, succssessors[S])

if __name__ == '__main__':
    main()