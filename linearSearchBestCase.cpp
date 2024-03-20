#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std:: chrono;
using std::ofstream;
using namespace std;

int* genlist(int arr[],int k)
{
  int val;
    for(int i=1;i<=k;i++)
    {
     arr[i]=rand();
    }
    return arr;
}

int search(int array[], int n, int x) {   
  for (int i = 0; i <=n; i++)
    if (array[i] == n)
      return i;
  return -1;
}

void timecomp(int arr[])
{
for(int i=1;i<=100000;i=i+1)
{
    arr=genlist(arr,i);
auto start=high_resolution_clock :: now();
for(int j=1;j<=10;j++)
{
    search(arr,0,i);
}
auto stop=high_resolution_clock :: now();
auto duration = duration_cast<microseconds>(stop - start)/10;
float dur=duration.count();
cout<<i<<" " << dur<<endl;
}
}
int main() {  
   int*arr=new int[1000];
     timecomp(arr);
     return 0;
}
