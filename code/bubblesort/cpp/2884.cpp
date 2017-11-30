#include <bits/stdc++.h>
int main(){

  int a[10],i,j,blank;

  for(i = 0; i < 10; i++) a[i]=i+1;

   for(j = 0; j < 9; j++){

    for(i = 9; i != j; i--){

      if(a[i] < a[i-1]){
	
	blank=a[i];
	a[i]=a[i-1];
	a[i-1]=blank;
	
      }
      
    }
    
  }

  for(i = 0; i < 10; i++) printf("%d\n",a[i]);

  return 0;

}
