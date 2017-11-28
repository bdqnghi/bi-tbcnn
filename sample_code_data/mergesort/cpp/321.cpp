/**

  Zadanie J: Szybkie sortowanie.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe.

  Złożoność rozwiązania: O(n lg n)

  Opis rozwiązania: 
    Idea algorytmu na wykorzystaniu metody dziel i zwyciężaj. Dzielimy tablicę na
    pół, sortujemy rekurencyjnie obydwie części, a następnie scalamy tak, aby 
    ułożyć elementy w kolejności niemalejącej. Rekurencja zatrzymuje się na tablicy
    o długości jeden, gdzie nie musimy nic robić - taka tablica jest zawsze posortowana.

    Operacja scalania może zostać wykonana liniowo. Jeśli mamy dwie posortowane
    tablice, to scalenie polega na ustawieniu dwóch wskaźników na początku tych
    tablic, wybieraniu zawsze mniejszego elementu do wpisania do tablicy wynikowej
    oraz odpowiedniego przesuwania wskaźników. Gdy któraś z tablic się skończy
    przepisujemy elementy pozostałej do tablicy wynikowej.

    Głębokość rekursji algorytmu jest rzędu O(lg n). Na każdym z poziomów rekurencji
    potrzebujemy scalić łącznie około n elementów, co robimy w czasie O(n). To daje
    łącznie czas działania rzędu O(n).

**/

#include <cstdio>
#include <vector>

using namespace std;

void merge(int* first_part, int first_part_size, int* second_part, int second_part_size, int* destination) {
  int merged_size = first_part_size + second_part_size;
  int* merged = new int[merged_size];
  
  int first_index = 0, second_index = 0, i = 0;

  while(first_index < first_part_size && second_index < second_part_size) {
    if(first_part[first_index] <= second_part[second_index]) {
      merged[i++] = first_part[first_index++];
    }
    else {
      merged[i++] = second_part[second_index++];
    }
  }

  while(first_index < first_part_size) {
    merged[i++] = first_part[first_index++];
  }

  while(second_index < second_part_size) {
    merged[i++] = second_part[second_index++];
  }

  for(int i=0; i < merged_size; ++i) {
    destination[i] = merged[i];
  }

  delete merged;
}

void merge_sort(int* data, int size) {
  if(size == 1) {
    return;
  }

  int first_part_size = size / 2;
  int second_part_size = size - first_part_size;

  int* first_part = data;
  int* second_part = data + first_part_size;

  merge_sort(first_part, first_part_size);
  merge_sort(second_part, second_part_size);

  merge(first_part, first_part_size, second_part, second_part_size, data);
}

int main() {
  int n;
  scanf("%d", &n);

  int* numbers = new int[n];

  for(int i=0; i<n; ++i) {
    scanf("%d", &numbers[i]);
  }

  merge_sort(numbers, n);

  for(int i=0; i<n; ++i) {
    printf("%d ", numbers[i]);
  }

  delete numbers;

  return 0;
}