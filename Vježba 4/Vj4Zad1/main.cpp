#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void removeSpace(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isspace(str[i]) && isspace(str[i + 1]))
		{
			str.erase(i, 1);
			i--;
		}
		if (isspace(str[i]) && ispunct(str[i + 1]))
			str.erase(i, 1);

		if (ispunct(str[i]) && isalpha(str[i + 1]))
			str.insert(str.begin()+i+1,' ');
	}
}

int main()
{
    string sen;
    cout << "Input a sentence:" << endl;
    getline (cin, sen);
    removeSpace(sen);
    cout << sen;
    return 0;
}
