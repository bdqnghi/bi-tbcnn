#include <iostream>
#include <sys/time.h>
#include <cmath>

using namespace std;




int main(){
  int temp = 0;
  bool swapped =true;
  struct timeval tv;
  double t1 = 0;
  double t2 = 0;
  double total_time = 0;
  int j = 0;
  int DATA_SIZE = 0;

  for(double r = 5; r<18; r++){
    DATA_SIZE = int(pow(2.0,r));
    int a[DATA_SIZE];
    j=0;
    swapped = true;


  for(int i = 0; i < DATA_SIZE; i++){
    a[i] = rand();
  }

  gettimeofday(&tv, NULL);
  t1=tv.tv_sec+tv.tv_usec/1000000.0;

  while(swapped && j<(DATA_SIZE - 1)){
    swapped = false;
    for(int i = 0;i<DATA_SIZE - (1+j);i++){
      if(a[i]>a[i+1]){
	temp = a[i];
	a[i] = a[i+1];
	a[i+1] = temp;
	swapped = true;
      }
    }
    j++;
  }

   gettimeofday(&tv, NULL);
   t2=tv.tv_sec+tv.tv_usec/1000000.0;
   total_time = t2-t1;
   cout<<"T["<<r<<"] = "<<total_time<<endl;
   cout<<"logT["<<r<<"] = "<<(log(total_time))/(log(2.0))<<endl;
}
}
