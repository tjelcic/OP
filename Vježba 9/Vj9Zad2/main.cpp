#include <iostream>
#include "Animal.h"

using namespace std;

int main()
{
    Tarantula t1;
    Sparrow v1;
    Cockroach z1;
    Animal* p1 = &t1;
    Animal* p2 = &v1;
    Animal* p3 = &z1;
    Count c;
    c.add(p1);
    c.add(p2);
    c.add(p3);
    c.sum();
    return 0;
}
