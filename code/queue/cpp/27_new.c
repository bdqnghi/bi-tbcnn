//
//  TrackingQueue.cpp
//  TrackingQueue
//
//  Created by tuhin shukla on 10/29/13.
//  Copyright (c) 2013 tuhin shukla. All rights reserved.
//

#include "TrackingQueue.h"




     template<typename T>
TrackingQueue<T>::~TrackingQueue<T>()
{
     cout<<"Max Queue Size is -->"<<max_queue_size<<"<--"<<endl;
}

     template<typename T>
TrackingQueue<T>::TrackingQueue()
{
     current_queue_size = queue<T>::size();
     max_queue_size  = current_queue_size; 
}

     template<typename T>
void TrackingQueue<T>::pop()
{
     queue<T>::pop();
     current_queue_size--; 
     if(max_queue_size < current_queue_size)
          max_queue_size = current_queue_size;


}
     template<typename T>
void TrackingQueue<T>::push(const T& element)
{

     queue<T>::push(element);

     current_queue_size++; 

     if(max_queue_size < current_queue_size)
          max_queue_size = current_queue_size;


}
