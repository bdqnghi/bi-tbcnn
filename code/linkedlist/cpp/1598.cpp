#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <ctime>
#include <clocale>
#include <cstdio>
#include "linkedlist.h"
#include "cell.h"

using namespace std;

// CONSTRUCTOR / DECONSTRUCTOR
LinkedList::LinkedList(){
    LinkedList::start = NULL;
}

LinkedList::~LinkedList(){
    //just incase
}

// GETTERS / SETTERS
Cell LinkedList::getStartData(){
    return LinkedList::start->data;
}

Cell LinkedList::getFinishCell(){
    return LinkedList::finish->data;
}

// OTHER PUBLIC FUNCTIONS
void LinkedList::insertCell(Cell item){
    //adding the node to the front of the link list and making start point to it
    Node* n = new Node;
    n->next = NULL;
    
    n->data = item;
    
    if (start != NULL) {
        current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = n;
        finish = n;
    }
    else{
        start = n;
        finish = n;
    }
}



void LinkedList::deleteCell(Cell item){
    Node* deletedNode = NULL;
    //set my temp and my current both to my start
    fugitive = start;
    current = start;
    
    //check to see if there are things in the linked list
    //if there is, is the current one the one im trying to delete?
    //everytimes its not incremenet and have fugitive trail
    //behind to try again for the next one, until I find the last node
    //essentiall cycle through any list to find the cell that I want to delete
    while (current != NULL and !(item.getCol() == current->data.getCol() and item.getRow() == current->data.getRow())) {
        fugitive = current;
        current = current->next;
    }
    
    //we traversed the list and it wasnt there just delete it, nice try
    if (current == NULL) {
        delete deletedNode;
    }
    
    //if
    else{
        //wire up the things around the node im deleting
        deletedNode = current;
        current = current->next;
        fugitive->next = current;
        
        //special cases
        //start pointer needs special attention
        if (deletedNode == start) {
            start = start->next;
        }
        //if what we are deleting is the finish node, then we must go back one
        if (fugitive->next == NULL) {
            finish = fugitive;
        }
        
        fugitive = NULL;
        delete deletedNode;
    }
}

