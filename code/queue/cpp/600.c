// =====================================================================================
// 
//       Filename:  Queue.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  09/24/2010 10:51:03 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  YOUR NAME (), 
//        Company:  
// 
// =====================================================================================

#include	<iostream>
#include	"Queue.h"
using namespace std;

int main()
{
    Queue<int> q;
    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(7);
    q.enQueue(8);
    cout << q.deQueue() << endl;
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    q.enQueue(9);
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    return 0;
}
