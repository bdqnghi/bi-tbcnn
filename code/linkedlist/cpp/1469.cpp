#include <iostream>

class Linked_List_With_Tail{
    private:
    struct node{
        int data;
        node* next;
    };
    node *head = NULL;
    node *tail = NULL;
    public:
    void insert_node_at_end(int value){
        node* temp_node = new node;
        temp_node->data = value;
        temp_node->next = NULL;
        if(head==NULL){
            head = temp_node;
            tail = temp_node;
        }
        else{
            tail->next = temp_node;
            tail = temp_node;
        }
    }
    void print_list(){
        node *current;
        current = head;
        while(current != NULL){
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};

class Linked_List_Without_Tail{
  private:
    struct node{
        int data;
        node* next;
    };
    node* head=NULL;
  public:
    void insert_node_at_end(int value){
        node* temp_node;
        std::cout << "0";
        temp_node->data = value;
        temp_node->next = NULL;
        std::cout << "0";
        if(head == NULL){
            head = temp_node;
        }
        else{
            node* current;
            current = head;
            std::cout << "0";
            while(current != NULL){
                current = current->next;
                std::cout << "1";
            }
            //current->next = temp_node;
        }
    }
    void print_list(){
        std::cout << "0";
        node* current;
        current = head;
        while(current != NULL){
            std::cout << current->data << std::endl;
            current = current->next;
        }
        
    }
    
};

int main()
{
    Linked_List_With_Tail myList;              //Creates my List on the stack
    myList.insert_node_at_end(3);
    myList.insert_node_at_end(5);
    myList.insert_node_at_end(26);
    myList.insert_node_at_end(50);
    myList.print_list();
    
//     Linked_List_Without_Tail newList;
//     newList.insert_node_at_end(12);
//   newList.insert_node_at_end(16);
   // newList->print_list();
    //delete newList;

    return 0;
}
