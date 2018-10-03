#include "dfs.hpp"
#include <cassert>
#include <iostream>

using namespace leda;

/* Does a DFS to determine whether the graph is connected or not */
bool is_connected(const ugraph& g) {
    unsigned int number_of_nodes = g.number_of_nodes();

    assert(number_of_nodes>0);

    node* stack = new node[number_of_nodes];
    const node* base = stack;
    *stack = g.first_node();

    node_array<bool> visited(g,false);
    visited[*stack] = true;

    unsigned int number_seen=1;

    while(stack>=base) {
        //pop from stack
        const node current = *stack;
        stack--;
        node next_node;

        //push unvisited neighbours
        forall_adj_nodes(next_node,current) {
            if (!visited[next_node]) {
                stack++;
                *stack = next_node;
                visited[next_node] = true;
                number_seen++;
            }
        }
    }

    delete[] base;
    return number_seen==number_of_nodes;
}

bool dfs_order(const ugraph& g, const node startnode, node ordered[]) {
    unsigned int number_of_nodes = g.number_of_nodes();

    node* stack = new node[number_of_nodes];
    const node* base = stack;
    stack[0] = startnode;

    node_array<bool> visited(g,false);
    visited[*stack] = true;
    ordered[0] = *stack;

    unsigned int number_seen=1;
    unsigned int dfi = 0;

    while(stack>=base) {
        //pop from stack
        const node current = *stack;
        ordered[dfi++] = current;
        stack--;
        node next_node;

        //push unvisited neighbours
        forall_adj_nodes(next_node,current) {
            if (!visited[next_node]) {
                stack++;
                *stack = next_node;
                visited[next_node] = true;
                number_seen++;
            }
        }
    }
    assert(dfi==number_seen);
    delete[] base;
    return number_seen==number_of_nodes;
}
