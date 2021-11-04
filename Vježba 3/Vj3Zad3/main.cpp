#include <iostream>
#include "header.hpp"
#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>

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

	sort(vec1.begin(),vec1.end());
	cout << "Elements sorted in ascending order:" << endl;
	vectorPrint(vec1);

	vec1.insert(vec1.begin(),0);
	cout << "Zero in front of smallest element:" << endl;
	vectorPrint(vec1);

	int sum = accumulate(vec1.begin(), vec1.end(), 0);
	vec1.insert(vec1.end(),sum);
	cout << "Sum of elements behind the biggest element" << endl;
	vectorPrint(vec1);

    return 0;
}
