#include "vector.hpp"

using namespace std;

void MyVector::vector_new (size_t sz)
{
    size=sz;
    capacity=1;
    arr = new int[capacity];
}

void MyVector::vector_delete()
{
    delete [] arr;
}

void MyVector::vector_push_back(int n)
{
    if (size == capacity)
    {
        int* temp = new int[capacity*2];
        for (int i = 0; i < capacity; ++i)
        {
            temp[i] = arr[i];
        }
        capacity *= 2;
        delete [] arr;
        arr = temp;
    }
    arr[size] = n;
    size++;
}

void MyVector::vector_pop_back()
{
    size--;
    int* temp = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
}

int& MyVector::vector_front()
{
    return arr[0];
}

int& MyVector::vector_back()
{
    return arr[size - 1];
}

size_t MyVector::vector_size()
{
    return size;
}

void MyVector::print_vector()
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
