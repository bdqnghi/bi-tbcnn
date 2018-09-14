#include<iostream>
#include<vector>
#include<algorithm>

#include<time.h>
#include<sys/time.h>

std::vector<int> merge(std::vector<int> array1,std::vector<int> array2);

std::vector<int> mergeSort(std::vector<int> array);

std::vector<int> produceVector(int size);

double gettimeofday_sec();

int main(){
  std::vector<int> array;
  double startTime[]={0,0,0,0,0},endTime[]={0,0,0,0,0};
  const int NUM=1;
  const int SIZE[] = {10,100,1000,10000,100000};
  for(int i=0;i<5;i++){
    for(int j=0;j<NUM;j++){
      array = produceVector(SIZE[i]);
      startTime[i] += gettimeofday_sec();
      array = mergeSort(array);
      endTime[i] += gettimeofday_sec();
    }
    std::cout << "size " << SIZE[i] << " is complete" << std::endl;
  }
  for(int i=0;i<5;i++){
    std::cout << "size " << SIZE[i] << ":" << (endTime[i]-startTime[i])/NUM << std::endl;
  }
  return 0;
}

std::vector<int> merge(std::vector<int> array1,std::vector<int> array2){
  std::vector<int> array;
  int i=0,j=0;
  for(int k=0;k<(int)(array1.size()+array2.size());k++){
    if(i<(int)array1.size() && j<(int)array2.size()){
      if(array1[i]<array2[j]){    
	array.push_back(array1[i]);
	i++;
      }else{
	array.push_back(array2[j]);
	j++;
      }
    }else if(j>=(int)array2.size()){
      array.push_back(array1[i]);
      i++;
    }else if(i>=(int)array1.size()){
      array.push_back(array2[j]);
      j++;
    }
  
  }
  return array;
}

std::vector<int> mergeSort(std::vector<int> array){
  if(array.size()<=1){
    return array;
  }

  std::vector<int> preArray1,preArray2;
  int index = array.size()/2;
  //std::cout << index << std::endl;
  auto itr = array.begin();
  for(;itr<array.begin()+index;itr++)
    preArray1.push_back(*itr);
  for(;itr<array.end();itr++)
    preArray2.push_back(*itr);

  
  std::vector<int> array1 = mergeSort(preArray1);
  std::vector<int> array2 = mergeSort(preArray2);
  
  return merge(array1,array2);
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
