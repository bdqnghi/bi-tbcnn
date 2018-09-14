///Code file that implements linkedlist with insert, insert and length functions
#include "linkedlist.h"

/*! linkedlist contructors */
linkedlist::linkedlist(){
    head = tail = NULL;
    length = 0;
}

/*! Inserts a node into linkedlist that contains all the log details */
void linkedlist::insert_node(node *newnode){

    node* temp = newnode;
    temp->next = NULL;
    if (head == NULL){
        temp->next = head;
        head = temp;
        tail = temp;
        length++;
        return;
    }
    tail->next = temp;
    tail = temp;
    length++;
}

/*! Prints the linkedlist - Not used in code */
void linkedlist::print_list(){

    if (length == 0)
    {
        cout << "List : Empty";
        return;
    }
    node *p = head;
    while (p -> next != NULL)
    {
       cout << "Key - IP : " << p->key << "    "  << "Time : " << p->log_time << endl;
    }
}

/*! Returns the length of the linkedlist */
int linkedlist::get_length(){

    return length;
}
