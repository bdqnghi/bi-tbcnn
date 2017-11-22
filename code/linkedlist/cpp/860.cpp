////////////////////////////////////////////////////////////////////////////////////
// roll number                    : cs09b010                                      //
// name                           : sujeet gholap <sujeetgholap@gmail.com>        //
// aim                            : to implement a singly linked list of integers //
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Node 
{ 
public: 
     int data; 
     Node *next; 
     Node() {next = NULL;} 
     Node(int num, Node * next_node = NULL) {data = num; next = next_node;} 
};

class List 
{ 
private :
     Node *head; 
public: 
     List();
     List(Node *);
     void insert(int);
     void insert_After(int, int);
     void delete_Element(int);
     bool search(int);
     bool is_Empty (); 
     Node * next_Node(Node *); 
     void print(); 
};

List::List () 
{
     head = NULL;
}

List::List (Node * head) 
{
     head = head;
}

void List::insert (int value)
{
     // make an new node with data=value and prepend it to list and shift the head to it
     Node * new_head = new Node (value);
     new_head->next = this->head;
     this->head = new_head;
}

void List::insert_After (int number_to_insert, int number_in_list)
{
     // if number_in_list not found, append the new node to the tail of the list
     Node * current_node = this->head;
     if ( current_node == NULL ) {
          // the list is empty
          this->insert (number_to_insert);
          return;
     }
     while (( current_node->next != NULL )&&( current_node->data != number_in_list )) {
          // the loop exits when current node is tail or it is the one to which we should append
          current_node = current_node->next;
     }
     Node * new_node = new Node (number_to_insert, current_node->next);
     current_node->next = new_node;
}

void List::delete_Element (int number_to_delete)
{
     Node * current_node = this->head;
     Node * next_node;
     if ( current_node == NULL ) {
          // the list is empty
          return;
     }
     next_node = current_node->next;
     if ( current_node->data == number_to_delete ) {
          // the head is to be deleted
          delete this->head;
          this->head = next_node;
     }
     while (( next_node != NULL )&&( next_node->data != number_to_delete)) {
          // loop is exited when current node is tail or
          // next node is to be deleted
          current_node = current_node->next;
          next_node = next_node->next;
     }
     if ( next_node == NULL ) {
          // element not found do nothing
          return;
     }
     if ( next_node->data == number_to_delete ) {
          current_node->next = next_node->next;
          delete next_node;
     }
}

bool List::search (int number_to_search)
{
     Node * current_node;
     for ( current_node = this->head; current_node != NULL; current_node = current_node->next ) {
          if ( current_node->data == number_to_search ) {
               return true;
          }
     }
     return false;
}

bool List::is_Empty ()
{
     if ( this->head == NULL ) return true;
     else return false;
}

Node * List::next_Node (Node * somenode)
{
     if ( somenode == NULL ) {
          cerr << "ERROR : NULL does not have any next node." << endl;
          return NULL;
     }
     if (not(this->search(somenode->data))) {
          cerr << "ERROR : The list does not have any node with " << somenode->data << " stored in it." << endl;
          return NULL;
     }
     return somenode->next;
}

void List::print ()
{
     Node * current_node;
     for ( current_node = this->head; current_node != NULL; current_node = current_node->next ) {
          cout << current_node->data << " ";
     }
     cout << endl;
}

int main()
{
     // uncomment the following lines to test

     // List list;
     // list.print();
     // if (list.is_Empty()) cout << "empty" << endl;
     // else cout << "not empty" << endl;
     // for (int i = 0; i < 10 ; i++) list.insert(i);
     // list.print();
     // if (list.search(4)) cout << "4 is in list." << endl;
     // else cout << "4 is not in list." << endl;
     // list.delete_Element(4);
     // list.print();
     // if (list.search(4)) cout << "4 is in list." << endl;
     // else cout << "4 is not in list." << endl;
     // list.insert_After(49, 6);
     // if (list.is_Empty()) cout << "empty" << endl;
     // else cout << "not empty" << endl;
     // list.print();
     // list.insert_After(99, 12);
     // list.print();
     // list.delete_Element(99);

     return 0;
}
