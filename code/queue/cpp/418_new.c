/*******************************************************************************
*
* FileName : LinkQueueTest.cpp
* Comment  : test the LinkQueue structure
* Version  : 1.0
* Author   : kailiu2013@gmail.com
* Date     : 2014/05/14
*
*******************************************************************************/
#include <iostream>
#include "LinkQueue.h"

int main()
{
	LinkQueue<int> queue;
	for(int i=0;i<10;i++)
		queue.En_queue(i);
	queue.Print();

	queue.De_queue();
	cout<<"size:"<<queue.Size()<<endl;
	queue.De_queue();
	cout<<"size:"<<queue.Size()<<endl;

	queue.Print();
	return 0;
}

