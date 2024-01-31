#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace std::chrono;
using std::ofstream;
using namespace std;

int horner(int poly[], int n, int x)
{
    int result = poly[0];
    for (int i = 1; i < n; i++)
        result = result * x + poly[i];
    return result;
}

int *genlist(int arr[], int k)
{
    int val;
    for (int i = 1; i <= k; i++)
    {

        arr[i] = rand();
    }
    return arr;
}

void timecomp(int arr[])

{

    for (int i = 100; i <= 100000; i = i + 100)
    {
        arr = genlist(arr, i);

        auto start = high_resolution_clock ::now();

        for (int j = 1; j <= 10; j++)
        {
            horner(arr, i, j);
        }

        auto stop = high_resolution_clock ::now();

        auto duration = duration_cast<microseconds>(stop - start) / 10;
        float dur = duration.count();

        cout << i << " " << dur << endl;
    }
}

int main()
{
    int *arr = new int[10000000];

    timecomp(arr);
    // 	int poly[] = {2, -6, 2, -1};
    // 	int x = 3;
    // 	int n = sizeof(poly)/sizeof(poly[0]);
    // 	cout << "Value of polynomial is " << horner(poly, n, x);
    return 0;
}