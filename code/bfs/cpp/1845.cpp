//
// Created by maor on 22/11/16.
//

#include "BFS.h"
using namespace std;
//bfs constructors
BFS::BFS() {

}

BFS::BFS(Map* map, Intersection* interStart, Intersection* interEnd) {
    myMap = map;
    start = map->getIntersect(interStart);
    end = map->getIntersect(interEnd);
}
//runs the bfs algorithm.
void BFS::algorithm() {
    queue<Intersection*> queueAl;
    //the current intersection
    Intersection* currentP = this->start;
    currentP->updateVisit();
    queueAl.push(currentP);
    //push the start intersection in to the queueAl.
    while(*currentP != *end){
        vector<Intersection*> neighbors = this->myMap->neighbors(currentP);
        for(int i = 0; i < neighbors.size(); i++){
            Intersection* pPoint = neighbors[i];
            if(!(*pPoint).isVisited()){
                queueAl.push(pPoint);
                (*pPoint).setFather(currentP);
                (*pPoint).updateVisit();
            }
        }
        queueAl.pop();
        currentP = queueAl.front();
    }

    //initialize the stack
    Intersection* current = this->end;
    this->stackPath.push(current);
    while (current != start){
        this->stackPath.push((current)->getFather());
        current = (*current).getFather();
    }


}

//print the path (intersections).
//notice! if we print, the stack empty!!!!
void BFS::printPath() {
    while (this->stackPath.size() != 0) {
        Intersection *toPrint = this->stackPath.top();
        cout << toPrint << endl;
        this->stackPath.pop();
    }
}

//connect the 2 funcs. algorithm + print.
void BFS::runBFS() {
    algorithm();
    printPath();
}

BFS::~BFS() {

}

stack<Intersection *> BFS::getStackPath() {
    return this->stackPath;
}



