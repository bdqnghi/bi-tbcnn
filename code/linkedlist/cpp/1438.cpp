#include <stdio.h>
#include <stdlib.h>

struct node
{
     int value;
     node *next;
};

int main()
{
    node *first = (node *)malloc(sizeof(node));
    first->next = 0;
    first->value = 5;
    printf("first->value: %d\n", first->value);

    first->next = (node *)malloc(sizeof(node));
    node *second = first->next;
    second->value = 10;
    printf("second->value: %d\n", second->value);
    printf("first->next->value: %d\n", first->next->value);

    first->next->next = (node *)malloc(sizeof(node));
    node *third = first->next->next;
    third->value = 20;
    printf("third->value: %d\n", third->value);
    printf("first->next->next->value: %d\n", first->next->next->value);
    
    third->next = (node *)malloc(sizeof(node));
    node *fourth = third->next;
    fourth->value = 40;
    fourth->next = NULL;
    printf("Time to remove a node.\n");

    node **pp = &first;

    int searchValue = 40;
    while(*pp && // while current pointer isn't NULL
          (*pp)->value != searchValue) 
    {
        pp = &((*pp)->next);
    }

    if(*pp == NULL)
        printf("Value not found.\n");
    else
    {
        // NOTE: *pp here refers to not the node itself, but to the either
        // the head or the "next" part of a node.
        *pp = (*pp)->next; 
    }

    pp = &first;
    while( (*pp)->next != NULL )
    {
         printf("Value: %d\n", (*pp)->value);
         pp = &(*pp)->next;
    }
    printf("Final value: %d\n", (*pp)->value);
    
    // Lets try it another way
    printf("\nLet's try it another way\n\n");

    node one;
    one.value = 5;
    node *head = &one;

    node two;
    one.next = &two;
    two.value = 10;

    printf("(*one.next).value: %d\n", (*one.next).value);

    node three;
    two.next = &three;
    three.value = 20;

    node four;
    three.next = &four;
    four.value = 40;
    four.next = NULL;

    printf("Time to remove a node.\n");
    pp = &head;
    //pp = &(&one);
    searchValue = 40;
    while(*pp && // while current pointer isn't NULL
          (*pp)->value != searchValue) 
    {
        pp = &((*pp)->next);
    }

    if(*pp == NULL)
        printf("Value not found.\n");
    else
    {
        *pp = (*pp)->next; 
    }

    pp = &head;
    while( (*pp)->next != NULL )
    {
         printf("Value: %d\n", (*pp)->value);
         pp = &(*pp)->next;
    }
    printf("Final value: %d\n", (*pp)->value);
}
