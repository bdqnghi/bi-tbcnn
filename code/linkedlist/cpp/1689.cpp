`#include <iostream>

using namespace std;
void DesplayMenu();
void DesplayType();

enum listType { Singly = 1, Doubly = 2, Singly_Circ = 3, Doubly_Circ = 4 };

class Node
{
public:
	Node(int value) : value(value)
	{
		next = nullptr;
		prev = nullptr;
	}
	Node* get_prev()
	{
		return prev;
	}
	Node* get_next()
	{
		return next;
	}
	void set_next(Node * n)
	{
		next = n;
	}
	void set_prev(Node * n)
	{
		prev = n;
	}
	int get_value()
	{
		return value;
	}

private:
	Node * prev;
	Node * next;
	int value;
};

class LinkedList
{
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		SizeCount = 0;
		ListType = -1;
	}
	//checks if list is empty
		bool isEmpty()
	{
		return head == nullptr;
	}
	void append(Node * n) //Adds node to end of the list
	{
		if (isEmpty())
		{
			head = n;
			tail = n;
			n->set_next(nullptr);
		}
		else
		{
			if (!is_circular())
			{
				if (ListType == Doubly)
				{
					n->set_next(nullptr);
					tail->set_prev(n);
					n->set_prev(tail);
					tail = n;
				}
				else //Singly
				{
					n->set_next(nullptr);
					tail->set_next(n);
					tail = n;
				}
			}
			else
			{
				if (ListType == Doubly_Circ)
				{
					n->set_next(head);
					tail->set_next(n);
					n->set_prev(tail);
					tail = n;
					head->set_prev(tail);
				}
				else //Singly_Circ
				{
					n->set_next(head);
					tail->set_next(n);
					tail = n;
				}
			}
		}
		SizeCount++;
	}
	Node* create_node(int value)
	{
		Node* n = new Node(value);
		return n;
	}
	
	void remove_tail()
	{
		if (isEmpty())
		{
		
		}
		else {
				if (tail == head)
				{
					delete head;
					head, tail = nullptr;
				}
				else
				{
					if (!is_circular())
					{
						if (ListType == Doubly)
						{

						}
						else // Singly
						{

						}
					}
					else
					{
						if (ListType == Doubly_Circ)
						{

						}
						else // Singly_Circ
						{

						}
					}

				}
			}
	}

	void push(Node* n)
	{

	}

	Node* pop()
	{

	}

	void remove_i(int i)
	{

	}

	Node* get_i(int i)
	{

	}

	void add_i(Node* n, int i)
	{

	}

	void print()
	{
		if (isEmpty())
		{
			cout << "Empty list" << endl;
		}
		else
		{
			if (!is_circular())
			{
				Node * temp = head;
				while (temp != nullptr)
				{
					cout << temp->get_value() << endl;
					temp = temp->get_next();
				}
			}
			else
			{
				Node * temp = head;
				do
				{
					cout << temp->get_value() << endl;
					temp = temp->get_next();
				} while (temp != head);
			}
		}
	}

	void deleteX()
	{
		Node* temp = head;
		while (head != tail)
		{
		temp = head->get_next();
		delete head;
		head = temp;
		}
		delete head;
		head = nullptr;
		tail = head;
	}
	void reverse()
	{
		if (isEmpty())
		{
			return;
		}
			Node* temp = head;
			head = tail;
			tail = temp;
	}

	void rotate(int rotations)
	{
		if (isEmpty())
		{

		}
		else
		{

		}
	}

	void random_shuffle()
	{

	}

	int size()
	{
		return SizeCount;
	}

	void setListType()
	{
		DesplayType();
		int ListType = -1;
		cin >> ListType;
		this->ListType = ListType;
	}
	bool perform_operation(int op_code, int value)
	{
		switch (op_code)
		{
		case 1:
			cout << "appending node" << endl;
			append(create_node(value));
			break;
		case 2:
			cout << "removing tail" << endl;
			break;
		case 3:
			cout << "Choice 3" << endl;
			break;
		case 4:
			cout << "Choice 4" << endl;
			break;
		case 5:
			cout << "Choice 5" << endl;
			break;
		case 6:
			cout << "Getting " << endl;
			break;
		case 7:
			add_i(create_node(value), value);
			cout << "Adding node at : "<< value << endl;
			break;
		case 8:
			cout << "Printing" << endl;
			print();
			break;
		case 9:
			cout << "Deleting List" << endl;
			deleteX();
			break;
		case 10:
			cout << "Rotating" << endl;
			rotate(value);
			break;
		case 11:
			cout << "Reversing" << endl;
			reverse();
			break;
		case 12:
			cout << "Randomizing" << endl;
			random_shuffle();
			break;
		case 13:
			cout << "Size_Count is : "<< size() << endl;
			break;
		case 14:
			cout << "Reopening menu" << endl;
			DesplayMenu();
			break;
		case 0:
			cout << "Exiting" << endl;
			return 0;
			break;
		}
	}
private:
	Node * head;
	Node * tail;
	int SizeCount;
	int ListType;
	bool is_circular() {
		return ListType == Doubly_Circ || ListType == Singly_Circ;
	}

	bool is_singly() {
		return ListType == Singly || ListType == Singly_Circ;
	}
};

int main()
{
	int value = -1;
	int op_code = -1;
	LinkedList List1;
	List1.setListType();
	DesplayMenu();
	do
	{
		do
		{
			cout << "enter op_code" << endl;
			cin >> op_code;
		} while (op_code < 0 || op_code > 14);
		if (op_code == 0)
		{
			value = NULL;
			List1.perform_operation(op_code, value);
		}
		cout << "enter value" << endl;
		cin >> value;
		List1.perform_operation(op_code, value);
	} while (op_code != 0);

	system("pause");
	return 0;
}

//User Display Map
void DesplayType()
{
	cout << "____List_Type?___________OP choice____" << endl;
	cout << "|___Singly_______________#1__________|" << endl;
	cout << "|___Doubly_______________#2__________|" << endl;
	cout << "|___Singly-Circulary_____#3__________|" << endl;
	cout << "|___Doubly-Circulary_____#4__________|" << endl;
	cout << "+------------------------------------+" << endl;
}
void DesplayMenu()
{
	cout << "____Menu_________________OP choice____" << endl;
	cout << "|___Append_______________#1__________|" << endl;
	cout << "|___Remove_Tail__________#2__________|" << endl;
	cout << "|___Push_________________#3__________|" << endl;
	cout << "|___Pop__________________#4__________|" << endl;
	cout << "|___Remove_i_____________#5__________|" << endl;
	cout << "|___Get_i________________#6__________|" << endl;
	cout << "|___Add_i________________#7__________|" << endl;
	cout << "|___Print________________#8__________|" << endl;
	cout << "|___Delete_______________#9__________|" << endl;
	cout << "|___Reverse______________#10_________|" << endl;
	cout << "|___Rotate_______________#11_________|" << endl;
	cout << "|___Random_Shuffle_______#12_________|" << endl;
	cout << "|___Size_________________#13_________|" << endl;
	cout << "|___Show_Menu____________#14_________|" << endl;
	cout << "|___Quit_________________#0__________|" << endl;
	cout << "+------------------------------------+" << endl;
}
