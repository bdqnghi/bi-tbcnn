//======================================================================
//             QUEUE.CPP
//
// DESCRIPTION: This file contains the Queue data structure library
//
// AUTHOR: DENSO INTERNATIONAL AMERICA, INC.
//         LA Laboratories
//         Bassam Masri
//
//
// VERSION: This is a preliminary version being provided to the VSCC
//          for information purposes.  DENSO reserves the right to 
//          make changes without prior approval from the VSCC.
//
//======================================================================
//#include "stdafx.h"
#include "Global.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

/* Crictical sections */
//pthread_mutex_t rx_pkt_queue_section;    //Linux
QMutex g_pkt_queue_mutex;

/* Queue definition */

struct QueueRecord
{
    uint16_t Capacity;
    uint16_t Front;
    uint16_t Rear;
    uint16_t Size;
    ElementType *Array;
};

//======================================================
// Create Queue - Pass number of elements
//======================================================
Queue CreateQueue (int MaxElements)
{
    Queue Q;

    Q = (QueueRecord *) malloc (sizeof(struct QueueRecord));
    if( Q == NULL )
        perror( "Out of space!!!" );

    Q->Array = (ElementType *) malloc (sizeof(ElementType) * MaxElements);
    if( Q->Array == NULL )
        perror( "Out of space!!!" );
    Q->Capacity = MaxElements;
    MakeEmpty( Q );

    return Q;
}

//======================================================
// Empty the Queue
//======================================================
void MakeEmpty (Queue Q)
{
    Q->Size  = 0;
    Q->Front = 1;
    Q->Rear  = 0;
}

//======================================================
// Free Queue Memory
//======================================================
void DisposeQueue (Queue Q)
{
    if (Q != NULL)
    {
        free (Q->Array);
        free (Q);
    }
}

//======================================================
// Check if the Queue is empty
//======================================================
int IsEmpty (Queue Q)
{
    return Q->Size == 0;
}

//======================================================
// Check if the Queue is Full
//======================================================
int IsFull (Queue Q)
{
    return Q->Size == Q->Capacity;
}

static int Succ (int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

//======================================================
// Add element to the Queue
//======================================================
void Enqueue (ElementType X, Queue Q)
{

    if (Q)
    {
        g_pkt_queue_mutex.lock();
        if (IsFull (Q))
            perror("Full queue");
        else
        {
            Q->Size++;
            Q->Rear = Succ (Q->Rear, Q);
            Q->Array[Q->Rear] = X;
        }
        g_pkt_queue_mutex.unlock();
    }
}


//======================================================
// Retrieve the first element in the Queue without removing it
//======================================================
ElementType Front (Queue Q)
{
    ElementType X = {0, ""};

    if (!IsEmpty(Q))
        return Q->Array[Q->Front];
    
    perror ("Empty queue");

    return X;  /* Return value used to avoid warning */
}

//======================================================
// Remove the first element in the Queue
//======================================================
void Dequeue (Queue Q)
{
    if (Q)
    {
        g_pkt_queue_mutex.lock();
        if (IsEmpty(Q))
            perror ("Empty queue");
        else
        {
            Q->Size--;
            Q->Front = Succ (Q->Front, Q);
        }
        g_pkt_queue_mutex.unlock();
    }
}

//======================================================
// Retrieve the first element and remove it from the queue
//======================================================
ElementType FrontAndDequeue (Queue Q)
{
    ElementType X = {0, ""};

    if (Q)
    {
        g_pkt_queue_mutex.lock();
        if (IsEmpty (Q))
            perror("Empty queue");
        else
        {
            Q->Size--;
            X = Q->Array[Q->Front];
            Q->Front = Succ (Q->Front, Q);
        }
        g_pkt_queue_mutex.unlock();
    }

    return X;
}
