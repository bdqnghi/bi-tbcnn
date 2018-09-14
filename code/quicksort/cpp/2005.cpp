#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<iterator>


#include<sys/time.h>
#include<time.h>


int selectPivot(std::vector<int> array);

inline std::vector<int> merge(std::vector<int> array1,std::vector<int> array2);

std::vector<int> produceVector(int size);

double gettimeofday_sec();

void print(std::vector<int> array);

void sort(std::vector<int>& array,int r,int p);

static std::random_device rnd;
int main(){
  const int SIZE[] ={10,100,1000,10000,100000};
  std::vector<int> array;
  const int NUM = 1;
  double startTime[]={0,0,0,0,0},endTime[]={0,0,0,0,0};
  for(int i=0;i<5;i++){
    for(int j=0;j<NUM;j++){
      array = produceVector(SIZE[i]);
      startTime[i] += gettimeofday_sec();
      sort(array,0,array.size()-1);
      //print(array);
      endTime[i] += gettimeofday_sec();
    }
    std::cout << "size " << SIZE[i] << " is complete" << std::endl;
  }
  for(int i=0;i<5;i++){
    std::cout << "size " << SIZE[i] << ":" << (endTime[i]-startTime[i])/NUM << std::endl;
  }
  return 0;
}

//無作為にpivotを選ぶ
int selectPivot(std::vector<int> array){     
  return rnd() % array.size();
}  

std::vector<int> produceVector(int size){
  std::vector<int> array;
  for(int i=0;i<size;i++)
    array.push_back(i);
  std::random_shuffle(array.begin(),array.end());
  return array;
}

double gettimeofday_sec(){
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec+(double)tv.tv_usec*(1e-6);
}

void print(std::vector<int> array){
  for(auto i=array.begin();i<array.end();i++)
    std::cout << *i << ",";
  std::cout << std::endl;
}

void sort(std::vector<int>& array,int p, int r){
  if(p>=r)
    return;
  
  int x = array[r];
  int i = p-1;
  for(int j=p;j<r;j++){
    if(array[j]<x){
      i++;
      std::iter_swap(array.begin()+i,array.begin()+j);
    }
  }
  std::iter_swap(array.begin()+i+1,array.begin()+r);
  
  
  sort(array,p,i);
  
  sort(array,i+1,r);

}
