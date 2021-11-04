#include "header.hpp"

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
