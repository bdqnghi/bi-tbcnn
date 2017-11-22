#include <cstdio>
#include <iostream>
#include <string>


using namespace std;
struct node{
    node *next;
    node *back;
    char c;
};


string large,small;

node* start;
node* last;
node* open;

void print(){
    node* cur = open;
    while(cur->next!=NULL){
        cur = cur->next;
        cout << cur->c;
    }
    cout << endl;
}



int main(){
    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);
    cin >> large >> small;
    start = new node;
    open = new node;
    last = start;
    start->c = large.at(0);
    start->back = open;
    open->next = start;


    for(int x = 1;x<large.length();x++){
        last->next = new node;
        (last->next)->back = last;
        last = last->next;
        last->c = large.at(x);
    }
    last->next = NULL;
    
    node* cur = start;
    while(cur!=NULL){
        node* tester = cur;
        bool flag = true;
        for(int x = 0;x<small.length();x++){
            if(tester==NULL||tester->c!=small.at(x)){
                flag = false;
                break;
            }
            tester = tester->next;
        }
        if(flag){
            node* ok = cur->back;
            ok->next = tester;
            if(tester!=NULL) tester-> back = ok;
            cur = ok;
            if(cur==open) cur = cur->next;

            for(int x = 0;x<small.length();x++){
                if(cur->back==open) break;
                cur = cur->back;
            }
        }
        else{
            cur = cur->next;
        }
    }
    print();


}



