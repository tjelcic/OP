#include "header.hpp"
#include <algorithm>

using namespace std;

void vectorInput(vector<int> &arr, int n)
{
    int input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
}
void vectorIntervalInput(vector<int> &arr, int a, int b)
{
    int input;
    cin >> input;
    while ((input >= a) && (input <= b))
    {
        arr.push_back(input);
        cin >> input;
    }
}
void vectorPrint(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

vector<int> newVector (vector<int> &v1, vector<int> &v2)
{
    vector<int> v3;
    for (int i=0; i < v1.size(); i++)
    {
        if (!(find(v2.begin(), v2.end(), v1[i]) != v2.end()))
        {
            v3.push_back(v1[i]);
        }
    }
    return v3;
}
