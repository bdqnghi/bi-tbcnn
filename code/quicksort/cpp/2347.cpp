#include<bits/stdc++.h>

using namespace std;

//este es un mergesrtcon ua sola funcion, la unica duda que tengo es la condicion de parada
/*
void particion(int *a, int *b, int ini, int fin, int piv){

int i=ini, j=fin, c=ini+1;
    while(c<=fin){

        if(a[c]<a[piv]){
            b[i]=a[c];
            i++;
        }else{
            b[j]=a[c];
            j--;
        }
        c++;
    }
    b[i]=a[piv];

for(int k=ini;k<=fin;k++) a[k]=b[k];

}*/

int particion(int *a, int *b, int ini, int fin){
int i=ini;

for(int j=ini;j<=fin;j++){
    if(a[j]<a[i]){
        i++;
        swap(a[i], a[j]);
    }else if(a[j]==a[i] && j!=i){
        i++;
        int aux=a[i];

        a[i]=a[j];
        a[j]=aux;

    }
}

swap(a[i],a[ini]);
return i;
}

void quicksort(int *a,int *b, int ini, int fin){

if(fin-ini>= 0){

    int piv=particion(a,b, ini, fin);
    quicksort(a,b,ini,piv-1);
    quicksort(a,b,piv+1,fin);
}

}
int main()
{
    int a[] = {12,10,43,23,-78,45,45,123,56,98,41,90,24};
    int num;

    num = sizeof(a)/sizeof(int);

    int b[num];

    quicksort(a,b,0,num-1);

    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
