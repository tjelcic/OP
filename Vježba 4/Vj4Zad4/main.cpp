#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v)
{
	vector<int>::iterator i = v.begin();
	vector<int>::iterator j = v.end();

	while (i != j)
    {
		cout << *i << " ";
		i++;
	}
	cout << endl;
}

vector<int>& stuffingBit(vector<int> v, vector<int>& stuff)
{
    int j = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v.at(i) == 0)
        {
            stuff.push_back(v[i]);
            j = 0;
        }
        else if(v.at(i) == 1)
        {
            if(j == 5)
            {
                stuff.push_back(0);
                stuff.push_back(v.at(i));
                j = 0;
            }
            else
                stuff.push_back(v[i]);
            j++;
        }
    }
    return stuff;
}

vector<int>& unstuffingBit(vector<int>& stuff)
{
    int j = 0;
    int len = stuff.size();
    for(int i = 0; i < len; i++)
    {
        if(stuff[i] == 1)
            j++;
        if(j == 5)
        {
            stuff.erase(stuff.begin() + i + 1);
            j = 0;
        }
    }
    return stuff;
}

int main()
{
	vector<int> v;
	int tmp;
	cout << "Input binary digits:" << endl;
	while (true)
    {
		cin >> tmp;
		if ((tmp == 0) || (tmp == 1))
			v.push_back(tmp);
		else
            break;
	}
	cout << "Your input:" << endl;
	printVector(v);
	vector<int> stuffed;
 	stuffingBit(v, stuffed);
 	cout << "Input after bit stuffing:" << endl;
	printVector(stuffed);
	unstuffingBit(stuffed);
	cout << "Input after bit unstuffing:" << endl;
	printVector(stuffed);
	return 0;
}
