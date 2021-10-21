#include <iostream>

using namespace std;

void findMaxMin(int *arr, int n, int&minn, int&maxx)
{
    int i;
    minn=arr[0];
    maxx=arr[0];

    for(i=1;i<n;i++)
    {
        if(arr[i]<minn)
            minn=arr[i];
        if(arr[i]>maxx)
            maxx=arr[i];
    }
}

int main()
{
    int arr[]={8,17,1,37,28,3};
    int n=sizeof(arr) / sizeof(arr[0]);
    int minn,maxx;
    findMaxMin(arr,n,minn,maxx);
    cout<<"Min:"<<minn<<endl;
    cout<<"Max:"<<maxx<<endl;
    return 0;
}
