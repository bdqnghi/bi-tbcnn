/*******************************************************************************
*
* FileName : queue_test.cpp
* Comment  : queue implemented in terms of single linked list
* Version  : 1.0
* Author   : haibindev.cnblogs.com
* Date     : 2007-9-21 :
*
*******************************************************************************/

#include <iostream>
#include "queue.h"

int main()
{
	Queue<int> queue;
	queue.en_queue(3);
	queue.en_queue(6);
	queue.en_queue(11);
	queue.de_queue();

	int num=queue.size();
	for (int i=0; i!=num; ++i)
		std::cout<<queue.de_queue()<<'-';
	std::cout<<std::endl;
	return 0;
}