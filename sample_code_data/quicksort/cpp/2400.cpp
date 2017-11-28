/*Algorithm::QuickSort*/

#include <iostream>
#define ARRAYSIZE 10
using namespace std;

unsigned int userInput(unsigned int *);

int main(int argc, char **argv)
{
  unsigned int inputArray[ARRAYSIZE];
  unsigned int inputArraySize = userInput(inputArray);

  for(unsigned int i = 1; i < inputArraySize; i++)  {
    int noToInsert = inputArray[i];
    //Find input array index where noToInsert should be inserted
    unsigned int j = 0;
    for(; j < i; j++)  {
      if(inputArray[j] > inputArray[i])  {
        break;
      }
    }
    //Insert noToInsert at index position j
    for(unsigned int k = i; k != j; k--)  {
      int tmp = inputArray[k];
      inputArray[k] = inputArray[k - 1];
      inputArray[k - 1] = tmp;
    }
  }

  for(unsigned int i = 0; i < inputArraySize; i++)  {
    cout << inputArray[i] << "\t";
  }
}


unsigned int userInput(unsigned int *inputArray)
{
  unsigned int inputArraySize = 0;
  cout << "Enter list of number and have them sorted."
       << "(Enter ZERO to terminate input)" << endl;
  /* Take input from user */
  for(inputArraySize = 0; inputArraySize < ARRAYSIZE; inputArraySize++)  {
    cout << "Enter a number :(" << inputArraySize + 1 << ") :" << endl;
    cin >> inputArray[inputArraySize];
    if(inputArray[inputArraySize] == 0)  {
      break;
    }
  }
  return inputArraySize;
}
