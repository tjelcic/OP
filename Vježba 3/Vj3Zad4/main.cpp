#include <iostream>
#include "header.hpp"

using namespace std;

int main()
{
    int n;
    vector<int> vec1;
    cout << "Input the size of vector:" << endl;
    cin >> n;
    cout << "Input elements of vector" << endl;
    vectorInput(vec1, n);

    cout << "Elements by order of input:" << endl;
    vectorPrint(vec1);

    int i;
    cout << "Input the index to erase:"<< endl;
    cin >> i;

    eraseElement(vec1,i);
    cout << "Vector after erasing the element:" << endl;
    vectorPrint(vec1);
    return 0;
}
