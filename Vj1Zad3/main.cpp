#include <iostream>

using namespace std;

typedef struct
{
    int maxe;
    int mine;
}maxandmin;

maxandmin findMaxMin (int arr[], int n)
{
    int i;
    int maxe=arr[0];
    int mine=arr[0];

    for (i=1;i<n;i++)
    {
        if (arr[i]>maxe)
            maxe=arr[i];
        if (arr[i]<mine)
            mine=arr[i];
    }

    maxandmin m1={maxe,mine};

    return m1;
}

int main()
{
    int arr[]={8,17,1,35,28,3};
    int n=sizeof(arr) / sizeof(arr[0]);
    maxandmin m2=findMaxMin(arr,n);
    cout<<"Max:"<<m2.maxe<<endl;
    cout<<"Min:"<<m2.mine<<endl;
}
