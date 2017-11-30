//
//  linkedlist.cpp
//  pre-final
//
//  Created by ibrahim ibrahim on 6/12/15.
//  Copyright (c) 2015 ibrahim ibrahim. All rights reserved.
//

#include "linkedlist.h"
#include "scrapper.h"
#include <iostream>
#include <cstdlib>

using namespace std;



/***************
 Constructor
 **************/

linklist::linklist()
{
    
    ListNode* sental = new ListNode;
    head=sental;
    head->next=head;
    head->prev=head;
    empty = true; //when it's first created, it's automatically empty

    
}



/*************************
 The insert function inserts a node with
 integer copied to its country member.
 *********************************/
void linklist::insert( Scrapper *spot)
{
    count++;
	
    empty = false; //the moment you insert a skyscraper, linklist isn't empty
    
    ListNode* object = new ListNode;
    object->toy_object=spot;
    
    
    if (head->next==head)
    {
        head->prev=object;
        object->next=head;
        head->next=object;
        object->prev=head;
        
    }
    else
    {
        head->prev->next=object;
        object->prev=head->prev;
        
        object->next=head;
        head->prev=object;
        
        
    }
    
    
}



/***************
 print, prints each number stored in each node
 which is pointed by the head
 print forwards
 **************/
void linklist::print()
{
    
    ListNode* ptr = head;
    ptr=ptr->next;
    
    while (ptr!=head)
    {
        
        
        cout << ptr->toy_object << endl;
        ptr=ptr->next;
        cout << endl;
    }
    cout << endl;
    
}


Scrapper *linklist::search(string name)
{
    Scrapper *notfound = NULL;
    
   ListNode* ptr = head;
    ptr=ptr->next;
    
    while (ptr!=head)
    {
        
        if(ptr->toy_object->getname()==name)
            return ptr->toy_object;
        
        ptr=ptr->next;
        
    }
    
    
    return notfound;
}

// remove the first object in the list
Scrapper *linklist::rehashingremove_top( )
{
    Scrapper *notfound =NULL;
    
    ListNode* ptr = head;
    ptr=ptr->next;
    
    if (ptr!=head)
    {
       
        
            ListNode* first= ptr->prev;
            ListNode* last= ptr->next;
            
            first->next = last;
            last->prev = first;
            
        
        
        notfound=ptr->toy_object;
        
        ptr->toy_object=NULL;
            
        return notfound;
        
    }
    else
    {
       return notfound;
    }
    
    
}


// removes tower from linked list
bool linklist::hashrejectedremove(string name)
{
    ListNode* ptr = head;
    ptr=ptr->next;
    
    while (ptr!=head)
    {
        
        if(ptr->toy_object->getname()==name)
        {
            ListNode* first= ptr->prev;
            ListNode* last= ptr->next;
            
            first->next = last;
            last->prev = first;
            
             ptr->toy_object=NULL;
            delete ptr->toy_object;
            count--;
            
            
            //////////////////////////////////////////////////
            // FIX hash table statistics
            
            //////////////////////////////////////////////////
            
            return true;
        }
        
        ptr=ptr->next;
        
    }
    
    
    return false;
}



