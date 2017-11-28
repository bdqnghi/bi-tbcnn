#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void merge(vector<T>& array, int start, int mid, int end) {

	int i = start;
	int j = mid + 1;
	int k = 0;


	vector<T> result;
	result.resize(end - start + 1);



	while (i <= mid && j <= end) {

		if (array[i] < array[j]) result[k++] = array[i++];
		else result[k++] = array[j++];
	}


	while (j <= end) {
		result[k++] = array[j++];
	}

	while (i <= mid) {
		result[k++] = array[i++];
	}


	k = 0;
	for (int i = start; i <= end; i++, k++) {
		array[i] = result[k];
	}

}



//����
template<typename T>
void merge_sort(vector<T>& array, int start, int end) {

	int mid; // �߰���


	//if (start >= end) return;//start�� end���� �� Ŀ���� ����.


	if (start < end) {

		mid = (end + start) / 2;//�߰���.

		merge_sort(array, start, mid);//�������� ��� ����
		merge_sort(array, mid + 1, end);//������ ����. ������ȸ ���.


		merge(array, start, mid, end);
	}

}



int main(void)
{
	vector<double> array = { 3.4, 8.2, 0.4, 2.1, 1, 4 };
	merge_sort(array, 0, array.size() - 1);




	for (int i = 0; i < (int)array.size(); i++) {
		printf("%lf ", array[i]);
	}

	return 0;
}
