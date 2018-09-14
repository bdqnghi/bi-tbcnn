#include <stdio.h>

#include<stdlib.h>
using namespace std;


typedef struct ll_node NODE;
struct ll_node{
    int val;
    NODE *next;
    };

NODE *create_new_list();
void insert_ind(NODE*,int,int);
void display(NODE*);
int get_at_index(int,NODE*);
int main ()
{
int choice,val,ind;
NODE *head=create_new_list();
   // This calls function from second name space.
do{
        printf("Operations menu:\n");
		printf("1. Insert a node.\n");
		printf("2. Dispaly all\n");
		printf("3. Display at Index.\n");
		printf("4. Exit.\n");
		printf("Enter your choice..: ");
		scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter value to be inserted : ");
                scanf("%d",&val);
                printf("Inserted at index: ");
                scanf("%d",&ind);
                insert_ind(head,val,ind);
                break;
        case 2: display(head);
                break;
        case 3: printf("Index : ");
                scanf("%d",&ind);
                val=get_at_index(ind,head);
                printf("value at index %d is %d",ind,val);
                break;
    }
}while(choice!=4);

   return 0;
}
NODE *create_new_list(){
NODE *ptr=NULL;
ptr=(NODE *)malloc(sizeof(NODE));
ptr->val=0;
ptr->next=NULL;
return ptr;
}
void insert_ind(NODE *head,int val,int ind){
    NODE *ptr=NULL;
    ptr=(NODE *)malloc(sizeof(NODE));
    ptr->next=NULL;
    ptr->val=val;
    while(head->next!=NULL && ind--){
        head=head->next;
        }

    head->next=ptr;
}
void display(NODE *head){
     while(head->next!=NULL){
        printf("%d",head->val);
        head=head->next;
     }
     printf("%d",head->val);
}
int get_at_index(int ind,NODE *head){
    for(;ind;ind--,head=head->next){
        if(head->next==NULL)
            return -1;
    }
    if(head==NULL)
            return -1;
    else
        return head->val;


}
