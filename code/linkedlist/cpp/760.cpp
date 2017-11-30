/*
 *  BermudaOS - Linked List class
 *  Copyright (C) 2012   Michel Megens
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <bermuda.h>
#include <lib/list/linkedlist.h>

template <class T>
LinkedList<T>::LinkedList()
{
        this->list = NULL;
}

template <class T>
void LinkedList<T>::add(T *data)
{
       if(this->list == NULL)
               this->list = new LinkedListNode<T>(data);
       else
       {
               LinkedListNode<T> *carriage = this->list;
               for(; carriage != NULL; carriage = carriage->next());
       }
}

template <class T>
LinkedListNode<T>::LinkedListNode(T data)
{
        this->data = data;
        this->next = NULL;
}

template <class T>
LinkedListNode<T> *LinkedListNode<T>::GetNext()
{
        return this->next;
}
