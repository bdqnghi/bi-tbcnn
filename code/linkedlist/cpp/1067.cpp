#include "linkedlist.h"

linkedlist::linkedlist(){
	head -> song = "head (contains no song data)";
    head -> artist = "head (contains no artist data)";
    head -> next = NULL;
    listLength = 0;
}

bool linkedlist::insertNode(node * newnode,int position){
	if((position <= 0) ||(position > listLength+1))
	{
		cout << "nError:the given number is out of range"<<endl;
		return false;
	}
	if(head->next == NULL)
	{
		head->next = newnode;
		listLength++;
		return true;
	}
	int count = 0;
	node *p = head;
	node *q = head;
	while(q)
	{
		if (count == position)
		{
			p->next = newnode;
			newnode->next = q;
			listLength++;
			return true;
		}
		p=q;
		q=p->next;
		count++;
	}
	if (count == position)
	{
		p->next = newnode;
		newnode->next = q;
		listLength++;
		return true;
	}
	cout << "nError:node was not added to list"<<endl;
	return false;
}

bool linkedlist::removeNode(int position){
	node *p = head;
	node *q = head;
 	if ((position <= 0) || (position > listLength + 1))
    {
        cout << "nError: the given position is out of range.n"<<endl;
        return false;
    }
    if (head -> next == NULL)
    {
       cout << "nError: there is nothing to remove.n"<<endl;
       return false;
    }
    int count=0;
    while(q)
    {
    	if (count == position)
    	{
    		p->next = q->next;
    		delete q;
    		listLength --;
    		return true;
    	}
    	p=q;
    	q=p->next;
    	count++;
    }
    cout << "" <<endl;
    return false;
}

void linkedlist::printList()
{
	node * p = head;
    node * q = head;
    cout << "n---------------------------n"<<endl;
    cout << "Song Playlist n"<<endl;
    int count = 0;
    while (q)
    {
        p = q;
        cout << "n-----------------------------n"<<endl;
        cout << "t position: " <<count << endl;
        cout << "t song: " << p -> song << endl;
        cout << "t artist: " << p -> artist << endl;
        q = p -> next;
        count++;
    }
}

linkedlist::~linkedlist()
{
	node *p=head;
	node *q=head;
	while(q)
	{
		p=q;
		q=p->next;
		if(q){	
			delete p;
		}
	}
}