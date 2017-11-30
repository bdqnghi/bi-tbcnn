/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  Node* node = head;
  int N = 0;
  while(node->next != NULL) {
    N++;
    node = node->next;
  }
  node = head;
  int pos = N-positionFromTail;
  while(pos--) {
    node = node->next;
  }
  return node->data;
}

/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
	Node* A = headA;
  	Node* B = headB;
  	
  	while(1) {
      if(A == NULL && B == NULL)
        return 1;
      if(A != NULL && B== NULL)
        return 0;
      if(A == NULL && B != NULL)
        return 0;
      if(A->data != B->data)
        return 0;
      A = A->next;
      B = B->next;
    }
  	if(B->next != NULL)
      return 0;
  	return 1;
}

/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
 	Node *cur = head; 
    while (cur != NULL) {
        Node *next = cur->next;
        if ((next != NULL) && (next->data == cur->data)) {
            cur->next = next->next;
        } else {
            cur = next;
        }
    }
    return head;
}

/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
  Node* temp = head;
  if(position == 0){
    head = head->next; //move from head (1st node) to second node
  }else{
    Node* prev = head;
    temp = head->next;
    for(int i=1;i<position;++i){
      prev = temp;
      temp = temp->next;
      
    }
    prev->next = temp->next;
  }
  
  return head;
}

/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
  Node* newHead = new Node();
  newHead->data = data;
  
  if(head != NULL)
    newHead->next = head;
  
  return newHead;
  
}

/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
  Node* tail = new Node();
  tail->data = data;
  
  if(head == NULL) {
    return tail;
  }
  
  Node* cur = head;
  while(cur->next != NULL) {
    cur = cur->next;
  }
  
  cur->next = tail;
  
  return head;
}

/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
  Node* curA = headA;
  while(curA != NULL) {
    Node* curB = headB;
    while(curB != NULL) {
      if(curA->data == curB->data) {
        return curA->data;
      }
      curB = curB->next;
    }
   	curA = curA->next; 
  }
}

/*
  Insert Node at a given position in a linked list 
  The linked list will not be empty and position will always be valid
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
  Node* newNode = new Node();
  newNode->data = data;
  
  if(position == 0) {
    newNode->next = head;
    return newNode;
  }
  Node* cur = head;
  for(int i=1;i<position;++i) {
    cur = cur->next;
  }
  newNode->next = cur->next;
  cur->next = newNode;
  
  return head;
}

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
  
  Node* mergedHead = NULL;
  Node* cur = mergedHead;
  while(1) {
    if(headA == NULL && headB == NULL)
      return mergedHead;
    
    if(headB == NULL || headA != NULL && headA->data < headB->data) {
      if(mergedHead == NULL) {
        mergedHead = headA;
        cur = mergedHead;
      }
      else {
        //std::cout << "adding " << headA->data << " from A" << std::endl;
        cur->next = headA;
        cur = cur->next;
      }
      headA = headA->next;
    }
    else {
      if(mergedHead == NULL) {
        mergedHead = headB;
        cur = mergedHead;
      }
      else {
        cur->next = headB;
        cur = cur->next;
      }
      headB = headB->next;
    }
  }
  return mergedHead;
}

/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int HasCycle(Node* head)
{
   // Complete this function
   // Do not write the main method
  Node* stepper = head;
  Node* twoStepper = head;
  
  while(stepper && twoStepper && twoStepper->next) {
    stepper = stepper->next;
    twoStepper = twoStepper->next->next;
    if(stepper == twoStepper)
      return 1;
  }
  return 0;
}

/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
  	if(!head) return head;
  
 		Node *temp = NULL;  
     Node *current = head;
      
     /* swap next and prev for all nodes of 
       doubly linked list */
     while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
     }      
      
     /* Before changing head, check for the cases like empty 
        list and list with only one node */
     if(temp != NULL )
        head = temp->prev;
  
  return head;
}

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{

  Node *current, *next, *prev;
  current = head;
  prev = NULL;
  while(current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}

/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  if(head == NULL) {
    return;
  }
  ReversePrint(head->next);
  std::cout << head->data << std::endl;
}

/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void Print(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  while(head) {
    std::cout << head->data << std::endl;
    head = head->next;
  }
}

/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.
  
  // Complete this function
    // Do not write the main method.
    Node * temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
  //head null return temp
    if (head == NULL)
    {
        head = temp;
        return head;
    }
//temp < head
    if (temp->data <= head->data)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }

    Node *curr = head;
  //iterate to node 
    // N <-> 1 <-> 2 <-> 4 <-> 5 <-> N
    while (curr->next!=NULL)
    {
      
        if (temp->data <= curr->data)
        {
            break;
        }

        curr = curr->next;
    }

  //insert before
  	if (temp->data <= curr->data)
    {   
      curr->prev->next = temp;
      temp->prev = curr->prev;
      temp->next = curr;
      curr->prev = temp;
      return head;
    }
  //insert at end
    curr->next = temp;
    temp->prev = curr;
    return head;
}