#include "Animal.h"

using namespace std;

int Tarantula::legs()
{
    return num_leg;
}
int Sparrow::legs()
{
    return num_leg;
}
int Cockroach::legs()
{
    return num_leg;
}
char* Tarantula::name()
{
    char* name1 =_strdup(_name);
    return name1;
}
char* Cockroach::name()
{
    char* name1 = _strdup(_name);
    return name1;
}
char* Sparrow::name()
{
    char* name1 = _strdup(_name);
    return name1;
}
Count::Count()
{
    arr = new Animal* [10];
}
void Count::add(Animal* A1)
{
    arr[sz] = A1;
    sz++;
}
void Count::sum()
{
    for (int i = 0; i < sz; i++)
    {
        cout << "Animal added: " << arr[i]->name() << endl;
        num += arr[i]->legs();
    }
    cout << "Total leg count: " << num << endl;
}
