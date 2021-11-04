#include <iostream>
#include "header.hpp"

using namespace std;

int main()
{
	int n, a, b;
	vector<int> vec1, vec2, vec3;
	cout << "Input the size of vector:" << endl;
	cin >> n;
	cout << "Input elements of vector" << endl;
	vectorInput(vec1, n);
	cout << "Input the intervals for vector:" << endl;
	cin >> a;
	cin >> b;
	cout << "Input elements between intervals:" << endl;
	vectorIntervalInput(vec2, a, b);
	cout << "First array of vectors: " << endl;
	vectorPrint(vec1);
	cout << "Second array of vectors: " << endl;
	vectorPrint(vec2);
	vec3=newVector(vec1,vec2);
	cout << "Third array of vectors: " << endl;
	vectorPrint(vec3);
    return 0;
}
