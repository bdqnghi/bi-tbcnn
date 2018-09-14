// Implementation Of Linked List In C++

// Insertion with head as global variable

#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* link;

};

Node* head;

void Insert(int x){  // Insert at beginning of linked list

	Node* temp=new Node();
    // temp is pointer variable 
    // and I am dereferencing pointer variable
    // to access the node
	temp->data=x;
  	temp->link=head;  // If list was empty head was null so no probs
  	head=temp;


}

void Insert(int data,int n){  // Insert at position n

	Node* temp1=new Node();
	temp1->data=data;
	temp1->link=NULL;

	if(n==1){  // Insert at beginning or empty list

		temp1->link=head;
		head=temp1;

		return;

	}

	Node* temp2=head;

	for(int i=0;i<n-2;++i){

		 temp2=temp2->link;  

	}	  

	// temp2 points to n-1th node
	temp1->link=temp2->link;  // Now the new node points to nth node

	temp2->link=temp1;


}

void Print(){

	Node* temp=head;

	while(temp!=NULL){

		cout<<temp->data<<"\n";
		temp=temp->link;

	}

	cout<<"\n";


}

int main(){

	head=NULL;  // list is empty

	Insert(2,1);  // List:2
	Insert(3,2);  // List: 2,3
	Insert(4,1);  // List:4,2,3
	Insert(5,2);  // List:4,5,2,3

	Print();	
	/*

	printf("How many numbers?\n");

	int n,i,x;

	cin>>n;

	for(i=0;i<n;++i){

		cout<<"Enter the number: \n";
		cin>>x;

		Insert(x);

	}

	*/

	//Print();

}