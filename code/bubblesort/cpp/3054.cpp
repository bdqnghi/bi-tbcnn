#include <iostream>

using namespace std;

void bubblesort(int v[], int n)
{
    int tmp;
    bool schimbare;

    do
    {
        schimbare = false;

        for (int i = 0; i < n - 1; i++)
            if (v[i] > v[i + 1]) /// v[i] < v[i + 1] pentru ordine descrescatoare
            {
                tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                schimbare = true;
            }
    } while (schimbare);
}

int main()
{
    int n, v[100];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    bubblesort(v, n);

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}
