//
//  linkedlist.cpp
//  linked-list-vi-clone
//

#include "linkedlist.hpp"

//  adds a new node to the linked list
//  if there is no head, it creates a head
//  takes data to put into node
void linkedlist::add(std::string data) {
    Node* node;
    
    if (head == NULL) {
        head = new Node(data);
        node = head;
    }
    else {
        node = head;
        while (node->next != NULL) {
            node = node->next;
        }
        Node* newNode = new Node(data);
        node->next = newNode;
    }
}

//  find a node in the linked list
//  takes index of node
//  returns linked list node at index
//  throws exception if node does not exist
linkedlist::Node* linkedlist::get(int index) {
    if (head==NULL) throw std::exception();
    if (index==0) return head;
    Node* node = head;
    for (int i = 0; i < index; i++) {
        if (node->next==NULL) {
            throw std::exception();
        }
        node = node->next;
    }
    return node;
}

//  insert a node before a given index
//  takes index to insert node before
//  takes data to put into node
//  throws exception if index is less than zero
//  throws exception if head is null
//  throws exception if node does not exist
void linkedlist::insert(int index, std::string data) {
    if (head==NULL || index < 0) throw std::exception();
    if (index == 0) {
        insertHead(data);
        return;
    }
    Node* node = head;
    int i;
    try {
        for (i = 0; i < index; i++) {
            if (node->next==NULL) {
                throw std::exception();
            }
            node = node->next;
        }
    }
    catch (...) {
        if (i>=index-1) {
            add(data);
            return;
        }
        else {
            throw std::exception();
        }
    }
    Node* newNode = new Node(data);
    
    if (node->next!=NULL) {
        newNode->next = node->next;
    }
    
    node->next = newNode;
}

void linkedlist::insertHead(std::string data) {
    if (head==NULL) {
        head = new Node(data);
    }
    else {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

//  removes a node from the linked list
//  takes index of node to remove
//  throws exception if index is less than zero
//  throws exception if head is null
//  throws exception if node does not exist
void linkedlist::remove(int index) {
    if (head==NULL || index < 0) {
        throw std::exception();
    }
    if (index==0) {
        removeHead();
        return;
    }
    Node* node = head;
    Node* prevNode = nullptr;
    for (int i = 0; i < index; i++) {
        if (node->next==NULL) {
            throw std::exception();
        }
        prevNode = node;
        node = node->next;
    }
    prevNode->next = node->next;
    free(node);
}

//  removes the head of the linked list
//  is only called by `linkedlist::remove(0)`
void linkedlist::removeHead() {
    Node* temp = head;
    head = head->next;
    free(temp);
}

//  replaces the data in a node in the linked list
//  takes index of node, and data to replace the node's data
//  throws exception if head is null
//  throws exception if index is less than zero
//  throws exception if node does not exist at index
void linkedlist::replace(int index, std::string data) {
	if (head == NULL || index < 0) throw std::exception();
	Node* node = head;
	for (int i = 0; i < index; i++) {
		if (node->next == NULL) {
			throw std::exception();
		}
		node = node->next;
	}
	node->data = data;
}
