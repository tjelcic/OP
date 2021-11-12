#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> sortReverseStrings ()
{
    vector<string> vec;
    cout << "Input the number of strings:" << endl;
    int n;
    cin >> n;
    string str;
    cout << "Input the strings:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        vec.push_back(str);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        reverse(vec[i].begin(), vec[i].end());
    }
    sort(vec.begin(), vec.end());
    return vec;
}

int main()
{
    vector<string> vec = sortReverseStrings();
    cout << "Strings reversed and sorted in ascending order:" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}
