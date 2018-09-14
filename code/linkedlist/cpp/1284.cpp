#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node*link;
	
}*start, *ptr, *end;

void insert( int data )
{
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->link = NULL;
	if( start != NULL ){
		start->link = ptr;
	}
	else 
		end = ptr;
	
	if( end->link == NULL )
		end->link = ptr;
	start = ptr;
}

void del()
{
	end = end->link;
}

int main()
{
	ptr = start = end = NULL;
	
	int n, a[10];
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
		insert(a[i]);
	}
	del();
	insert(6);
	while( end != NULL ){
		cout << end->data << " " ;
		end = end->link;
	}
}
