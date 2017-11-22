#include <iostream>
#include <vector>
#include <ctime>
#include <random>


/**
 * @name 			quickSort
 * @parameter 		std::vector<T> &, const int begin, const int end
 * @return 			void
 *
 * @author 			Diogo Dantas
 *
 * Implementation of classic sort algorithm called quick sort.
 * The pivot is always chosen as the last element of the vector.
 */

template<typename T>
void quickSort(std::vector<T> &unordered_vector ,const int begin, const int end)
{
	T pivot = end;

	int i = begin;
	int j = end-1;

	while(true){
		while(unordered_vector[i] <= unordered_vector[pivot] && i < end)
			i++;

		while(unordered_vector[j] > unordered_vector[pivot] && j >= begin)
			j--;

		if(i < j){
			std::swap(unordered_vector[j], unordered_vector[i]);
		}
		else{
			std::swap(unordered_vector[pivot], unordered_vector[i]);
			break;
		}
	}

	if(begin < i-1)
		quickSort(unordered_vector, begin, i-1);
	if(i+1 < end)
		quickSort(unordered_vector, i+1, end);
}

int main(int argc, char const *argv[])
{
	std::vector<int> input;
 	int count = 0, tmp = 0, input_size;

 	std::cin >> input_size;

 	while(count < input_size) {
 		std::cin >> tmp;
 		input.push_back(tmp);
 		++count;
 	}

 	quickSort(input, 0, input.size() - 1);

 	for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
 	{
 		std::cout << *it << std::endl;
 	}

	return 0;
}
