#include <vector>
#include <algorithm>
#include "Student.h"
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Tokenizer.h"

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

void quicksort(int low, int high, vector<Student> &A){ // quicksort 
	int pivotpoint;
	if( high > low){
		partition(low, high, pivotpoint, A);
		quicksort(low, pivotpoint-1, A);
		quicksort(pivotpoint+1, high, A);
	}
}

void quicksort( vector<Student> &A){
	return quicksort(0,A.size()-1,A);
}

int main(int argc , char * argv[]){
	char* fName = argv[1];
	if (fName == NULL) { // ���� ������ ������ ���� ���� 
		cout << "������ �����ϴ�. \n";
		system("pause");
		exit(0);
	}
	
	vector<Student> A = readinput(fName);
	for_each(A.begin(), A.end(), print_element<Student>);
	quicksort(A);
	for_each(A.begin(), A.end(), print_element<Student>);
	system("pause");
	return 0;
}

