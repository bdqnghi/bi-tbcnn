//
//  linkedlist.cpp
//  Lab03
//
//  Created by Christian Joachim on 9/21/16.
//  Copyright © 2016 Christian Joachim. All rights reserved.
//

#include "linkedlist.hpp"
#include "node.hpp"
#include <iostream>
#include <string>
using namespace std;

LinkList::LinkList()
{
    head = NULL;
    tail = NULL;
    
    
}

LinkList::LinkList(string input)
{
    head = new node(input);
    tail   = head;
    
    
    
}

LinkList::~LinkList()
{
    for (node* current = head; current != NULL; current = head)
    {
        head = current->get_next_ptr();
        delete current;
    }
    
    
}

bool LinkList::Insert(string new_data)
{
    if (head == NULL) {
        head = new node(new_data);
        tail = head;
    }
    else{
        tail->set_next_ptr(new node(new_data));
        tail = tail->get_next_ptr();
    }
    return true;
}

bool LinkList::Search(string new_data)
{
    
    node* current = head;
    
    while (current != NULL)
    {
        if (new_data == current->data)
        {
            return true;
        }
        else current = current->next;
    }
    return false;
}

void LinkList::print_list()
{
    
    for (node* current = head; current != NULL; current = current->get_next_ptr())
    {
        
        cout << current->get_data() << " --> ";
    }
    cout << "NULL" << endl;
    
}

