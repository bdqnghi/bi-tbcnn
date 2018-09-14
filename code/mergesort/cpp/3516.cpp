//#include <fstream>
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//void split_sort_inv(vector<string>& str1, vector<string>& str2) {
//
//}
//
//void mergestr(vector<string>& str,int begin,int n, int end) {
//	vector<string> str1(str.begin() + begin, str.begin() + n);
//	vector<string> str2(str.begin() + n, str.begin() + end);
//
//	while (!str1.empty() && !str2.empty()) {
//		if (stoi(str1.front()) < stoi(str2.front())) {
//			str[begin] = str1.front();
//			str1.erase(str1.begin());
//			begin++;
//		}
//		else if (stoi(str2.front()) < stoi(str1.front())) {
//			str[begin] = str2.front();
//			str2.erase(str2.begin());
//			begin++;
//		}
//	}
//
//	if (!str1.empty()) {
//		int len = str1.size();
//		for (int i = len; i >0; --i) {
//			str[end-1] = str1.back();
//			str1.pop_back();
//			end--;
//		}
//	}
//
//	else if (!str2.empty()) {
//		int len = str2.size();
//		for (int i = len; i > 0; --i) {
//			str[end-1] = str2.back();
//			str2.pop_back();
//			end--;
//		}
//	}
//}
//
//void sort_inv(vector<string>& str, int begin, int end) {
//	if ((end-begin)>=2){
//		int n = (end - begin) / 2;
//		sort_inv(str, begin, begin + n);
//		sort_inv(str, begin + n, end);
//		mergestr(str, begin, begin + n, end);
//	}
//}
//
//int main(){
//	ifstream in("array.txt");
//	vector<string> a;
//	string line;
//	while (getline(in, line)) 
//	{
//		a.push_back(line);
//	}
//	cout<<"ok"<<endl;
//	int size = a.size();
//	sort_inv(a,0,size);
//	for (int i = 0; i < size; ++i) {
//		cout << a[i] << endl;
//	}
//	getchar();
//	return 0;
//}
//
//
////queue<string> q;
////int begin2 = mid;
////while (begin1 != mid&&begin2 != end) {
////	if (stoi(str[begin1]) < stoi(str[begin2])) {
////		q.push(str[begin1]);
////		begin1++;
////	}
////	else {
////		q.push(str[begin2]);
////		begin2++;
////	}
////}

