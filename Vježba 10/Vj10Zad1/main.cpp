#include "template.h"

#define SIZE 6
#define SORT "Sorted arr: "
#define NOTSRT "Not sorted arr: "

void test(int*, float*, double*, char*, char*);

int main()
{

    int intArr[SIZE] = { 10, 25, 11, 2, 18, 4 };
    float floatArr[SIZE] = { 7.5, 18.9, 25.4, 2.9, 30.7, 0.8 };
    double doubleArr[SIZE] = { 14.8, 15.22, 9.33, 28.15, 5.44, 1.12 };
    char charArr[SIZE] = { 's', 'o', 'r', 't', 'e', 'd' };
    char charCaseArr[SIZE] = { 's', 'O', 'r', 'T', 'e', 'D' };

    test(intArr, floatArr, doubleArr, charArr, charCaseArr);

    return 0;
}

void test(int* intArr, float* floatArr, double* doubleArr, char* charArr, char* charCaseArr)
{

    print(intArr, SIZE,  NOTSRT);
    print(floatArr, SIZE,  NOTSRT);
    print(doubleArr, SIZE,  NOTSRT);
    print(charArr, SIZE,  NOTSRT);
    print(charCaseArr, SIZE, NOTSRT);
    cout << endl;

    sort(intArr, SIZE);
    sort(floatArr, SIZE);
    sort(doubleArr, SIZE);
    sort(charArr, SIZE);
    sort(charCaseArr, SIZE);

    print(intArr, SIZE, SORT);
    print(floatArr, SIZE, SORT);
    print(doubleArr, SIZE, SORT);
    print(charArr, SIZE, SORT);
    print(charCaseArr, SIZE, SORT);
}
