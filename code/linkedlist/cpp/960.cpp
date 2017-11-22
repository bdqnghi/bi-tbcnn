#include "linkedlist.h"

Cell::Cell(int item)
{
    element = item;
    next = 0;
}

LinkedList::LinkedList()
{
    sizeList = 0;
    curr = 0;
    head = 0;
}

void LinkedList::clear()
{
    int i;
    curr = 0;
    Cell * current;
    Cell * aux;
    for(i = 0 ; i < sizeList ; ++i)
    {
        current = head;
        while(current->next != 0)
        {
            if(current->next->next == 0)
                aux = current;
            current = current->next;
        }
        aux->next = 0;
        delete current;
    }
    head = 0;
    sizeList = 0;
}

void LinkedList::insert(int item)
{
    int i;
    ++sizeList;
    Cell * newCell = new Cell(item);
    if(head == 0)
        head = newCell;
    else if(curr == 0)
    {
        Cell * aux = head;
        head = newCell;
        head->next = aux;
    }
    else
    {
        Cell * current = head;
        for(i = 0 ; i < curr - 1 ; ++i)
            current = current->next;
        newCell->next = current->next;
        current->next = newCell;
    }
}

void LinkedList::append(int item)
{
    ++sizeList;
    Cell * newCell = new Cell(item);
    if(head == NULL)
        head = newCell;
    else
    {
        Cell * current = head;
        while(current->next != 0)
            current = current->next;
        current->next = newCell;
    }
}

int LinkedList::remove()
{
    int i;
    int value;
    if(sizeList == 0)
        return 0;
    else
    {
        --sizeList;
        Cell * current = head;
        Cell * aux;
        if(curr == 0)
        {
            value = head->element;
            head = head->next;
            delete current;
        }
        else
        {
            for(i = 0 ; i < curr - 1 ; ++i)
                current = current->next;
            aux = current->next;
            current->next = aux->next;
            value = aux->element;
            delete aux;
        }
        return value;
    }
}

void LinkedList::moveToStart()
{
    curr = 0;
}

void LinkedList::moveToEnd()
{
    curr = sizeList - 1;
}

void LinkedList::prev()
{
    if(curr > 0) --curr;
}

void LinkedList::next()
{
    if(curr < sizeList - 1)
        ++curr;
}

int LinkedList::length()
{
    return sizeList;
}

int LinkedList::currPos()
{
    return curr;
}

void LinkedList::moveToPos(int pos)
{
    if(pos > sizeList - 1)
        curr = sizeList - 1;
    else if(pos < 0)
        curr = 0;
    else
        curr = pos;
}

int LinkedList::getValue()
{
    int i;
    Cell * current = head;
    if(head == 0)
        return 0;
    for(i = 0 ; i < curr ; ++i)
        current = current->next;
    return current->element;
}
