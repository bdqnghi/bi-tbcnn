#include <vector>
#include <algorithm>
#include "Student.h"
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Tokenizer.h"
#include <time.h>
#define NO_FUNC 3
template<typename T>
void print_element(T st){ // ���ø��� �̿��� ���  
	cout << st.get_name() << "\t" << st.get_telno()<< endl;
} 



#define TRIM_SPACE " \t\n\v" // Ʈ�� �̿�� ���־��� white space 


using namespace std;

namespace ospace { 
 inline std::string trim(std::string& s,const std::string& drop = TRIM_SPACE)
 {
  std::string r=s.erase(s.find_last_not_of(drop)+1);
  return r.erase(0,r.find_first_not_of(drop));
 }
inline std::string rtrim(std::string s,const std::string& drop = TRIM_SPACE)
 {
  return s.erase(s.find_last_not_of(drop)+1);
 }
inline std::string ltrim(std::string s,const std::string& drop = TRIM_SPACE)
 {
  return s.erase(0,s.find_first_not_of(drop));
 }
}

using ospace::trim;
using ospace::ltrim;
using ospace::rtrim;


vector<Student> readinput(char * fName){  //���� ������  
	vector<Student> words;
	ifstream in(fName);
	string word;
	Tokenizer str; 
	Student stu;
	string name;
	string telno;
	if (in.is_open()) { // ����  ����  
		while (!in.eof()) { // ����  ���̱� ������  ����
			getline(in, word); // 1�� �б� 
			trim(word);  // 1�� �յڷ� white space ����  
			str.set(word); // #��ũ�������� ������. => tokenizer.h ���Ͽ���  const std::string DEFAULT_DELIMITER = "#"; �̺κ��� �ٲ���ϴ�. 
			stu.set_name(trim(name = str.next())); // �̸� �κ�  trim �ϰ� ����  
			stu.set_telno(trim(telno = str.next())); // ����ȣ �κ� trim�ϰ� ����  
			words.push_back(stu); // Student ���� ����  
		}
	}
	return words;

}
#define CLOCKS_PER_SEC 100
int time_print(string method, vector<Student>& A, int (*sorter)(vector<Student>&)) {
	
   clock_t start = clock();
   for(int i = 0; i<CLOCKS_PER_SEC; i++){
		sorter(A);
   }
   clock_t end = clock();

   vector<Student>::iterator it;
   for (it = A.begin(); it != A.end(); it++) 
      it -> print();

   double diff = (double)(end - start) / CLOCKS_PER_SEC;
   printf("%-20s ", method.c_str()) ;
   printf("time = %13.9lf sec\n", diff);

   return 1;
}
void exchange(vector<Student>&A, int i, int j){
	Student temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}


int exchangeSort (vector<Student>& A) {
	int size = A.size()-1 ;
	for(int i = 0; i<=size; i++){
		for(int j=i+1; j<=size; j++){
			if(A[j] < A[i])
				exchange(A,i,j);
		}
	}
	return  0;
}

void merge2(vector<Student>& A, int low, int mid, int high){
	int i = low;
	int j = mid+1;
	vector<Student> B;
	while( i<= mid && j<= high){
		if (A[i] < A[j]){
			B.push_back(A[i]);
			i++;
		}
		else{
			B.push_back(A[j]);
			j++;
		}
	}
	
	if( i>mid){
		for(;j<=high;j++)
			B.push_back(A[j]);
		
	}
	else{
		for(; i<high;i++)
			B.push_back(A[i]);
		
	}
	for(i = low, j = 0; i<=high; i++,j++)
		A[i] = B[j];
}

int mergesort2(vector<Student>& A, int low, int high){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		mergesort2(A,low,mid);
		mergesort2(A,mid+1,high);
		merge2(A,low,mid,high);
	}
	return 0;
}

int mergeSort (vector<Student>& A) {

	return mergesort2(A,0,A.size()-1);
}


void partition(int low, int high, int& pivotpoint, vector<Student>& A){ // quicksort partition �κ�  
	int i;
	int j;
	
	Student pivotitem = A[low];
	j = low;
	for( i = low +1; i<=high; i++){
		if(A[i] < pivotitem){
			j++;
			Student temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	pivotpoint = j;
	Student temp = A[low];
	A[low] = A[pivotpoint];
	A[pivotpoint] = temp;
	
}

int quicksort(int low, int high, vector<Student> &A){ // quicksort 
	int pivotpoint;
	if( high > low){
		partition(low, high, pivotpoint, A);
		quicksort(low, pivotpoint-1, A);
		quicksort(pivotpoint+1, high, A);
	}
	return 0;
}

int quickSort( vector<Student> &A){
	return quicksort(0,A.size()-1,A);
}


struct Sorter {
	char *name;
	int (*function)(vector <Student>& A); 
};

struct Sorter sorter[NO_FUNC] = {
	{"exchange sort", exchangeSort},
	{"merge sort", mergeSort},
	{"quick sort", quickSort}
};

int main(int argc , char * argv[]){
	char* fName = argv[1];
	if (fName == NULL) { // ���� ������ ������ ���� ���� 
		cout << "������ �����ϴ�. \n";
		system("pause");
		exit(0);
	}
	
	vector<Student> A = readinput(fName);
	
	for (int i = 0; i < NO_FUNC ; i++) {
	   		vector<Student> B = A;
			time_print(sorter[i].name,  B, sorter[i].function);
			//for_each(B.begin(), B.end(), print_element<Student>);
	}

	system("pause");
	return 0;
}

