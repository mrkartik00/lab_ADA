#include <iostream>
#include <vector>
#include <iomanip> 
#include <cstdlib>
using namespace std;

// graph:
// https://www.desmos.com/calculator/vsp4kqh0iq

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100; 
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}

int partition(vector<int> &arr,int start,int end){
    int pivotIndex = start;

   while (start < end)
    {
        while (arr[start] <= arr[pivotIndex])
        {
            start++;
        }

        while (arr[end] > arr[pivotIndex])
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[end], arr[start]);
        }
    }

    swap(arr[pivotIndex], arr[end]);

    return pivotIndex;
}

int kthSmallestElement(vector<int> &arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int p = partition(arr, start, end);

        if (p == k - 1)
        {
            ans = p;
            break;
        }
        else if (p < k - 1)
        {
            start = p + 1;
        }
        else
        {
            end = p - 1;
        }
    }

    return ans;
}

void selectionSort(vector<int> &arr){
    for(int i=1;i <= arr.size();i++){
        int small = kthSmallestElement(arr,i+1);
        swap(arr[i],arr[small]);
      }
}
int main()
{
    vector<int> arr;

    for(int input_size=10;input_size<100;input_size = input_size +10){

    arr = randomnumbers(arr, input_size);

    clock_t start, end;

    start = clock();

    for (int i = 0; i < 100; i++)
        selectionSort(arr);

    end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    double average_time = time_taken / 100;

    cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    }

    return 0;
}

// Average Time taken by for input size 10 is : 0.000521 sec 
// Average Time taken by for input size 20 is : 0.00758 sec 
// Average Time taken by for input size 30 is : 0.05733 sec 
// Average Time taken by for input size 40 is : 0.25262 sec 
// Average Time taken by for input size 50 is : 0.79687 sec 
// Average Time taken by for input size 60 is : 2.15044 sec 
// Average Time taken by for input size 70 is : 5.08391 sec 
// Average Time taken by for input size 80 is : 10.26820 sec 
// Average Time taken by for input size 90 is : 19.34009 sec 
