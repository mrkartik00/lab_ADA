#include <iostream>
#include <vector>
#include <iomanip> 
#include <cstdlib> 
using namespace std;

// graph:
// https://www.desmos.com/calculator/btjr6tylrq

void print(vector<int> &arr){
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

void quickSort(vector<int> &arr,int s,int e){
    if(s<e){
        int q = partition(arr,s,e);
        quickSort(arr,s,q-1);
        quickSort(arr,q+1,e);
    }
}

int main(){
    vector<int> arr; 

    for(int input_size=1;input_size<100;input_size = input_size +1){


    arr = randomnumbers(arr, input_size);

    clock_t start, end;

    start = clock();

    for (int i = 0; i < 100; i++)
        quickSort(arr,0,arr.size()-1);

    end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    double average_time = time_taken / 10;

    cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    }
    
    return 0;
}


// output:

// Average Time taken by for input size 1 is : 0.000001 sec 
// Average Time taken by for input size 2 is : 0.00001 sec 
// Average Time taken by for input size 3 is : 0.00003 sec 
// Average Time taken by for input size 4 is : 0.00006 sec 
// Average Time taken by for input size 5 is : 0.00013 sec 
// Average Time taken by for input size 6 is : 0.00026 sec 
// Average Time taken by for input size 7 is : 0.00035 sec 
// Average Time taken by for input size 8 is : 0.00056 sec 
// Average Time taken by for input size 9 is : 0.00085 sec 
// Average Time taken by for input size 10 is : 0.00122 sec 
// Average Time taken by for input size 11 is : 0.00164 sec 
// Average Time taken by for input size 12 is : 0.00227 sec 
// Average Time taken by for input size 13 is : 0.00302 sec 

// Average Time taken by for input size 14 is : 0.00397 sec 
// Average Time taken by for input size 15 is : 0.00546 sec 
