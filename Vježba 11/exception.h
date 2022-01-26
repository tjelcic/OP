#include <iostream>

using namespace std;

class Exception
{
public:
    virtual void Error() = 0;
};

class FileNotFound : public Exception
{
public:
    void Error()
    {
        cout << "File Not Found." << endl << endl;
    }
};
