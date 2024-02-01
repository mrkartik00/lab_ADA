#include <iostream>
using namespace std;

void merge(int arr1[], int arr2[], int arr3[], int n, int m)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }

        if (arr1[i] > arr2[j])
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        else
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
    }

    while (i < n)
    {
        arr2[k] = arr1[i];
        k++;
        i++;
    }

    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
};

void print(int arr3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[5] = {10, 11, 12, 13, 14};
    int arr3[10] = {0};

    merge(arr1, arr2, arr3, 5, 5);

    print(arr3, 10);
}