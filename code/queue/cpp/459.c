#include "queue.h"

using namespace std;

/***********************************************************************
Constructor
***********************************************************************/
queue::queue()
{
 qFront = '\0';
 qRear = '\0';
}

/***********************************************************************
Destructor
***********************************************************************/
queue::~queue()
{
 MakeEmpty();
}

/***********************************************************************
Enqueue- Put a new elemtent into the queue
***********************************************************************/
void queue::Enqueue(int newItem)
{
 node* newNode;

 newNode = new node;
 newNode->data = newItem;
 newNode->next = '\0';

 if(qRear == '\0')
   qFront = newNode;

 else
   qRear->next = newNode;

 qRear = newNode;
} 

/***********************************************************************
Dequeue- Take an element out of the queue, passed by reference
***********************************************************************/
void queue::Dequeue(int& item)
{
 if(!IsEmpty())
 {
 node* tempPtr;

 tempPtr = qFront;
 item = qFront->data;
 qFront = qFront->next;

 if(qFront == '\0')
   qRear = '\0';

 delete tempPtr;
}
} 


/***********************************************************************
MakeEmpty-deletes elements in the queue
***********************************************************************/
void queue::MakeEmpty()
{
 node* tempPtr;

 while(qFront != '\0') 
 {
   tempPtr = qFront;
   qFront = qFront->next;
   delete tempPtr;
 }

 qRear='\0';
} 

/***********************************************************************
IsEmpty- if the front of the queue is equil to null return true 
***********************************************************************/
bool queue::IsEmpty() const
{
 return(qFront == '\0');
}
/***********************************************************************
IsFull- Always returns false 
***********************************************************************/
bool queue::IsFull() const
{
   return false;
}


