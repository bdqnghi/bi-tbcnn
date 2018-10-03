#include <iostream>
#include "Queue.h"

using namespace std;

// ====================================================================
// Queue data structure test code
int main()
{
    Queue *pQueue = QueueCreate();

    QueueEnqueue(pQueue, "Ali");
    QueueEnqueue(pQueue, "Veli");
    QueueEnqueue(pQueue, "Hasan");
    QueueEnqueue(pQueue, "Cemil");

    const char *str;

    str = (const char *) QueuePeek(pQueue);
    cout << "peeked: " << str << endl;
    cout << "Queue size: " << QueueGetSize(pQueue) << endl;

    while ((str = (const char *) QueueDequeue(pQueue)) != NULL)
    {
        cout << str << endl;
    }

    QueueDestroy(pQueue);

    return 0;
}
