#include<iostream>
#include<ctime>
using namespace std;

void quicksort(int* &p, int left, int right) {
	if (left > right) {
		return;
	}
	int sign = p[left];//ѡ���׼
	int i = left;
	int j = right;
	while (i != j) {
		while (sign >= p[i] && i < j) {
			//���������������ֹͣѭ�������Ž��н���
			i++;
		}
		while (sign < p[j] && i < j) {
			j--;
		}

		if (i < j) {
			int tmp = p[i];
			p[i] = p[j];
			p[j] = tmp;
		}

	}

	int tmp = p[i];
	p[i] = p[left];
	p[left] = tmp;

	quicksort(p, left, i - 1);
	quicksort(p, i + 1, right);

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
	int len = 5;
	int *arr = randomArray(len);
	quicksort(arr, 0, len-1);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;
	system("pause");
}