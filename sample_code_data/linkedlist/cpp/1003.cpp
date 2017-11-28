#include "./linkedlist.h"
#include <iostream>
#define COUT std::cout
#define ENDL std::endl
// Note: when compiling, add "-std=c++11" 
// or "-std=c++0x" if using nullptr instead of NULL

LinkedList::LinkedList() :
  size(0),
  head(nullptr),
  tail(nullptr)
  {  }

LinkedList::~LinkedList() {
  while (head) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  COUT << "Object was deleted" << ENDL;
}

bool LinkedList::insert(int key) {
  if (contains(key)) return false; // no duplicates
    Node *next = new Node();
    next->key = key;
    next->prev = nullptr;
    next->next = nullptr;
  if (size == 0) {
    head = tail = next;
    size++;
    return true;
  } else if (size > 0) {
    next->prev = tail;
    tail->next = next;
    tail = tail->next;
    size++;
    return true;
  }
  return false;
}

bool LinkedList::insertAfter(int target, int key) {
  if (contains(key)) return false; // no duplicates
  Node *theNode = new Node();
  theNode->key = key;
  theNode->prev = nullptr;
  theNode->next = nullptr;
  if (size > 0) {
    Node *temp = head;
    while (temp->next) {
      if (temp->key == target) {
        theNode->next = temp->next;
        temp->next->prev = theNode;
        temp->next = theNode;
        theNode->prev = temp;
        size++;
        return true;
      }
      temp = temp->next;
    }
  }
  return false;
}

bool LinkedList::deleteHead() {
  Node *temp = head;
  head->next->prev = nullptr;
  head = head->next;
  delete temp;
  size--;
  return true;
}

bool LinkedList::deleteTail() {
  Node *temp = tail;
  tail->prev->next = nullptr;
  tail = tail->prev;
  delete temp;
  size--;
  return true;
}

bool LinkedList::remove(int target) {
  Node *temp = head;
  while (temp) {
    if (temp->key == target) {
      if (!temp->prev) {
        // head
        head = temp->next;
      } else {
        temp->prev->next = temp->next;
      }
      if (!temp->next) {
        // tail
        tail = temp->prev;
      } else {
        temp->next->prev = temp->prev;
      }
      size--;
      delete temp;
      return true;
    }
    temp = temp->next;
  }
  return false;
}

bool LinkedList::removeR(int target) {
  return removeR_h(target, head);
}

bool LinkedList::removeR_h(int target, Node * currentNode) {
  if (currentNode->key == target && head->key == currentNode->key) {
    // head
    head = currentNode->next;
    head->prev = nullptr;
    delete currentNode;
    size--;
    return true;
  } else if (currentNode->key == target && tail->key == currentNode->key) {
    // tail
    tail = currentNode->prev;
    tail->next = nullptr;
    delete currentNode;
    size--;
    return true;
  }
  else if (currentNode->key == target) {
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;
    delete currentNode;
    size--;
    return true;
  } else return removeR_h(target, currentNode->next);
}

bool LinkedList::contains(int key) {
  Node *currentNode = head;
  while (currentNode) {
    if (currentNode->key == key) {
      return true;
    }
    currentNode = currentNode->next;
  }
  return false;
}

void LinkedList::printList() {
  Node *curr = head;
  while (curr) {
    COUT << curr->key << "<-->";
    curr = curr->next;
  }
  COUT << "nullptr" << ENDL;
}
