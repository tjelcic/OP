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

void vectorPrint(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}
