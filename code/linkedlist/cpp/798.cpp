/* Pan Xinyuan
   xp572,
   16305
   EE312-Assignment 8

   I commited everything from the command line, which for some reason uses my personal git account,
   aifusenno1, instead of the one I created for this course.
*/

class LinkedList{
private:
    typedef struct Node {
        int value;
        Node *next;
    } Node;

    Node *head;
public:
    LinkedList() {
        head = 0;
    }
    ~LinkedList(){
    }
    void addToListAtPosition (int position, int value) {
        if (getListLength() >= position) {
            Node * newNode = new Node;
            newNode->value = value;
            newNode->next = 0;
            Node * cur = head;
            Node * pre = 0;
            while (position>0){
                pre = cur;
                cur = cur->next;
                position--;
            }
            // when we are adding to the beginning
            if (pre == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = cur;
                pre->next = newNode;
            }
        }
    }
    void addToHead (int value) {
        Node * n = new Node;
        n->value = value;
        n->next = head;
        head = n;
    }

    void appendToList (int value) {
        Node * cur = head;
        while (cur->next != 0) {
            cur = cur->next;
        }
        Node * newNode = new Node;
        newNode->value = value;
        newNode->next = 0;
        cur->next =newNode;

    }


    void removeFromListAtPosition (int position) {
        if (position < getListLength()) {
            Node * cur = head;
            Node * pre = 0;
            while (position>0){
                pre = cur;
                cur = cur->next;
                position--;

            }
            // removing the head
            if (pre == 0) {
                head = head->next;
            } else {
                pre->next = cur->next;

            }

        }
    }
    void removeFromHead() {
        if (getListLength()>0){
            head = head->next;

        }
    }
    void removeFromEnd() {
        if (getListLength()>0) {
            Node *cur = head;
            Node *pre = 0;
            while (cur->next != 0) {
                pre = cur;
                cur = cur->next;
            }
            if (pre == 0){
                head = head->next;  // supposed to be 0
            } else {
                pre->next = 0;
            }
        }
    }

    bool find (int value) {
        Node *cur = head;
        while (cur!= 0) {
            if (cur->value == value) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void reverseList() {
        Node *cur = head;
        Node *pre = 0;
        while (cur != 0) {
            Node *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        head = pre;

    }

    int getListLength() {
        int count = 0;
        Node * cur = head;
        while (cur != 0) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    Node * getHead() {
        return head;
    }


};
