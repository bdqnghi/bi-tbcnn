using namespace std;
#include <iostream>
void bubblesort(int element[], int N);

int main(int argc, char *argv[])
{
    int element[100],N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> element[i];
    bubblesort(element, N);
    for (int i = 0; i < N; i++)
        cout << element[i] << endl;
    return 0;
}

void bubblesort(int element[],int N)
{
    int temp;
    for(int i = 1; i < N; i++)
        for(int j = 0; j < N-1; j++)
            if(element[j] > element[j + 1])
                {
                    temp = element[j];
                    element[j] = element[j + 1];
                    element[j + 1] = temp;
                }
}
