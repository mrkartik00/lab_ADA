#include<iostream>
using namespace std;

void Min(int arr[][], int start, int end, int &min)
{
    int n;
    int arr[0][0]=arr[start];
    int arr[n][n]=arr[end];
    if (start == end)
    {
     min = arr[0][0];
    }
    else if (start == end - 1)
    {
        if (arr[0][0] < arr[n][n])
        {
            min = arr[0][0];
        }
        else
        {
            min = arr[n][n];
        }
    }
    else
    {
        int mid = (start + end)/2;
        int  min1;
        Min(arr, start, mid, min);
        Min(arr, mid + 1, end, min1);
        if (min > min1)
            min = min1;
    }
}
void near(){
    for(int i=0; i<n;i++){
        
    }
}
void Prims(E, cost, n, t){
    
    for(int i=1; i<n; i++){
        if(cost[i,k]<cost[i,l]){
            near[i]=k;
        }
        else{
            near[i]=l;
        }
        near[k]=near[l]=0;
        min.cost=cost[k,l];
    }
    for(int j=2;j<n-1; j++){
        
        t[j,1]=u;
        t[j,2]=near[u];
        t[1,1]=k;
        t[1,2]=l;
        
        min.cost=minimum+cost[u,near[u]];
        near[u]=0;
    }
    for(int K=0; K<n; K++){
        near[w]!=0 && cost[w,near[w]]>cost[u,w];
        near[w]=u;
    }
}
