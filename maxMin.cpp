#include<iostream>
using namespace std;

MinMax(A, n){
    int min = A[0];
    int max = A[0];
    for(int i = 1; i < n; i++){
        if(max < A[i])
            max = A[i];
        else if(min > A[i])
            min = A[i];
    }
    return (min, max);
}
int main(){
int arr[10]={1,2,3,4,5,6,7,8,9,0}
MinMax(arr, 10)
return 0;
}
