/* Code by Pikulin Ilya, Mar 2015 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

void quicksort( int a[], int N );

int main( int argc, char* argv[] )
{
    int a[] = { 28, 42, 11, 19, 12, 19, 28, 1, 6, 17, 34, 48, 22, 41, 24, 27, 11, 41, 14, 40, 6, 46, 38, 47, 25, 41 };
    quicksort( a, sizeof( a ) / sizeof( a[0] ) - 1 );
    for ( int i = 0; i < sizeof( a ) / sizeof( a[0] ); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

void quicksort( int a[], int N )
{
    int l = 0, r = N; 
    int temp, p; 
    p = a[ N / 2 ];

    do
    {
        while ( a[l] < p) 
        {
            ++l;
        }
        while ( a[r] > p)
        {
            --r;
        }

        if ( l <= r )
        {
            temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            ++l;
            --r;
        }
    } while ( l <= r );

    if ( r > 1 )
    {
        quicksort( a, r );
    }
    if ( N > l )
    {
        quicksort( a + l, N - l );
    }
}
