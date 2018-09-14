#include<iostream>
#include<ctime>
using namespace std;
int* merge(int* &a, int* &b, int lena, int lenb) {
	//�ϲ������Ѿ����������

	int index = 0;
	int i = 0;
	int j = 0;
	int count = lena + lenb;
	int* tmp = new int[count] {0};
	while (index < count) {
		if (a[i] < b[j]) {
			if (i < lena) {
				tmp[index++] = a[i++];
			}
			else {
				tmp[index++] = b[j++];
			}
		}
		else {
			if (j < lenb) {
				tmp[index++] = b[j++];
			}
			else {
				tmp[index++] = a[i++];
			}
		}
	}
	return tmp;
}

void mergesort(int* &p, int len, int step) {
	for (int nth = 0; nth < len; nth += step*2) {
		int* p1 = p + nth;
		int* p2 = p + nth + step;
		int len1 = step;
		int len2 = step;
		if ((len - nth - step) < step) {
			len2 = len - nth - step;
		}
		if ((nth + step) > len) {
			len1 = len - nth;
			len2 = 0;
		}
		int* p3 = merge(p1, p2, len1, len2);
		for (int i = 0; i < len1 + len2; i++) {
			p[nth + i] = p3[i];
		}
		delete[] p3;
	}
	if (step < len) {
		mergesort(p, len, step * 2);
	}
}

int* randomArray(int len) {
    //�����������

	srand((unsigned)time(0));
	int* tmp = new int[len] {0};
	for (int i = 0; i < len; i++) {
		tmp[i] = rand() % len;
	}
	return tmp;
}
int main() {
	int len = 10;
	int step = 1;
	//int* arr = randomArray(len);
	int* arr = new int[len] {1, 6, 0, 3, 3, 8, 2, 4, 1, 1};
	cout << "Array : ";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	clock_t start = clock();

	mergesort(arr, len, step);

	clock_t ends = clock();

	cout << "Running Time : " << (double)(ends - start) / CLOCKS_PER_SEC << endl;

	cout << "Array : ";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	system("pause");
}