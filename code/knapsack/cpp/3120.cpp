#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

void knapsackDP(std::vector< std::vector<int> >, int);

int main() {
  std::vector< std::vector<int> > input (6, std::vector<int>(2));
  input[0][0] = 3;
  input[0][1] = 7;
  input[1][0] = 2;
  input[1][1] = 10;
  input[2][0] = 6;
  input[2][1] = 2;
  input[3][0] = 1;
  input[3][1] = 3;
  input[4][0] = 7;
  input[4][1] = 2;
  input[5][0] = 4;
  input[5][1] = 6;
  int weight = 10;
                                    // std::cout << "LLLL" << std::flush;
  std::vector<int> output;
  knapsackDP(input, weight);
  return 0;
}

void knapsackDP(std::vector< std::vector<int> > input, int weight) {

  std::vector< std::vector<int> > board;
  for (int i = 0; i < input.size(); i++) {
    std::vector<int> tmp;
    tmp.push_back(0);
    board.push_back(tmp);
  }
  for (int j = 1; j <= weight; j++) {
    if (input[0][0] > j) board[0].push_back(0); else
    board[0].push_back(input[0][1]);
  }

  for (int i = 1; i < input.size(); i++) {
    for (int j = 1; j <= weight; j++) {
      int tmp = j - input[i][0];
      if (tmp < 0) tmp = INT_MIN;
      else tmp = board[i-1][tmp];
      if (j > input[i][0] && (tmp + input[i][1] > board[i-1][j]) ) {
        board[i].push_back(tmp + input[i][1]);
      } else {
        board[i].push_back(board[i-1][j]);
      }
    }
  }

                          //print board;
                          for(int i = 0; i < board.size(); i++) {
                            for (int j = 0; j < board[i].size() ; j++) {
                              std::cout << board[i][j] << " ";
                            }
                            std::cout << std::endl;
                          }
  // std::vector<int> a;
  // return a;
}
