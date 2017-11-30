/* 
 *@Name - Sagar Nanda
 *@Turnin Id - snanda
 *@FileiName - knapsack.cpp
 *
 *@DESC - Knapsack problem implemented in dynamic programming and recursive backtracking to select the items with maximum value to put into sack.
 *
 *
 */

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

//@Global Variables

int *value;
int *weight;

/*
 * 
 *@DESC : Class Knap implemented with vector of vector to store value grid and backtracking grid. 
 * 
 *@Input : N/A
 * 
 *@Output: N/A
 * 
 */

class Knap
{
    public:
        int no_of_items;
        int W;
        Knap(int items, int Weight);
        vector<vector<int> > V;
        vector<vector<int> > B;
        void backtracking(int i, int j);
        void max_val(int first, int second, int i, int j);
        void fill_array(int items, int value[], int weight [], int W);

};
/*
 *@DESC : Parameterized Contructor for class Knap which initializes the member variable for the class. 
 *
 *@Input  : int items, int weight.
 *
 *@Output : N/A
 */


Knap::Knap(int items, int Weight)
{
    no_of_items = items;
    W = Weight;
    V =  vector<vector<int> >(no_of_items,vector<int>(W+1));
    B =  vector<vector<int> >(no_of_items,vector<int>(W+1));
}

/*
 *@DESC   : Function implemented to file the desired value and using backtracking by recurrence relation given in pdf.
 *         V[1,j] = 0  , if w1 > j
 *         V[1,j] = vi , if w1 <= j
 *         V[i,j] = V[i-1,j], if wi > j
 *         V[i,j] = max(V[i-1,j], V[i-1, j-wi] + vi) if wi<=j
 *
 *         For Backtracking:
 *         B[i,j] = j , if i is not in a optimal solution
 *         B[i,j] = j - wi, if i is in a optimal solution.
 *
 *@Input  : int no_of_items, int value[],int weight[],int W.
 *
 *@Output : N/A
 */
void Knap::fill_array(int no_of_items,int value[],int weight[], int W)
{
    int i,j;
    for(i = 0; i < no_of_items; i++)
    {
        V[i][0] = 0;
        B[i][0] = 0;
        for(j = 1; j <= W; j++)
        {
            if(weight[0] > j && i == 0)
            {
                V[0][j] = 0;
                B[0][j] = 0;
            }
            if(weight[0] <= j && i == 0)
            {
                V[0][j] = value[0];
                B[0][j] = j - weight[0];
            }
            if(weight[i] > j && i > 0)
            {
                V[i][j] = V[i-1][j];
                B[i][j] = j;
            }
            if(weight[i] <= j && i > 0)
            {
                int first = V[i-1][j];
                if((j-weight[i]) < 0)
                {
                    B[i][j] =j;
                    V[i][j] = V[i-1][j];

                }
                else
                {
                    int second = V[i-1][j-weight[i]]+value[i];
                    if(first <= second)
                    {
                        B[i][j] = j-weight[i];
                        V[i][j] = second;
                    }
                    else
                    {
                        B[i][j] = j;
                        V[i][j] = first;
                    }
                }

            }

        }
    }

/*    for(int i = 0; i < no_of_items; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }*/
}

/*
 *
 *@DESC    : Recursive Function for backtracking inorder to get maximum value
 *
 *@Input   : int i, int j // rows and cols respectively. 
 *
 *@Output  : N/A
 *
 */

void Knap::backtracking(int i, int j)
{
    if(i < 0)
    {
        return;
    }
    backtracking(i-1, B[i][j]);
    if(B[i][j] < j)
    {
        cout<<i+1<<" ";
    }
}
/*
 *
 *@DESC   : Function to take input from the user and creating class object called sack
 *         Then, calling backtracking function implemented above.
 *
 *@Input  : N/A
 *
 *@Output :N/A
 *
 */

void input()
{
    int N, K;
    cin >> N;
    cin >> K;
    value = new int[N]();
    weight = new int[N]();
    for (int i = 0; i < N; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
    Knap sack(N,K);
    sack.fill_array(N,value,weight,K);
    cout<<sack.V[N-1][K]<<endl;
    sack.backtracking(N-1, K);
    cout<<endl;
}
/*
 *
 *@DESC   : Main function to cal input function. 
 *
 *@Input  : N/A
 *
 *@Output : N/A
 */
int main()
{
    input();
    delete [] value;
    delete [] weight;
    return 0;
}
