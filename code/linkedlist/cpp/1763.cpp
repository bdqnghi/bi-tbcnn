/*
 * Copyright (c) 2016 Lund University
 *
 * Written by Anton Cervin, Dan Henriksson and Martin Ohlin,
 * Department of Automatic Control LTH, Lund University, Sweden.
 *   
 * This file is part of TrueTime 2.0.
 *
 * TrueTime 2.0 is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * TrueTime 2.0 is distributed in the hope that it will be useful, but
 * without any warranty; without even the implied warranty of
 * merchantability or fitness for a particular purpose. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with TrueTime 2.0. If not, see <http://www.gnu.org/licenses/>
 */

#ifndef LINKEDLIST
#define LINKEDLIST

#include "linkedlist.h"

/** 
 * Node Constructor 
 */
Node::Node() {
  pNext = NULL;
  pPrev = NULL;
  myList = NULL;
}

/** 
 * Returns a pointer to the node after pNode 
 * NULL if pNode is last node 
 */
Node *Node::getNext() {
  
  return pNext;
}

/** 
 * Returns a pointer to the node before pNode,
 * NULL if pNode is first node 
 */
Node *Node::getPrev() {
  
  return pPrev;
}

/** 
 * Removes the node from its current list
 */
void Node::remove() {
  if (myList != NULL) {
    myList->removeNode(this);
  }
}

/** 
 * Removes the node from its current list
 * and inserts it sorted in newList
 */
void Node::moveToList(List* newList) {

  remove();
  newList->insertSorted(this);
}


/**
 * List Constructor 
 */
List::List(const char *n, int (*cf)(Node *, Node *)) {
  strncpy(name, n, MAXCHARS);
  compFcn = cf;
  pHead = NULL;
  pTail = NULL;
}

List::~List() {
  Node *p;
  while ((p = getFirst()) != NULL) {
    removeNode(p);
  }
}

/* Returns a pointer to the first node in the list */
Node *List::getFirst() {
  return pHead;
}

/* Returns a pointer to the last node in the list */
Node *List::getLast() {
  return pTail;
}

/* Appends a node to the end of the list */
void List::appendNode(Node *pNode)
{
  if (pHead == NULL) {
    pHead = pNode;
    pNode->pPrev = NULL;
  }
  else {
    pTail->pNext = pNode;
    pNode->pPrev = pTail;
  }
  pTail = pNode;
  pNode->pNext = NULL;

  pNode->myList = this;
}

/* Inserts a node into the list after pAfter */
void List::insertAfter(Node *pNode, Node *pAfter)
{
  pNode->pNext = pAfter->pNext;
  pNode->pPrev = pAfter;
  if (pAfter->pNext != NULL)
    pAfter->pNext->pPrev = pNode;
  else
    pTail = pNode;
  pAfter->pNext = pNode;

  pNode->myList = this;
}

/* Inserts a node into the list before pBefore */
void List::insertBefore(Node *pNode, Node *pBefore)
{
  pNode->pPrev = pBefore->pPrev;
  pNode->pNext = pBefore;
  if (pBefore->pPrev != NULL)
    pBefore->pPrev->pNext = pNode;
  else
    pHead = pNode;
  pBefore->pPrev = pNode;

  pNode->myList = this;
}

/** 
 * Inserts a node in the list, sorted using compFcn
 */
void List::insertSorted(Node *pNode)
{
  Node *p;

  // if no priority function, assume FIFO and insert node last in list
  if (compFcn == NULL) {
    appendNode(pNode);
    return;
  }

  p = pTail;    // insertion sort, starting from end of list
  if (p==NULL) {
    appendNode(pNode);
    return;
  }

  while (p!=NULL) {
    if (!compFcn(pNode,p)) { // if pNode does not beat p, insert after p
      insertAfter(pNode,p);  
      return;
    }
    p = p->pPrev;
  }
  insertBefore(pNode,pHead); // strictly lowest priority value, insert first
}

/* Removes the specified node from the list */
void List::removeNode(Node *pNode)
{
  if (pNode->pPrev == NULL) {
    pHead = pNode->pNext;
  } else {
    pNode->pPrev->pNext = pNode->pNext;
  }
  if (pNode->pNext == NULL) {
    pTail = pNode->pPrev;
  } else {
    pNode->pNext->pPrev = pNode->pPrev;
  }
  pNode->myList = NULL;
}

void List::deleteNode(Node *pNode)
{
  removeNode(pNode);
  delete pNode;
  pNode = NULL;
}

int List::length() {
  int len = 0;
  Node *n = pHead;
  while (n != NULL) {
    len++;
    n = n->pNext;
  }
  return len;
}

void List::print() {
  int i = 0;

  mexPrintf("%s:", name);
  Node *n = pHead;
  if (n == NULL) mexPrintf(" Empty");
  while (n != NULL) {
    mexPrintf(" %d.",++i);
    n->print();
    n = n->pNext;
  }
  mexPrintf("\n");
}

#endif
