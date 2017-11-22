#include "Bfs.h"
#include <queue>

using namespace std;

stack<AbstractNode *> Bfs::BfsAlgorithm(AbstractNode *source, AbstractNode *destination) {
    stack<AbstractNode *> stackTrail; // Use for printing in right order.
    queue<AbstractNode *> queue; // Use to save the track.
    AbstractNode *currNode;
    AbstractNode *currNode2;

    source->setDistance(0);
    queue.push(source); // Adding the first point to the queue.
    currNode = source;
    currNode2 = currNode;

    while (!queue.empty()) { // Stop when the queue is empty and its last node.
        AbstractNode *node;
        node = queue.front(); // Getting the first node.
        queue.pop(); // Deleting the first node.

        if (destination == currNode) { // Found the destination.

            while (currNode != source) { // Saving the track into the stack.
                stackTrail.push(currNode);
                currNode = currNode->getPrev();
            }
            stackTrail.push(currNode);
        }

        for (int i = 0; i < node->getNumOfNeighbors(); i++) { // Pass all the node neighbors.

            if ((node->getNeighbors()[i]->getDistance() == -1) && (!node->getObstacle())) {
                node->getNeighbors()[i]->setDistance(
                        node->getDistance() + 1); // Update the distance.
                node->getNeighbors()[i]->setPrevNode(node); // Update the previous node.
                queue.push(node->getNeighbors()[i]); // Push the neighbor to the queue.
                currNode = node->getNeighbors()[i]; // Go to the previous neighbors.
                if (currNode == destination) {
                    break;
                }
            }
        }
    }

    return stackTrail;
}

Bfs::~Bfs() {

}

Bfs::Bfs() {}
