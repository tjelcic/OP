#include <iostream>

using namespace std;

int findMaxEl (int arr[],int n)
{
    if (n==1)
        return arr[0];
    return max(arr[n-1], findMaxEl(arr,n-1));
}

int findMinEl (int arr[],int n)
{
    if(n==1)
        return arr[0];
    return min(arr[n-1], findMinEl(arr,n-1));
}

int main()
{
    int arr[]={2,5,1,28,17};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Max element:"<<findMaxEl(arr,n)<<endl;
    cout<<"Min element:"<<findMinEl(arr,n)<<endl;
}
