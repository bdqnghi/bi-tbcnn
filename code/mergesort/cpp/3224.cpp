//EDWARDS AMES PIZARRO

#include <stdio.h>
#include <stdlib.h>

struct listnode
{
    struct listnode * next;
    long key;
};

struct listnode * sort(struct listnode * a)
{
    int length = 0;
    struct listnode * current = a;
    struct listnode * temp = a;
    struct listnode * first = a;
    struct listnode * second = NULL;

    while(current!= NULL)
    {
        current = current -> next;
        length++;
    }

    if (length>1)
    {

        for(int i = 0 ; i < (length / 2) - 1 ; i++)
        {
            temp = temp -> next;
        }

        second = temp->next;
        temp->next = NULL;

        first = sort (first);
        second = sort (second);

        if (first->key > second->key)
        {
            a = second;
            second = second -> next;
        }
        else
        {
            a = first;
            first = first -> next;
        }

        struct listnode * bottom = a;

        while (first!=NULL && second!=NULL)
        {
            if (first->key > second->key)
            {
                bottom ->next = second;
                bottom = second;
                second = second -> next;
            }
            else
            {
                bottom -> next = first;
                bottom = first;
                first = first -> next;
            }
        }

        while (first!=NULL)
        {
            bottom -> next = first;
            bottom = first;
            first = first -> next;
        }

        while (second!=NULL)
        {
            bottom -> next = second;
            bottom = second;
            second = second -> next;
        }

    }
    return a;
}

int main(void)
{
   long i;
   struct listnode *node, *tmpnode, *space;
   space =  (struct listnode *) malloc( 500000*sizeof(struct listnode));
   for( i=0; i< 500000; i++ )
   {  (space + i)->key = 2*((17*i)%500000);
       (space + i)->next = space + (i+1);
   }
   (space+499999)->next = NULL;
   node = space;
   printf("\n prepared list, now starting sort\n");
   node = sort(node);
   printf("\n checking sorted list\n");
   for( i=0; i < 500000; i++)
   {  if( node == NULL )
   {  printf("List ended early\n"); exit(0);
   }
       if( node->key != 2*i )
       {  printf("Node contains wrong value\n"); exit(0);
       }
       node = node->next;
   }
   printf("Sort successful\n");
   exit(0);
}
