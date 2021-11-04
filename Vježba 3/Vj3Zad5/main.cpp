#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int substringCount (string &s, string &subs)
{
    int cnt = 0;
	int i = 0;
	for(;;)
    {
        i = s.find(subs, i);
        if (i == string::npos)
            break;
        cnt++;
        i += subs.size();
    }
	return cnt;
}

int main()
{
    string s = "this is a string, and this is not";
    string subs = "this";
    cout << "Substring " << subs << " occurs " << substringCount (s,subs) << " times." << endl;
    return 0;
}
