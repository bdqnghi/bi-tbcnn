#include<iostream>
using namespace std;


//This is the node class for the linked list
class Node{
public:
	Node(){
	next = 0;
	info = 0;	
	}
	Node(int info = 0,Node* n = 0){
	Node::next = n;
	Node::info = info;
	}

int info;
Node* next;
};

class List{
public:
	List(){
	head = tail = 0;
	}

	void addtoHead(int value){
		if(head == 0){
			head = new Node(value);
			head->next = 0;
			tail = head;
		}else{
			Node* temp = new Node(value,head);
			head = temp;
		}	
	}

	void addtoTail(int value){
		if(tail == 0){
			tail = new Node(value);
			tail->next = 0;
			head = tail;
		}else{
			Node* temp = new Node(value);
			tail->next = temp;
			tail = temp;			
		}
	}

	bool lookUp(int value){
		Node*temp = head;
		while(temp!= 0){
			if(temp->info == value){
				cout<<"Node does exist"<<endl;
				return true;
			}	
		temp = temp->next;
		}
		cout<<"Node does not exist"<<endl;
		return false;
	}

    void recurseReverse(){
		 rreverse(*head);
	}


    void rreverse(Node** root){
		Node* first;
		Node* rest;

		if(root == 0){
			return;
		}

		first = root;
		rest = root->next;
	
		if(rest == 0){
			return;
		}

		rreverse(&rest);

		first->next->next = first;
		first->next = 0;
		root = rest;
	}

	void removeNode(int value){
		if(lookUp(value)){
			Node* temp = head;
			if(temp->info == value){
				removeHead();
			}else{
				while(temp->next->info!= value){
				temp = temp->next;
				}
				Node* toDelete = temp->next;
				temp->next = temp->next->next;
				delete(toDelete);
			}
		}else{
			cout<<"Node does not exist in the list"<<endl;
		}
	}

	void removeHead(){
		if(head == tail){
			head = tail = 0;
			delete(head);
		}
		else{
			Node* temp = head;
			head = temp->next;
			delete temp;
		}
	}

	void removeTail(){
		if(head == tail){
			head = tail = 0;
			delete(tail);
		}else{
			Node*temp = head;
			while(temp->next != tail){
				temp = temp->next;
			}
			Node* last = temp->next;
			temp->next = 0;
			tail = temp;
			delete(last);
		}
	}

	void sort(){

	}

	void printHT(){
		cout<<"Head:"<<head->info<<endl;
		cout<<"Tail:"<<tail->info<<endl;
	}

	void sortedInsert(int value){
		Node* toAdd = new Node(value);
		if(head == 0 || head->info >= value){
			toAdd->next = head;
			head = toAdd;
		}else{
			Node* current = head;
			while(current->next!= 0 && current->next->info < value){
				current = current->next;
			}
			toAdd->next = current->next;
			current->next = toAdd;
		}
	}
	
	void printList(){
		Node*temp = head;
		while(temp!=0){
			std::cout<<temp->info<<" ";
			temp = temp->next;
		} 
	cout<<endl;
	}

	void reverseList(){
		Node* result = 0;
		Node* current = head;
		Node* next;
		while(current != 0){
			next = current->next;
			current->next = result;
			result = current;
			current = next;
		}
		head = result;
	}

Node* head;
Node* tail;

};


int main(){
List myList;
myList.addtoTail(1);
myList.addtoTail(2);
myList.addtoTail(4);
myList.printList();
myList.sortedInsert(3);
myList.printList();
myList.reverseList();
myList.printList();
myList.recurseReverse();
myList.printList();




return 0;
}
