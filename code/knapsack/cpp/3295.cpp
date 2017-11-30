#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream dataFile("items1.txt");
  string line;
  int maxWeight, numItems;

  getline(dataFile, line);
  istringstream iss(line);
  iss >> maxWeight >> numItems;

  cout << "NumItems: " << numItems << ". Sack: " << maxWeight << endl;
  // init a matrix with 0s
  int** matrix = 0;
  matrix = new int*[numItems];
  for (int i = 0; i < numItems; i++) {
    matrix[i] = new int[maxWeight];

    for (int x = 0; x < maxWeight; x++) {
      matrix[i][x] = 0;
    }
  }

  int value, weight, curWeight;
  int i = 0;
  while (getline(dataFile, line))
  {
    istringstream iss(line);
    iss >> value >> weight;
//    cout << "i/v/w:" << i << "," << value << "," << weight << endl;

    for (int x = 0; x < maxWeight; x++) {
      curWeight = x + 1;
      // only compare if we fit in an x sized sack
      if (weight <= curWeight) {
        if (i == 0) {
          // if first i, fill with value:
          matrix[i][x] = value;
        } else {
          // not first i, choose max value betewen
          if (matrix[i-1][x] > matrix[i-1][curWeight-weight - 1] + value) {
            matrix[i][x] = matrix[i-1][x];
          } else {
            matrix[i][x] = matrix[i-1][curWeight-weight - 1] + value;
          }
        } // first i?
      } else {
        // we don't fit in an x-sized sack, so we need to copy over the answer
        // from i-1[x]
        if (i != 0) {
          matrix[i][x] = matrix[i-1][x];
        }
      } // weight <= curWeight?
//      cout << i << "," << x << " = " << matrix[i][x] << endl;
    } // loop all weights
    i++;
  }
  dataFile.close();

  // answer is in last/last of matrix:
  cout << "Max Value: " << matrix[numItems - 1][maxWeight - 1] << endl;
  return 1;
}
