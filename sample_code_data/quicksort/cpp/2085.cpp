#include <iostream>  	// cout
#include <utility>  	// swap
#include <random>       // default_random_engine
#include <cstdlib>      // rand, srand
#include <algorithm>  	// max, shuffle, is_sorted
#include <ctime>        // time
#include <chrono>
// TAGS: quicksort, quick sort, partition, median, benchmark

using namespace std::chrono;
using std::cout;
using std::endl;

static std::default_random_engine RandomEngine;

#define BENCHMARK(s, block) \
	const auto time_start_bench = std::chrono::steady_clock::now(); \
	block \
	const auto time_end_bench = std::chrono::steady_clock::now(); \
	const auto time_delta_bench = time_end_bench - time_start_bench; \
	cout << s << " took " << duration_cast<microseconds>(time_delta_bench).count()/1000000. << " s" << endl;

#define BENCHMARK_SORT(s, callback) { \
	BENCHMARK(s, \
 		for (size_t i = 0; i < N_stress; ++i) { \
			std::shuffle(A, A + N, RandomEngine); \
			callback; \
			if (!std::is_sorted(A, A + N)) { \
				cout << s << " failed at " << i << " iteration!\n\t"; \
				show(A); \
				break; \
			} \
		}); \
}


template<typename T, size_t N>
constexpr size_t size(T (&)[N]) { return N; }

