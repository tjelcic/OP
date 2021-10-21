#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
bool flag;
cout << "unesi " << true << " - " << false << endl;
cin >> flag;
cout << noboolalpha << flag <<endl;
int a = 123;
cout << "hex " << hex << a << endl;
cout << "dec " << dec << a << endl;
cout << "oct " << oct << a << endl;
double pi = 3.141592;
cout << "pi = " << fixed;
cout << setprecision(7) << setw(20) << setfill('*');
cout << pi << endl;
}
