#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace std::chrono;
using std::ofstream;
using namespace std;

void selectionsort(int arr[], int n)
{
    int i, j, min, t;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
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
void store(int i, float avg)
{
    ofstream file("tc.txt");
    file << i << " " << avg;
    file.close();
}
void timecomp(int arr[])
{
    for (int i = 1000; i <= 100000; i = i + 1000)
    {
        arr = genlist(arr, i);
        auto start = high_resolution_clock ::now();
        for (int j = 1; j <= 10; j++)
        {
            selectionsort(arr, i);
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
    return 0;
}