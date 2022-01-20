#include <iostream>

using namespace std;

#define MAXSIZE 30

template<typename T>
class Stack
{
private:
    T* arr;
    unsigned int capacity;
    int top;
public:
    Stack(unsigned int = MAXSIZE);

    void push(T);
    void pop();
    void get_top() const;
    bool is_empty() const;
    bool is_full() const;
    void print() const;

    ~Stack();
};
