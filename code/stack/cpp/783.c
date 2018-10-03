#include <iostream>
using namespace std;
union u
{
    int data1;
    char data2;
    float data3;
};
struct node
{
    int tag;
    union u value;
};
struct nodestack
{
    int size;
    int max_size;
    node elements[10001];
};
void push(nodestack& s,node x)
{
    if(s.size==s.max_size)
        cout <<"Stack is Full\n";
    else
    {
       s.size++;
       s.elements[s.size-1]=x;
    }
}
node pop(nodestack& s)
{
    if(s.size==0)
           cout <<"Stack is Empty\n";
    else
    {
        s.size--;
        return s.elements[s.size];
    }
}
int main()
{
    nodestack S;
    S.size=0;
    S.max_size=10000;int a;
    cout<<"enter size of generic stack"<<endl;
    cin>>a;
for(int i=0;i<a;i++){

    cout <<"Enter data tag to enter 1.int 2.char 3.float\n";
    node x;
     
        cin >>x.tag;
		cout<<"enter the data"<<endl;
        if(x.tag!=0)
        {
            switch(x.tag)
            {
                case 1:{cin >>x.value.data1;
                        push(S,x);
                        }
                       break;
                case 2:{cin >>x.value.data2;
                         push(S,x);
                        }
                        break;
                case 3:{cin >>x.value.data3;
                        push(S,x);
                        }       
                        break;
            }
        }

    }



    while(S.size!=0)
    {

       node y=pop(S);
       switch(y.tag)
       {
           case 1:cout <<y.value.data1<<endl;
           break;
           case 2:cout <<y.value.data2<<endl;
           break;
           case 3:cout <<y.value.data3<<endl;
           break;

       }
    }


    return 0;

}
