#include <iostream>
//#include <stdlib>
#include <vector>

using namespace std;



struct node
{	
	struct node *next;
	int data;
};

struct nodeDLL
{
	struct nodeDLL *next;
	struct nodeDLL *prev;
	int data;
};


struct Node
{
	struct Node *next,*arbit;
	int data;
};



struct tree *sortedLLtoBSTRecur(node **head, int n);

void createLL(struct node **head, int data)
{
	struct node *new_node = new node();
	new_node->data = data;
	if (*head == NULL)
	{
		*head = new_node;
		(*head)->next = NULL;
		return;
	}
	new_node->next = *head;
	*head = new_node;
}

node *newnode(int data) {
	struct node *nnode = (struct node *)malloc(sizeof(struct node));
	nnode->data = data;
	nnode->next = NULL;

	return nnode;
}

void createDLL(struct nodeDLL **head, int data)
{
	struct nodeDLL *new_node = new nodeDLL();
	new_node->data = data;
	if (*head == NULL)
	{
		*head = new_node;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		return;
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	new_node->prev = NULL;
	*head = new_node;
}

void createNodeLL(struct Node **head, int data)
{
	struct Node *new_node = new Node();
	new_node->data = data;
	if (head == NULL)
	{
		*head = new_node;
		(*head)->next = NULL;
		return;
	}
	new_node->next = *head;
	new_node->arbit=NULL;
	*head = new_node;
}

struct node *NthNode(struct node *head, int n)
{
	int count=0;
	struct node * temp = head;
	if ( head == NULL)
		return NULL;
	
	while (temp) {
		if (count == n)
			return temp;
		
		temp=temp->next;
		count++;
	}
	cout<<"n is greater than the list size"<<endl;
	return NULL;
}

void printLL(struct node *head)
{
	if (head == NULL) {
		cout << "LL is null " <<endl;
			return;
	}
	else {
		struct node *temp;
		temp = head;
		while (temp) {
			cout << temp->data;
			if(temp->next)
				cout << "->" ;
			temp = temp->next;
		}
		cout << endl;
	}	
}

void printDLL(struct nodeDLL *head)
{
	if (head == NULL) {
		cout << "LL is null " <<endl;
			return;
	}
	else {
		struct nodeDLL *temp;
		temp = head;
		while (temp) {
			cout << temp->data;
			if(temp->next)
				cout << "->" ;
			temp = temp->next;
		}
		cout << endl;
	}
}

void printNodeLL(struct Node *head)
{
	if (head == NULL) {
		cout << "LL is null " <<endl;
			return;
	}

	struct Node *temp=head;
	cout<<"using next"<<endl;
	while (temp) {
		cout << temp->data;
		if(temp->next)
			cout << "->" ;
		temp = temp->next;
	}

	temp=head;
	cout << endl<<"using arbit"<<endl;
	while(temp) {
		cout<<temp->arbit->data;
		if(temp->next)
			cout << "->" ;
		temp = temp->next;
	}
	cout<<endl;
}

void printCLL(struct node *head) {
	if (head == NULL) {
		cout << "LL is null " <<endl;
			return;
	}

	struct node *temp;
	temp = head;
	do {
		cout << temp->data;
	//	if(temp->next)
		cout << "->" ;
		temp = temp->next;
	} while (temp!=head);
	cout << endl;
}

void removeDup(struct node *head)
{
	bool *hashInt=new bool[10];
	int i;
	if(!head) {
		cout << "LL is empty" << endl;
		return;
	}

	for(i=0;i<10;i++)
		hashInt[i]=false;

	struct node *temp=head;
	struct node *previous=NULL;

	while(temp) {
		if(hashInt[temp->data]) {
			cout<<"deleted node value :"<<temp->data<<endl;
			previous->next = temp->next;
			delete temp;
		}
		else {
				previous=temp;
				hashInt[temp->data]=true;
		}
		temp=temp->next;
	}
//	printLL(head);
}

void removeDupWOBuffer(struct node *head)
{
	if(!head) {
		cout << "LL is empty" << endl;
		return;
	}

	struct node *current,*runner,*previous;
	current=head->next;
	previous=head;

	while(current) {
		runner=head;
		while(runner!=current) {
			if(runner->data==current->data) {
				previous->next=current->next;
				current=current->next;
				break;
			}
			runner=runner->next;
		}
		if(runner==current) {
			previous=current;
			current=current->next;
		}
	}
	printLL(head);
}

void nthNodefromLast(struct node *head,int n) {
	struct node *current=head,*nbehind=head;
	int count=0;
	if(!head || n<1) {
		cout<<"empty LL"<<endl;
		return;
	}


	while(current) {
		if(count<=n) {
			count++;
			current=current->next;
			if(!current) {
				cout<< "n should not be greater than the size of LL" <<endl;
				return;
			}
		}
		else {
			nbehind=nbehind->next;
			current=current->next;
		}
	}
	cout<<"result node is "<<nbehind->data<<endl;
}

void deleteMiddle(struct node *middle) {
	struct node *temp;

	if(!middle || !middle->next) {
		cout<<"invalid node"<<endl;
		return;
	}

	temp=middle->next;
	middle->data=temp->data;
	middle->next=temp->next;
	free(temp);
}

void sumList(struct node *head1, struct node *head2) {
	struct node *temp1=head1;
	struct node *temp2=head2;
	struct node *sum=NULL;
	struct node *tail;
	int carry=0;

	if(!head1)
		sum=head2;
	else if(!head2)
		sum=head1;

	while(temp1 || temp2 || carry)
	{
		struct node *new_node=new node();
		if(temp1 && temp2) {
			new_node->data=(temp1->data + temp2->data+carry)%10;
			carry=(temp1->data + temp2->data+carry)/10;
			if(sum==NULL) {
				new_node->next=NULL;
				sum=new_node;
				tail=new_node;
			}
			else {
				new_node->next=NULL;
				tail->next=new_node;
				tail=new_node;
			}
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(!temp1) {

			new_node->data=(temp2->data+carry)%10;
			carry=(temp2->data+carry)/10;
			new_node->next=NULL;
			tail->next=new_node;
			tail=new_node;
			temp2=temp2->next;
		}
		else if(!temp2) {
			new_node->data=(temp1->data+carry)%10;
			carry=(temp1->data+carry)/10;
			new_node->next=NULL;
			tail->next=new_node;
			tail=new_node;
			temp1=temp1->next;
		}
		else {
			new_node->data=carry;
			new_node->next=NULL;
			tail->next=new_node;
			tail=new_node;
		}
	}
	printLL(sum);
}

struct node *sumListEfficient(node *head1, node *head2) {

	node *result = NULL;
	node *prev= NULL;
	node *temp;
	int sum,carry=0;

	while (head1 || head2) {
		sum = carry  + (head1?head1->data:0) + (head2?head2->data:0);

		carry = (sum >= 10)?1:0;
		sum = sum%10;
		temp = newnode(sum);

		if(!result)
			result = temp;
		else
			prev->next = temp;
		prev = temp;

		if(head1)
			head1=head1->next;
		if(head2)
			head2=head2->next;
	}

	if(carry)
		prev->next = newnode(carry);

	return result;
}


/////////////////// Sum of the lists in correct representation order
int listSize(node *head) {
	if(!head)
		return 0;

	int count=0;
	node *temp = head;
	while(temp) {
		temp = temp->next;
		count++;
	}
	return count;
}

void addFront(node **head, int data) {

	node *newnode = new node();

	newnode->data = data;
	newnode->next = *head;
	*head = newnode;
}

void swapHead(node **a, node **b) {

	node *temp = *a;
	*a = *b;
	*b = temp;
}

node *sumSameSize(node *head1, node *head2, int *carry) {
	if(!head1)
		return NULL;

	node *result=new node();
	int sum=0;

	result->next = sumSameSize(head1->next,head2->next,carry);

	sum = head1->data + head2->data + *carry;
	*carry = sum/10;
	sum = sum % 10;

	result->data = sum;
	return result;
}

void addCarryToRemainingList(node *head, node *curr, int *carry, node **result) {
	int sum;

	if(head != curr) {
		addCarryToRemainingList(head->next, curr,carry,result);
		sum = head->data + *carry;
		*carry = sum/10;
		sum = sum % 10;
		addFront(result,sum);
	}
}

//Sum of the lists with correct order
node *sumLLOpt(node *head1, node *head2) {
	if(!head1)
		return head2;
	if(!head2)
		return head1;

	node *result = NULL;
	int carry=0;
	int s1 = listSize(head1);
	int s2 = listSize(head2);

	if(s1 == s2)
		result = sumSameSize(head1,head2,&carry);
	else {

		int diff = abs(s1-s2);

		if(s1<s2)
			swapHead(&head1,&head2);

		node *curr = head1;
		while (diff--) {
			curr = curr->next;
		}

		result = sumSameSize(curr,head2,&carry);

		addCarryToRemainingList(head1,curr,&carry,&result);
	}

	if(carry)
		addFront(&result,carry);

	return result;
}

/////////////////// Sum of the lists in correct representation order -------END

void deletehead(struct node **head) {
	struct node *temp;

	temp=(*head)->next;
	delete *head;
	*head=temp;

	//printLL(head);
}

void deleteNode(struct node *head, struct node *del) {
	if(!head || !del)
		return;

	if(head == del) {

		if(head->next == NULL) {
			//head = NULL; //list can't be made empty
			return;
		}

		node *temp = head->next;
		head->data  = head->next->data;
		head->next = head->next->next;

		delete head->next;
	}
	else {
		node *prev = head;
		while(prev->next && prev->next != del) {
			prev = prev->next;
		}

		if(prev->next == NULL)
			return;
		else {
			prev->next = prev->next->next;
		}

		delete del;
	}
}

void circularListStart(struct node *head) {
	struct node *slow=head;
	struct node *fast=head;

	slow=slow->next;
	fast=fast->next->next;

	while(slow!=fast)
	{
		if(!fast) {
			cout<< " not a circular list "<<endl;
			return;
		}
		slow=slow->next;
		fast=fast->next->next;
	}

	fast=head;
	while(slow!=fast) {
		fast=fast->next;
		slow=slow->next;
	}

	cout<< "start of CLL is : "<<fast->data<<endl;

}

void printMiddle(struct node *head) {
	struct node *fast = head;
	struct node *slow = head;

	if(head!=NULL)
	{
		while(fast && fast->next)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		cout<<"middle is :"<<slow->data<<endl;
	}
}

void deleteLL(struct node **head) {
	struct node *current=*head;
	struct node *next;

	while(current)
	{
		next=current->next;
		delete current;
		current=next;
	}
	*head=NULL;
}

void reverseLL(struct node **head) {
	if(!(*head))
		return;
	if(!(*head)->next)
		return;

	struct node *current=*head;
	struct node *next;//=current->next;
	struct node *prev=NULL;

	while(current)
	{
		next=current->next;
		current->next=prev;//->next=current;
		prev=current;
		current=next;
	}
	*head=prev;
}

void reverseLLRecur(struct node **head) {
	if(!(*head))
		return;
	struct node *first=*head;
	struct node *rest=(*head)->next;

	if(!rest)
		return;

	reverseLLRecur(&rest);
	first->next->next=first;
	first->next=NULL;
	*head=rest;
}

bool isLoopinLL(struct node *head) {
	struct node *fast=head;
	struct node *slow=head;
	if(!head)
		return false;

	while(fast && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow) {
			return true;
		}
	}
	return false;
}

bool compareLLs(struct node *head1, struct node *head2) {

	struct node* temp1=head1;
	struct node* temp2=head2;

	if(!temp1 && !temp2)
		return 1;

	while(temp1 && temp2)
	{
		if(temp1->data == temp2->data) {
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else
			return 0;
	}
	if(!temp1 && !temp2)
			return 1;
	return 0;
}

bool isPanlindrome(struct node *head) {
	struct node *fast = head;
	struct node *slow = head;
	struct node *prev_to_slow=NULL;
	struct node *midnode=NULL,*second_half;
	bool isP;

	if(head!=NULL) {
		while(fast && fast->next) {
			fast=fast->next->next;
			prev_to_slow=slow;
			slow=slow->next;
		}
	}

	prev_to_slow->next=NULL;
	if(fast) {
		midnode=slow;
		slow=slow->next;
	}

	second_half=slow;
	reverseLL(&second_half);
	isP=compareLLs(head,second_half);
	reverseLL(&second_half);

	if(fast) {
		prev_to_slow->next=midnode;
		midnode->next=second_half;
	}
	prev_to_slow->next=second_half;
	return isP;
}

bool isPalinUtil(struct node **left, struct node *right) {
	if(!right)
		return true;

	bool isP=isPalinUtil(left,right->next);
	if(isP==false)
		return false;

	bool isP1=((*left)->data == right->data);

	*left=(*left)->next;

	return isP1;
}

bool isPanlindromeRecur(struct node *head) {
	return isPalinUtil(&head,head);
}

Node *copyarbitLL(Node *head) {
	if(!head)
		return NULL;

	Node *copy = NULL;
	Node *copy_head = NULL;
	Node *temp = head;

	//make a list like 1-1-2-2-3-3-4-4-5-5
	while(temp) {
		Node *newnode = new Node();
		newnode->data = temp->data;
		newnode->arbit = NULL;
		newnode->next = temp->next;
		temp->next = newnode;
		temp = temp->next->next;
	}

	temp = head;
	copy_head = temp->next;

	//create arbit links
	while(temp) {
		temp->next->arbit = temp->arbit;
		temp = temp->next;
	}

	temp = head;
	copy = head->next;

	//separate original and copy list
	while(temp) {
		temp->next = temp->next->next;
		temp = temp->next;
		if(copy->next) {
			copy->next = copy->next->next;
			copy = copy->next->next;
		}
	}

	return copy_head;
}

void printReverseRecur(struct node *head) {
	if(!head)
		return;

	printReverseRecur(head->next);

	cout<< head->data<<"->";
}

void reverseDLL(struct nodeDLL **head) {
	struct nodeDLL *current=*head;
	struct nodeDLL *prev=NULL;


	while(current) {
		prev=current->prev;
		current->prev=current->next;
		current->next=prev;
		current=current->prev;
	}

	/* Before changing head, check for the cases like empty list and list with only one node */
	if(prev)
	*head=prev->prev;

/*
		struct nodeDLL *next;

	 	while(current) {
	    next = current->next;
		current->next=current->prev;
		current->prev=next;
		prev = current;
		current=next;
	}

	if(prev)
	*head=prev;
*/

}

void DivideCircularLL(node *head) {
	if(!head || head->next==head)
		return;

	node *fast=head;
	node *slow=head;
	node *head2=NULL;

	while(fast->next!=head && fast->next->next!=head) {
		fast=fast->next->next;
		slow=slow->next;
	}

	if(fast->next->next==head)
		fast=fast->next;

	head2=slow->next;
	fast->next=slow->next;
	slow->next=head;
	printCLL(head2);
	printCLL(head);
}

void moveLasttoHead(node** head) {
	if(!head)
		return;
	node* temp=*head;
	node* prev_to_temp=NULL;

	while(temp->next) {
		prev_to_temp=temp;
		temp=temp->next;
	}

	temp->next=*head;
	prev_to_temp->next=NULL;
	*head=temp;

	printLL(*head);
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void pairSwap(node* head) {
	node* temp=head;

	while(temp && temp->next) {
		swap(&temp->data, &temp->next->data);
		temp=temp->next->next;
	}
}

void pairSwapRecur(node *head) {

	if(head && head->next) {
		swap(&head->data, &head->next->data);
		pairSwapRecur(head->next->next);
	}
}


void deleteNodeDLLValueGiven(nodeDLL **head,int value)
{
	if(!*head)
		return;

	nodeDLL* temp=*head;

	while(temp) {
		if(temp->data==value) {
			if(temp==*head) {					//head node
				if (temp->next)
					(*head)->next->prev=NULL;
				temp=(*head)->next;
				delete *head;
				*head=temp;
				break;
			}
			if(temp->next) {					//in-between
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
			}
			else								//last node
				temp->prev->next=NULL;
			delete temp;
			break;
		}
		temp=temp->next;
	}
}

void deleteNodeDLL(nodeDLL **head,nodeDLL *del)
{
	if(!(*head) || !del)
		return;

	if(del==*head)
		*head=(*head)->next;

	if(del->next)
		del->next->prev=del->prev;

	if(del->prev)
		del->prev->next=del->next;

	delete del;
}

node* intersectSortedLL(node *head1,node *head2) {
	node *result=NULL;
	node** last=&result;

	while(head1 && head2) {
		if(head1->data == head2->data) {
			createLL(last,head1->data);
			last=&((*last)->next);
			head1=head1->next;
			head2=head2->next;
		}
		else if(head1->data < head2->data) {
			head1=head1->next;
		}
		else
			head2=head2->next;
	}
	return result;
}

struct node *sortedIntersectRecur(struct node *a, struct node *b)
{
    if (a == NULL || b == NULL)
        return NULL;

    if (a->data < b->data)
        return sortedIntersectRecur(a->next, b);

    if (a->data > b->data)
        return sortedIntersectRecur(a, b->next);

    struct node *temp = new node();
    temp->data = a->data;

    temp->next = sortedIntersectRecur(a->next, b->next);
    return temp;
}

void deleteAlternate(node *head) {
	if(!head)
		return;
	node* temp=head;
	node* next=NULL;

	while(temp && temp->next) {
		next=temp->next;
		temp->next=temp->next->next;
		temp=next->next;
		delete next;
	}
}

void deleteAlternateRecur(node *head) {
	if(!head)
		return;
	node* next=head->next;

	if(!next)
		return;

	head->next=next->next;
	delete next;

	deleteAlternateRecur(head->next);
}

void splitAlternate(node *head) {
	if(!head)
		return;
	node* temp1=head;

	if(!(head->next))
		return;
	node* temp2=head->next;
	node* head2=head->next;

	while(temp1 && temp2) {
		temp1->next=temp2->next;
		temp1=temp1->next;
		if(temp1) {
		temp2->next=temp2->next->next;
		temp2=temp2->next;
		}
	}

	printLL(head);
	printLL(head2);
}

void splitAlternateRecur(node *head,node* next) {
	if(!head)
		return;

	if(!next)
		return;

	head->next=next->next;
	head=head->next;

	if(head) {
		next->next=head->next;
		next=next->next;
		splitAlternateRecur(head,next);
	}
}

node* SortMerge(node *head1, node* head2) {
	node *temp=NULL;
	if(!head1)
		return head2;
	else if(!head2)
		return head1;

	if(head1->data <= head2->data) {
		temp=head1;
		temp->next=SortMerge(head1->next,head2);
	}
	else {
		temp=head2;
		temp->next=SortMerge(head1,head2->next);
	}

	return temp;
}

void SplitLL(node* head, node** front, node** back) {
	node* fast;
	node* slow;

	if(!head || !(head->next)) {
		*front=head;
		*back=NULL;
	}
	else {
		slow=head;
		fast=head->next;

		while(fast) {
			fast=fast->next;
			if(fast) {
				fast=fast->next;
				slow=slow->next;
			}
		}

		*front=head;
		*back=slow->next;
		slow->next=NULL;
	}
}

void MergeSort(node** headRef) {

	node* head=*headRef;
	node* front=NULL;
	node* back=NULL;

	if(!head || !(head->next))
		return;

	SplitLL(head,&front,&back);

	MergeSort(&front);
	MergeSort(&back);

	*headRef=SortMerge(front,back);
}

node *reverseLLinKSet(node *head, int k) {

	node *current = head;
	node *prev = NULL;
	node *next = NULL;
	int n=k;

	while (current && n >0) {
		next = current->next;
		current->next= prev;
		prev = current;
		current = next;
		n--;

	}

	if(current) {
		head->next = reverseLLinKSet(current,k);
	}
	return prev;
}

//Delete nodes which have a greater value on right side
void deleteLesserRightSideUtil(node *head) {

	node *current = head->next;
	node *prev = head;
	int max = head->data;

	while (current) {
		if(current->data < max) {
			prev->next = current->next;
			delete current;
			current = prev->next;
		}
		else {
			max = current->data;
			prev = current;
			current = current->next;
		}
	}
}

void deleteLesserRightSide(node **head) {
	if(!(*head) || !(*head)->next)
		return;

	reverseLL(head);
	deleteLesserRightSideUtil(*head);
	reverseLL(head);
}


void separateEvenOdd(node **head) {
	if(!(*head))
		return;

	node *prev = NULL;
	node *temp = *head;
	node *end =  *head;

	while(end->next) {
		end =end->next;
	}

	node *new_end = end;

	//remove all the odd numbers from the start
	while((temp->data)%2 != 0 && temp!=end) {
		new_end->next = temp;
		temp = temp->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}

	//update head and shuffle even/odds.
	if(temp->data % 2 == 0) {
		*head = temp;
		while(temp != end) {
			if(temp->data % 2 ==0) {
				prev = temp;
				temp = temp->next;
			}

			if((temp->data)%2 != 0) {
				prev->next = temp->next;
				temp->next = NULL;
				new_end->next = temp;
				new_end = temp;
				temp = prev->next;
			}
		}
	}
	else
		prev = temp;

	//if end is having odd value, move it to last
	if(end!=new_end && end->data%2!=0) {
		prev->next = end->next;
		new_end->next = end;
		end->next = NULL;
		new_end = end;
	}
	return;

}

void sortedInsert(node **head, int data) {

	node *nnode = newnode(data);

	if(*head == NULL || data <= (*head)->data) {
		nnode->next = *head;
		*head = nnode;
	}
	else {
		node *temp = *head;
		while (temp->next  && temp->next->data < data) {
			temp = temp->next;
		}
		nnode->next = temp->next;
		temp->next = nnode;
	}
}


struct efficientDLL {
	int data;
	efficientDLL *npx;
};

efficientDLL *XOR(efficientDLL *a, efficientDLL *b) {
	return (efficientDLL *)((unsigned long)a ^ (unsigned long)b);
}


void insertEfficientDLL(efficientDLL **head, int data) {

	struct efficientDLL *newnode = (struct efficientDLL *)malloc(sizeof(struct efficientDLL));
	newnode->data = data;

	newnode->npx = XOR(*head,NULL);

	if(*head) {
		efficientDLL *next = XOR((*head)->npx,NULL);
		(*head)->npx = XOR(newnode,next);
	}
	*head = newnode;
}


void printEfficientDLL (efficientDLL *head) {
	if(!head)
		return;
	else {
		efficientDLL *curr = head;
		efficientDLL *prev = NULL;
		efficientDLL *next;


		while(curr) {
			cout << curr->data<< " ";
			next  = XOR(curr->npx,prev);
			prev = curr;
			curr = next;
		}
	}
}


//SortedLL to BST
struct tree {
	int data;
	tree *left;
	tree *right;
};

tree *newTree(int data) {
	tree *newnode = new tree();

	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

int countLL(node *head) {	//listSize function is available in this file for this...
	if(!head)
		return 0;

	int count=0;

	while(head) {
		count++;
		head = head->next;
	}

	return count;
}

struct tree *sortedLLtoBST(node **head) {			//O(n) approach
	int n = countLL(*head);

	return sortedLLtoBSTRecur(head,n);
}

struct tree *sortedLLtoBSTRecur(node **head, int n) {
	if(n<=0)
		return NULL;

	struct tree *left = sortedLLtoBSTRecur(head,n/2);

	struct tree *root = newTree((*head)->data);
	root->left = left;

	*head = (*head)->next;
	root->right = sortedLLtoBSTRecur(head,n-n/2-1);

	return root;
}

void inorder(tree *root) {
	if(!root)
		return;
	else {
		inorder(root->left);
		cout<< root->data <<" ";
		inorder(root->right);
	}
}

void sort012(node *head) {
	if(!head)
		return;

	int count[3]={0};

	node *temp = head;

	while(temp) {
		count[temp->data] +=1;
		temp = temp->next;
	}


	temp = head;
	int i=0;
	while(temp) {
		if(count[i]==0)
			i++;
		else {
			temp->data = i;
			count[i]--;
			temp = temp->next;
		}
	}
}

void KthSwapUtil(node **left, node **left_prev, node *right, node *right_prev, int k) {
	static int count = 1;
	if(!right)
		return;


	KthSwapUtil(left,left_prev, right->next, right, k);

	if(count == k) {
		(*left_prev)->next = right;
		node *temp = right->next;
		right->next = (*left)->next;
		right_prev->next = *left;
		(*left)->next = temp;
		count++;
		return;
	}

	if(count < k) {
		*left_prev = *left;
		*left = (*left)->next;
		count++;
	}
}

void KthSwap(node *head, int k) {
	if(!head)
		return;

	KthSwapUtil(&head,NULL,head,NULL,k);

}


struct node *intersectUtil(int diff, struct node *head1, struct node *head2) {

    while(diff--) {
        head1 = head1->next;
    }

    while(head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }

    if(!head1)
        return NULL;

    return head1;
}

struct node *intersectPoint(node *head1, node *head2) {
    if(!head1 || !head2)
        return NULL;

    int s1 = listSize(head1);
    int s2 = listSize(head2);

    if(s1 == s2) {
        return intersectUtil(0, head1, head2);
    }
    else {
        int diff = s1 - s2;
        if(s1 > s2)
            return intersectUtil(diff, head1,head2);
        else
            return intersectUtil(-diff,head2,head1);
    }
}


void returnHeads(node *head) {
	vector<node*> result;
	if(!head)
		return;

	//reverseLL(&head);
	result.push_back(head);
	while(head->next) {
		if(head->data > head->next->data) {
			result.push_back(head->next);
		}
		head = head->next;
	}

	vector<node*>::iterator i;

	for(i=result.begin();i!=result.end();i++) {
		cout <<(*i)->data<< " ";
	}
	cout<<endl;
	//return result;
}


int main()
{
/*	struct node *head = NULL;
	createLL(&head,4);
	//createLL(&head,9);
	createLL(&head,3);
	createLL(&head,6);
	createLL(&head,5);
	createLL(&head,2);
	createLL(&head,1);
*/
/*	//KthSwap
	printLL(head);
	KthSwap(head,5);
	printLL(head);
*/

	//returnHeads
//	printLL(head);
//	returnHeads(head);


/*	//deleteNode
	printLL(head);
	deleteNode(head, head);
	printLL(head);
*/

/*	//sortedLLtoBST
	tree *root=NULL;
	root = sortedLLtoBST(&head);
	inorder(root);
*/

/*	//sort012
	printLL(head);
	sort012(head);
	printLL(head);
*/

/*	//sortedInsert
	sortedInsert(&head,3);
	sortedInsert(&head,5);
	sortedInsert(&head,1);
	sortedInsert(&head,1);
	printLL(head);
*/

/*	//efficientDLL
	struct efficientDLL *head = NULL;
	insertEfficientDLL(&head,1);
	insertEfficientDLL(&head,15);
	insertEfficientDLL(&head,12);
	insertEfficientDLL(&head,2);
	insertEfficientDLL(&head,8);
	printEfficientDLL(head);
*/

/*	printLL(head);
	head->next->next->next->next->next=head->next->next->next;
	cout<<"is Loop "<<isLoopinLL(head)<<endl;
*/
//	removeDupWOBuffer(head);
//	printLL(head);
//	moveLasttoHead(&head);
//	pairSwapRecur(head);
//	printLL(head);
//	DivideCircularLL(head);

/*	struct nodeDLL *head = NULL;
	createDLL(&head,6);
	createDLL(&head,4);
	createDLL(&head,5);
	createDLL(&head,5);
	createDLL(&head,3);
	createDLL(&head,4);
	createDLL(&head,9);
	createDLL(&head,8);

	printDLL(head);

	deleteNodeDLL(&head,head->next->next);
	printDLL(head);
	deleteNodeDLL(&head,head);
	printDLL(head);
*/

/*	//arbit LL
 	 struct Node *Head = NULL;
	createNodeLL(&Head,8);
	createNodeLL(&Head,4);
	createNodeLL(&Head,3);
	createNodeLL(&Head,5);
	createNodeLL(&Head,3);
	createNodeLL(&Head,4);
	createNodeLL(&Head,8);

    Head->arbit=Head->next->next;
    Head->next->arbit=Head;
    Head->next->next->arbit=Head->next->next->next->next;
    Head->next->next->next->arbit=Head->next->next;
    Head->next->next->next->next->arbit=Head->next;
*/
//	struct Node *copy=copyarbitLL(Head);
//	printNodeLL(copy);
//	head->next->next->next->next->next->next->next=head->next->next->next;
//	int n,i,x;

	//for sortedIntersectLL
	node *head1=NULL,*head2=NULL,*result=NULL;
	int i,x,y;
	cout<<"enter the no. of nodes to enter "<<endl;
	cin >> i;
	for(int j=0;j<i;j++) {
		cout<<"enter the data of node "<<endl;
		cin >> x;
		createLL(&head1,x);
	}
	printLL(head1);

	cout<<"enter the no. of nodes to enter 2 "<<endl;
	cin >> i;
	for(int j=0;j<i;j++) {
		cout<<"enter the data of node 2 "<<endl;
		cin >> x;
		createLL(&head2,x);
	}
	printLL(head2);

	//result = sumList(head1,head2);
	//result = sumListEfficient(head1,head2);
	result = sumLLOpt(head1,head2);
//	result=sortedIntersectRecur(head1,head2);
	printLL(result);
//	result=SortMerge(head1,head2);
//	printLL(result);


/*	//for deleteAlternate
	printLL(head);
	deleteAlternateRecur(head);
	printLL(head);
*/

/*	printLL(head);
	node *next=head->next;
	splitAlternateRecur(head,next);

	printLL(head);
	printLL(next);
*/

/*	//reverseLLinKSet
	printLL(head);
	head = reverseLLinKSet(head,3);
	printLL(head);
*/

/*	//deleteLesserRightSide
	printLL(head);
	deleteLesserRightSide(&head);
	printLL(head);
*/

/*	//separateEvenOdd
	printLL(head);
	separateEvenOdd(&head);
	printLL(head);
*/

//	printLL(head);
//	MergeSort(&head);

//	printLL(head);

/*	//intersectPoint
	struct node *head1 = NULL;
	createLL(&head1,3);
	createLL(&head1,4);
	createLL(&head1,6);
	createLL(&head1,8);
	createLL(&head1,2);
	createLL(&head1,7);

	struct node *head2 = NULL;
	createLL(&head2,2);
	createLL(&head2,7);
	head2->next->next = head1->next->next->next->next;

	printLL(head1);
	printLL(head2);

	struct node *result;
	result = intersectPoint(head1,head2);
	printLL(result);
*/

	return 0;
}