template<typename T, size_t N>
void show(T (&A)[N]) {
	for (size_t i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}


template<typename T>
T random(T a, T b) {
	return rand() % (b-a+1) + a;
}


template<typename T, size_t N>
size_t median_of_3(T (&A)[N], size_t p, size_t r) {
	if (r-p+1 < 3) {
		return p;
	}

	T a = A[p];
	T b = A[r];
	T c = A[(p+r)/2];

	if (a >= b && a >= c) {
		if (b >= c) {
			return r;  // b
		} else {
			return (p+r)/2;  // c
		}
	} else if (b >= a && b >= c) {
		if (a >= c) {
			return p;  // a
		} else {
			return (p+r)/2;  // c
		}
	} else {
		if (a >= b) {
			return p;  // a
		} else {
			return r;  // b
		}
	}
}

template<typename T, size_t N>
size_t median_of_3_randomized(T (&A)[N], size_t p, size_t r) {
	if (r-p+1 < 3) {
		return p;
	}

	T a = A[random(p, r)];
	T b = A[random(p, r)];
	T c = A[random(p, r)];

	if (a >= b && a >= c) {
		if (b >= c) {
			return r;  // b
		} else {
			return (p+r)/2;  // c
		}
	} else if (b >= a && b >= c) {
		if (a >= c) {
			return p;  // a
		} else {
			return (p+r)/2;  // c
		}
	} else {
		if (a >= b) {
			return p;  // a
		} else {
			return r;  // b
		}
	}
}


// Cormen`s  (Seems to be not working with non-unique elements...)
// template<typename T, size_t N>
// size_t partition(T (&A)[N], size_t p = 0, size_t r = N-1) {
// 	T x = A[p];
// 	size_t i = p,  j = r;
// 	while (true) {
// 		while (A[j] > x) { --j; }
// 		while (A[i] < x) { ++i; }
// 		if (i < j)
// 			std::swap(A[i], A[j]);
// 		else
// 			return j;
// 	}
// }

template<typename T, size_t N>
size_t partition(T (&A)[N], size_t l = 0, size_t r = N-1) {
	T x = A[l];
	size_t j = l;

	for (size_t i = l+1; i <= r; ++i) {
		if (A[i] < x) {
			++j;
			std::swap(A[j], A[i]);
		}
	}

	std::swap(A[l], A[j]);
	return j;
}

template<typename T, size_t N>
size_t partition_median_of_3(T (&A)[N], size_t p = 0, size_t r = N-1) {
	std::swap(A[p], A[median_of_3(A, p, r)]);
	return partition(A, p, r);
}

template<typename T, size_t N>
size_t partition_randomized(T (&A)[N], size_t p = 0, size_t r = N-1) {
	std::swap(A[p], A[random(p, r)]);
	return partition(A, p, r);
}

template<typename T, size_t N>
size_t partition_randomized_median_of_3(T (&A)[N], size_t p = 0, size_t r = N-1) {
	std::swap(A[p], A[median_of_3_randomized(A, p, r)]);
	return partition(A, p, r);
}

template<typename T, size_t N>
size_t partition_lomuto(T (&A)[N], size_t p = 0, size_t r = N-1) {
	T x = A[r];
	size_t i = p - 1;

	for (size_t j = p; j <= r; ++j) {
		if (A[j] <= x) {
			std::swap(A[++i], A[j]);
		}
	}

	if (i < r) {
		return i;
	} else {
		return i - 1;
	}
}

template<typename T, size_t N>
size_t partition_lomuto_median_of_3(T (&A)[N], size_t p = 0, size_t r = N-1) {
	std::swap(A[p], A[median_of_3(A, p, r)]);
	return partition_lomuto(A, p, r);
}

template<typename T, size_t N>
size_t partition_lomuto_randomized(T (&A)[N], size_t p = 0, size_t r = N-1) {
	std::swap(A[p], A[random(p, r)]);
	return partition_lomuto(A, p, r);
}

template<typename T, size_t N>
size_t partition_lomuto_randomized_median_of_3(T (&A)[N], size_t p = 0, size_t r = N-1) {
	std::swap(A[p], A[median_of_3_randomized(A, p, r)]);
	return partition_lomuto(A, p, r);
}


template<typename T, size_t N>
void quicksort(T (&A)[N], size_t p = 0, size_t r = N-1) {
	if (p < r) {
		size_t q = partition(A, p, r);
		quicksort(A, p, q);
		quicksort(A, q + 1, r);
	}
}

template<typename T, size_t N>
void quicksort_iterative(T (&A)[N], int p = 0, int r = N-1) {  // int! r
	while (p < r) {
		size_t q = partition(A, p, r);
		if (q-p < r-q) {  // q-1-p < r-(q+1)
			quicksort_iterative(A, p, q - 1);  // left part
			p = q + 1;
		}
		else {
			quicksort_iterative(A, q + 1, r);  // right part
			r = q - 1;
		}
	}
}

template<typename T, size_t N>
void quicksort_median_of_3(T (&A)[N], size_t p = 0, size_t r = N-1) {
	if (p < r) {
		size_t q = partition_median_of_3(A, p, r);
		quicksort_median_of_3(A, p, q);
		quicksort_median_of_3(A, q+1, r);
	}
}

template<typename T, size_t N>
void quicksort_randomized(T (&A)[N], size_t p = 0, size_t r = N-1) {
	if (p < r) {
		size_t q = partition_randomized(A, p, r);
		quicksort_randomized(A, p, q);
		quicksort_randomized(A, q+1, r);
	}
}

template<typename T, size_t N>
void quicksort_randomized_median_of_3(T (&A)[N], size_t p = 0, size_t r = N-1) {
	if (p < r) {
		size_t q = partition_randomized_median_of_3(A, p, r);
		quicksort_randomized_median_of_3(A, p, q);
		quicksort_randomized_median_of_3(A, q+1, r);
	}
}

template<typename T, size_t N>
void quicksort_iterative_randomized(T (&A)[N], int p = 0, int r = N-1) {
	while (p < r) {
		size_t q = partition_randomized(A, p, r);
		if (q-p < r-q) {
			quicksort_iterative(A, p, q - 1);  // left part
			p = q + 1;
		}
		else {
			quicksort_iterative(A, q + 1, r);  // right part
			r = q - 1;
		}
	}
}

template<typename T, size_t N>
void quicksort_lomuto(T (&A)[N], size_t p = 0, size_t r = N-1) {
	if (p < r) {
		size_t q = partition_lomuto(A, p, r);
		quicksort_lomuto(A, p, q);
		quicksort_lomuto(A, q+1, r);
	}
}

template<typename T, size_t N>
void quicksort_lomuto_median_of_3(T (&A)[N], size_t p = 0, size_t r = N-1) {
	if (p < r) {
		size_t q = partition_lomuto_median_of_3(A, p, r);
		quicksort_lomuto_median_of_3(A, p, q);
		quicksort_lomuto_median_of_3(A, q+1, r);
	}
}

template<typename T, size_t N>
void quicksort_lomuto_randomized(T (&A)[N], size_t p = 0, size_t r = N-1) {
	if (p < r) {
		size_t q = partition_lomuto_randomized(A, p, r);
		quicksort_lomuto_randomized(A, p, q);
		quicksort_lomuto_randomized(A, q+1, r);
	}
}

template<typename T, size_t N>
void quicksort_lomuto_randomized_median_of_3(T (&A)[N], size_t p = 0, size_t r = N-1) {
	if (p < r) {
		size_t q = partition_lomuto_randomized_median_of_3(A, p, r);
		quicksort_lomuto_randomized_median_of_3(A, p, q);
		quicksort_lomuto_randomized_median_of_3(A, q+1, r);
	}
}


int main() {
	srand(time(0));
	int A[] {67,28,76,70,46,2,23,14,23,57,7,15,54,55,4,78,57,37,63,74,26,58,36,56,62,36,67,24,50,33,75,32,53,2,44,69,5,67,93,13,14,86,36,94,6,61,97,65,73,89,66,10,61,40,49,44,59,72,67,3,5,80,82,22,5,59,57,98,12,70,43,68,21,2,6,4,1,64,30,88,55,19,48,15,49,76,90,47,38,51,59,96,1,71,31,83,29,52,76,47,97,13,2,44,18,43,86,63,42,35,31,54,52,49,45,58,85,79,83,51,23,3,75,73,96,15,44,10,87,5,16,50,79,64,4,96,67,55,23,80,40,69,96,98,9,49,36,51,81,48,86,44,98,39,78,39,34,99,26,57,1,38,72,95,81,9,67,50,8,53,15,49,8,1,57,35,40,66,66,70,35,93,59,16,82,79,48,21,3,12,31,8,32,83,65,1,83,69,70,6,62,96,28,88,60,50,59,5,86,89,20,63,26,13,16,68,60,82,44,35,83,10,10,45,33,85,97,65,4,45,41,85,30,2,18,13,96,47,15,23,74,72,73,24,39,5,8,89,85,45,95,75,24,37,65,60,36,29,54,19,18,69,68,12,40,69,7,9,77,89,99,56,39,73,74,21,51,57,2,28,63,78,43,93,79,47,59,74,89,95,55,40,16,22,55,29,14,73,59,74,27,75,14,3,33,11,61,16,14,62,47,87,59,98,52,89,4,43,71,17,30,37,36,16,98,61,74,32,20,49,93,70,93,25,56,90,34,49,90,81,89,37,38,21,56,69,35,33,98,9,34,90,49,14,13,78,88,91,76,51,78,94,29,2,87,26,86,49,6,81,85,24,25,21,16,88,77,20,30,91,96,36,23,79,49,53,14,40,47,70,9,2,66,18,52,25,68,18,83,28,12,9,34,77,57,36,91,35,34,88,41,69,77,32,63,34,77,42,39,82,1,33,70,63,19,98,44,66,23,54,1,90,33,43,45,80,36,2,9,85,76,82,57,4,62,79,82,67,82,70,97,20,69,60,6,86,22,70,11,55,41,17,39,56,18,63,85,50,37,38,76,31,83,33,75,99,60,97,46,40,82,10,98,88,20,50,6,55,84,75,6,81,24,85,36,77,59,26,57,96,23,89,84,23,26,38,94,3,65,34,60,79,86,18,34,26,10,84,4,2,32,84,69,20,38,15,54,91,80,35,23,85,55,62,32,84,98,46,64,16,13,42,69,13,76,97,40,21,49,17,82,72,73,28,95,69,46,55,82,98,81,96,49,3,98,33,78,28,33,53,68,75,45,66,7,5,7,12,89,57,36,3,59,25,11,28,29,99,95,95,81,10,40,79,40,91,20,81,85,85,64,65,36,7,12,66,22,78,19,31,11,90,87,81,29,59,36,45,74,13,71,60,42,31,36,68,61,17,60,3,90,99,12,95,65,17,79,42,77,99,41,11,72,24,10,52,34,97,82,9,10,55,30,70,12,45,99,44,93,25,6,9,28,96,54,6,41,30,40,71,67,13,14,68,34,79,57,79,90,81,37,40,16,18,52,47,56,46,19,37,92,69,98,58,61,95,58,20,28,63,40,51,57,38,15,17,60,21,82,74,2,18,25,72,59,51,11,11,37,39,38,67,41,70,59,7,48,28,63,38,37,25,75,85,37,59,45,85,96,47,47,12,2,37,72,79,22,20,33,15,2,51,45,7,49,73,62,41,79,69,21,30,12,88,78,4,10,47,2,96,25,18,95,53,91,22,32,96,7,1,77,60,68,2,53,30,40,17,74,13,87,36,43,25,63,78,82,9,69,85,12,50,2,27,57,40,11,10,73,45,71,3,64,66,63,28,45,24,78,35,23,80,40,42,39,18,86,22,40,2,47,77,23,30,19,44,42,25,55,36,9,7,37,74,51,7,87,44,63,18,85,63,80,2,81,23,1,90,40,48,91,7,27,52,3,2,75,11,2,43,69,85,3,95,1,28,97,42,71,65,92,45,4,8,82,68,92,92,69,23,7,42,26,77,20,92,36,63,97,19,29,49,7,32,26,2,27,92,75,63,29,9,13,8,44,51,86,26,33,74,14,96,92,76,66,91,42,25,85,85,85,68,30,12,9,17,59,91,2,65,66,76,6,87,43,3,11,20,72,62,77,90,10,24,58,9,23,27,33,47,34,29,41,25,56,88,7,9,45,24,97,61,57,76,67,4,73,43,10,58,35,7,54,84,18,53,66,85,88,28,80,73,19,89,35,45,69,77,91,91};

	size_t N = size(A);
	size_t N_stress = 10000;
	cout << "Stress test with N=" << N_stress << " for size=" << size(A) << " started..." << endl;

	BENCHMARK_SORT("Default", std::sort(A, A + N))
	BENCHMARK_SORT("Quicksort", quicksort(A))
	BENCHMARK_SORT("Quicksort-Iterative", quicksort_iterative(A))
	BENCHMARK_SORT("Quicksort-Lomuto", quicksort_lomuto(A))
	BENCHMARK_SORT("Quicksort-Randomized", quicksort_randomized(A))
	BENCHMARK_SORT("Quicksort-Iterative-Randomized", quicksort_iterative_randomized(A))
	BENCHMARK_SORT("Quicksort-Lomuto-Randomized", quicksort_lomuto_randomized(A))
	BENCHMARK_SORT("Quicksort-Median-of-3", quicksort_median_of_3(A))
	BENCHMARK_SORT("Quicksort-Lomuto-Median-of-3", quicksort_lomuto_median_of_3(A))
	BENCHMARK_SORT("Quicksort-Randomized-Median-of-3", quicksort_randomized_median_of_3(A))
	BENCHMARK_SORT("Quicksort-Lomuto-Randomized-Median-of-3", quicksort_lomuto_randomized_median_of_3(A))
}
