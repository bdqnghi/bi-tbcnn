#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
class Node{
public:
	int data;
	Node * next;
	Node(int d){
		data = d;
		next = NULL;
	}
};
class Solution{
public:
	Node * insert(Node *head, int data){
		Node *node = new Node(data);
		if(head == NULL){
			head = node;
		}else{
			Node *curr = head;
			while(curr->next){
				curr = curr->next;
			}
			curr -> next = new Node(data);
		}
		return head;
	}
	void display(Node * head){
		Node * start = head;
		while(start){
			cout << start-> data<<" ";
			start = start -> next;
		}
	}
};
int main(){

	Node * head = NULL;
	Solution mylist;
	int T,data;
	cin >> T;
	while(T-->0){
		cin >> data;
		head = mylist.insert(head,data);

	}
	mylist.display(head);

	return 0;
}