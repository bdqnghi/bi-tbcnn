#include <iostream>


/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
*/

struct Node
  {
     int data;
     struct Node *next;
  };

void Print(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  if (head == nullptr) exit;
  std::cout << head->data << std::endl;
  if (head->next != nullptr) 
    Print(head->next);
}

int main(){
    
   Node n1,n2,n3;
   
   n1.data = 5;
   n1.next = &n2;
   
   n2.data = 7;
   n2.next = &n3;
   
   n3.data = 9;
   n3.next = NULL;
   
   Print(&n1);
   
   return 0; 
}
