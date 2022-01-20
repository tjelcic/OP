#include <iostream>

using namespace std;

template <typename T>
void sort(T* items, int count)
{
    for (int i = 1; i < count; ++i)
    {
        for (int j = count - 1; j >= i; --j)
        {
            if (items[j - 1] > items[j])
            {
                swap(items[j - 1], items[j]);
            }
        }
    }
}

template <>
void sort(char* items, int count)
{
    for (int i = 1; i < count; ++i)
    {
        for (int j = count - 1; j >= i; --j)
        {
            if (tolower(items[j - 1]) > tolower(items[j]))
            {
                swap(items[j - 1], items[j]);
            }
        }
    }
}

template<typename T>
void print(T obj, int count, string str)
{
    cout << str;
    for (int i = 0; i < count; ++i)
    {
        cout << obj[i] << " ";
    }
    cout << endl;
}
