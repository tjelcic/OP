#include "stack.cpp"

#define SIZE 3

void print_stacks(Stack<int>&, Stack<double>&, Stack<char>&);

int main()
{

    Stack<int> intStack(SIZE);
    Stack<double> doubleStack(SIZE);
    Stack<char> charStack(SIZE);

    intStack.push(1);
    intStack.push(4);
    intStack.push(10);
    intStack.push(15);

    doubleStack.push(2.58);
    doubleStack.push(11.25);

    charStack.push('t');
    charStack.push('e');
    charStack.push('a');

    print_stacks(intStack, doubleStack, charStack);

    intStack.pop();
    doubleStack.pop();
    doubleStack.pop();
    doubleStack.pop();

    print_stacks(intStack, doubleStack, charStack);

    return 0;
}

void print_stacks(Stack<int>& is, Stack<double>& ds, Stack<char>& cs)
{
    is.print();
    ds.print();
    cs.print();
}
