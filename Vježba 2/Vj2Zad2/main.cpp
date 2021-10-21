#include <iostream>

using namespace std;

int& returnRef(int*arr, int n, int i)
{
    if (i<=n)
    {
        return arr[i];
    }
    return arr[0];
}

int main()
{
    int arr[]={8,17,1,37,28};
    int n=sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int i;
    cout << "Input the array index:" << endl;
    cin >> i;
    returnRef(arr,n,i)++;
    cout << "Element on index "<< i << " increased by 1: " << returnRef(arr,n,i) << endl;
    return 0;
}
