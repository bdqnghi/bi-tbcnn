#include <cstdlib>
#include "Queue.h"

Queue *QueueCreate()
{
    Queue *pQueue = new Queue;

    pQueue->pList = ListCreate();

    return pQueue;
}

Node *QueueEnqueue(Queue *pQueue, const void *pData)
{
    return ListAppend(pQueue->pList, pData);
}

void *QueueDequeue(Queue *pQueue)
{
    return ListDeleteHead(pQueue->pList);
}

void *QueuePeek(Queue *pQueue)
{
    if (ListIsEmpty(pQueue->pList))
    {
        return NULL;
    }

    return pQueue->pList->pHead->pData;
}

int QueueGetSize(Queue *pQueue)
{
    return ListGetSize(pQueue->pList);
}

bool QueueIsEmpty(Queue *pQueue)
{
    return ListIsEmpty(pQueue->pList);
}

void QueueDestroy(Queue *pQueue)
{
    ListDestroy(pQueue->pList);
    delete pQueue;
}
