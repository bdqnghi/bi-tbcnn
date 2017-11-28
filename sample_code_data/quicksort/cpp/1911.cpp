#include <iostream>
#include <vector>

template <typename T>
void quick_sort(std::vector<T>& data, int left, int right);

int main() {
  //  std::vector<double> data {4.5, 64.6, 243.43, 564.565, 53.31, 22.2, 53.31, 64.6, 74.4, 74.3, 432.0, 5.4};
  std::vector<double> data {1, 12.2, 5, 26, 7.5, 14, 3, 7.5, 2, 45.453, 53.5345, 342.34};
  
  quick_sort(data, 0, data.size() - 1);

  for (double x : data) {
    std::cout << x << '\n';
  }
  
  return 0;
}

template <typename T>
void quick_sort(std::vector<T>& data, int left, int right) {
  int piv_index = (left + right) / 2;
  int i = left, j = right;
  while (i <= j) {
    while (data[i] < data[piv_index]) {
      ++i;
    }
    while (data[j] > data[piv_index]) {
      --j;
    }
    if (i <= j) {
      T temp = data[i];
      data[i] = data[j];
      data[j] = temp;
      ++i;
      --j;
    }
  }
  if (left < i - 1) {
    quick_sort(data, left, i - 1);
  }
  if (i < right) {
    quick_sort(data, i, right);
  }
}
