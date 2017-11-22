#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

struct node {
	int data;
	node *next;

	// constructor to initialize data at the new node
	node (int x, node *t) {
		data = x;
		next = t;
	};
};

typedef node *link;

void printList(link head) {
	link temp = head;
	while(temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << '\n';
}

link createList(int n) {
	link head = new node(1, NULL);
	link x = head;
	for(int i = 2; i <= n; i++) x = (x->next = new node(i, NULL));
	return head;	
}

link makeCopy(link start) {
	link temp = start;
	link head = temp;
	link x = NULL;
	link prev = NULL;
	while(temp != NULL) {
		x = new node(temp->data, NULL);
		if (prev != NULL) prev->next = x;
		prev = x;
		temp = temp->next;
	}
	return head;
}

void traverseR(link head) {
	if (head->next != NULL) traverseR(head->next);
	cout << head->data << ' ';
}


// NULL <- 1 <- 2 <- 3
// prev 3
// curr NULL
// temp NULL
link reverseList(link head) {
	link prev = NULL;
	link curr = head;
	link after = head->next;
	link temp;

	while(curr != NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

//----------------------------------Circular List------------------------------------
// returns link to last node, so use like:
// link start = initCircularList(7)->next;
// to get link to the first node
link initCircularList(int n) {
	link circularList = new node(1, NULL);
	circularList->next = circularList;

	link x = circularList;
	for(int i = 2; i <= n; i++) x = (x->next = new node(i, circularList));
	return x;
}

void printCircularList(link start) {
	link temp = start;
	if (temp == NULL) return;
	while(temp->next != start) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << temp->data << ' ';
	cout << '\n';
}

int sizeOfCircularList(node *start) {
	link temp = start;

	int count = 1;
	while(temp->next != start) {
		count++;
		temp = temp->next;
	}
	return count;
}

// solution to the Josephus problem
// out of n members in a circle, eliminate every mth member
// last person remaining is the winner
void runJosephus(int n, int m) {

	link x = initCircularList(n);
	int i;

	while(x != x->next) {
		for(i = 1; i < m; i++) x = x->next;
		link t = x->next;
		x->next = t->next;
		cout << "Eliminating : " << t->data << '\n';
		delete t;
	}

	cout << "Winner : " << x->data << '\n';
}

int main()
{
	// test list
	link head = createList(20);
	printList(head);

	// duplicate of test list
	link head2 = makeCopy(head);
	printList(head2);

	// reverse of test list
	traverseR(head);
	cout << '\n';

	// reverse linked list
	link head3 = reverseList(head);
	printList(head3);

	// circular list
	link circleStart = initCircularList(7)->next;
	printCircularList(circleStart);
	cout << sizeOfCircularList(circleStart) << '\n';

	// prints solution to the Josephus problem
	runJosephus(10, 4);

	return 0;
}