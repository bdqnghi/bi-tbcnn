#include <iostream>
#include <vector>

template <typename T>
void bubble_sort(std::vector<T>&);

int main() {
  std::vector<int> data = {12, 45, 834, 45, 656, 234, 64, 64, 234, 34, 464, 464, 43};
  bubble_sort(data);

  for (int x : data) {
    std::cout << x << '\n';
  }
  
  return 0;
}

template <typename T>
void bubble_sort(std::vector<T>& data) {
  for (int j = 0; j < data.size(); ++j) {
    for (int i = 1; i < data.size() - j; ++i) {
      if (data[i] < data[i - 1]) {
	T temp = data[i];
	data[i] = data[i - 1];
	data[i - 1] = temp;
      }
    }
  }
}
