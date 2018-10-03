/*! @file	Queue.cpp
    @brief	Example of queue.
    
			Example of queue. Logic: first in - first out. Linear list.
			Firstly we take number of elements. 
			After - create queue with random values.
			After - print queue.
			After - pop (delete) all queue from memory.
    @version	0.1
    @date		30 apr 2013 22:12
*/



#include <iostream>
/*! @struct	queue
	@brief	Struct for elements of queue.
    @param val		Value of element.
	@param *next	Pointer to next element of queue.
*/
struct queue
{
	int val;
	queue *next;
} *top, *last;								/// top and last elements of queue
void add_el (int value);
void print_queue();
void pop_element();


void main()
{
	int size;
	int tmpVal;

	printf("Input number of elements: ");
	scanf("%d", &size);
	printf("\n\n...Start of creating queue...");
		while (size--)
		{
			tmpVal = rand()%10000;
			add_el(tmpVal);
		}
	printf("\n...Queue was created...\n");

	print_queue();							/// print queue
	pop_element();							/// pop queue (delete it)

	getchar();
	getchar();
}


/*! @fn		void add_el(int value)
    @brief	Add new element to queue.
    
	@param value	Value of element.
	@return			void
*/
void add_el (int value)
{
	queue *tmp = new queue;
	tmp->val = value;
	tmp->next = NULL;
		if(!top)
		{
			top = tmp;
			last = top;
		}
		else
		{
			last->next = tmp;
			last = tmp;
		}
	printf ("\n...Value \'%d\' was added", value);
}


/*! @fn		void print_queue()
    @brief	Print queue in oder.
    
	@return	void
*/
void print_queue()
{
    queue *tmp;
	tmp = top;
	printf("\n\nQueue:");
		while (tmp)
		{
			printf("|%d ", tmp->val);
			tmp = tmp->next;
		}
}


/*! @fn		void pop_element()
    @brief	Pop element (delete it).
    
	@return	void
*/
void pop_element()
{   
	queue *tmp;
		while(top)
		{
			tmp = top->next;
			delete top;
			top = tmp;
		}
	printf("\n\n...Queue was totally poped...\n");
}