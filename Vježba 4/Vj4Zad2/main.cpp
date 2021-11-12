#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

bool VowelTest(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

string PigLatin(string sen)
{
    string tmp, sub;
    int pos = 0;
    int pos_end = sen.find(' ', pos + 1);
    int cnt = 0;
    int i = 0;

    if (VowelTest(sen.at(pos)))
        tmp.append(sen.substr(pos, (pos_end - pos)) + "hay ");
    else if (!VowelTest(sen.at(pos)))
    {
        sub = sen.substr((pos), (pos_end - pos));
        while (!VowelTest(sub.at(cnt)))
            cnt++;
        tmp.append(sub.substr(cnt, (sub.length() - cnt)));
        tmp.append(sub.substr(0, cnt) + "ay ");
        cnt = 0;
    }

    while (i != sen.npos)
    {
        pos = sen.find(' ', i);
        pos_end = sen.find(' ', pos + 1);
        i = pos_end;

        if (VowelTest(sen.at(pos + 1)))
            tmp.append(sen.substr(pos, (pos_end - pos)) + "hay ");
        else if (!VowelTest(sen.at(pos + 1)))
        {
            sub = sen.substr((pos + 1), (pos_end - pos) - 1);
            while (!VowelTest(sub.at(cnt)))
                cnt++;
            tmp.append(sub.substr(cnt, (sub.length() - cnt)));
            tmp.append(sub.substr(0, cnt) + "ay ");
            cnt = 0;
        }
    }
    return tmp;
}

int main()
{
    vector<string> vec;
    string sentence;
    int n = 0;

    cout << "Input sentences, Ctrl + Z for end of input" << endl;
    while (getline(cin, sentence))
    {
        vec.push_back(sentence);
        n++;
    }

    vector<string>::iterator it = vec.begin();
    int cnt = 0;
    while (it != vec.end())
    {
        cnt++;
        it++;
    }
    srand (time(NULL));
    int r = rand() % cnt;

    sentence = PigLatin(vec.at(r));
    cout << endl << "Randomly selected sentence: " << sentence << endl;
    return 0;
}
