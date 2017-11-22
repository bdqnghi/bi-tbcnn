#include <stdio.h>
#include <iostream>
#include <map>
#include <typeinfo>

struct Node
{
  int value;
  Node* p_next;
};

void printList(Node* root)
{
  std::cerr << root->value << " -> ";
  while(root->p_next != NULL)
  {
    root = root->p_next;
    std::cerr << root->value << " -> ";
  }
  std::cerr << "NULL" << std::endl;
}

void insertNode(Node* root, int value, Node* next = NULL)
{
  while(root->p_next != NULL)
  {
    root = root->p_next;
  }
  Node* n = new Node();
  n->value = value;

  n->p_next = next;
  root->p_next = n;
}

void deleteFirst(Node* root, int value)
{
  while( root->p_next != NULL )
  {
    if( root->value == value )
    {
      root->value = root->p_next->value;
      root->p_next = root->p_next->p_next;
      return;
    }
    root = root->p_next;
  }
}


Node* reverseList(Node* current)
{
  Node* parent = NULL; // first element has to be the last one

  while( current != NULL )
  {
    std::cout << "reversing " << current->value << std::endl;
    Node* next = current->p_next;
    current->p_next = parent;
    parent = current;

    current = next;
  }
  return parent;
}

Node* initList( int value=1)
{
  Node* root;
  root->value = value;
  return root;
}


/* wrong solution, does only detect full loops */
bool detectCycle( Node* init )
{
  Node* head = init;

  while (init->p_next != NULL)
  {
    if (init->p_next == head)
    {
      std::cerr << "Cycle found at " << init->p_next->value << std::endl;
      return true;
    }
    init = init->p_next;
  }
  return false;
}

bool isCyclic( Node* init )
{
  Node* slow_runner = init;
  Node* fast_runner = init;

  while( fast_runner->p_next != NULL && fast_runner->p_next->p_next != NULL )
  {
    if (fast_runner->p_next == slow_runner)
    {
      return true;
    }
    slow_runner = slow_runner->p_next;
    fast_runner = fast_runner->p_next->p_next;
  }
  return false;
}

Node* getCycleStart( Node* init )
{
  Node* slow_runner = init;
  Node* fast_runner = init;

  Node* meeting_point = NULL;
  while (fast_runner->p_next != NULL /*&& fast_runner->p_next->p_next != NULL*/)
  {
    slow_runner = slow_runner->p_next;
    fast_runner = fast_runner->p_next->p_next;
    if (slow_runner == fast_runner)
    {
      meeting_point = fast_runner;
      break;
    }
  }

  if (meeting_point == NULL)
  {
    return NULL;
  }

  slow_runner = init;
  std::cerr << "meeting point at: " << fast_runner->value << std::endl;
  while (slow_runner != fast_runner)
  {
    slow_runner = slow_runner->p_next;
    fast_runner = fast_runner->p_next;
  }
  return slow_runner;
}

int main()
{
  Node* n1 = new Node();
  n1->value = 1;
  n1->p_next = NULL;

  Node* n2 = new Node();
  n2->value = 1;
  n2->p_next = n1;

  std::cerr << " 2 nodes are the same " << ((n1==n2->p_next)?"true":"false") << std::endl;

  Node* init = new Node();
  init->value = 1;
  init->p_next = NULL;

  std::cerr << "is cyclic for one element: " << (isCyclic(init)?"true":"false") << std::endl;
  insertNode(init, 2);
  insertNode(init, 3);
  insertNode(init, 4);
  insertNode(init, 5);
  insertNode(init, 6);
  insertNode(init, 7);
  
  //deleteFirst(init, 3);
  printList(init);

  //printList( reverseList(init) );

  //std::cerr << "is cyclic: " << (isCyclic(init)?"true":"false") << std::endl;
  /* create full cycle */
  //insertNode(init, 7, init);
  //std::cerr << "detected full cycle: " << (isCyclic(init)?"true":"false") << std::endl;

  insertNode(init->p_next, 8, init->p_next->p_next->p_next->p_next );
  std::cerr << "is cyclic: " << (getCycleStart(init)->value) << std::endl;
  return 0;
}
