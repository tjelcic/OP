#include "exception.h"
#include "functions.h"

int main()
{
    vector<int> numbers;

    try
    {
        read_file(numbers);
        count_greater(numbers);
        min_max_el(numbers);
        cout << endl << "Number of numbers before deleting: " << numbers.size();
        delete_lower(numbers);
        cout << "\t After: " << numbers.size() << endl;
        sort_descending(numbers);
        cout << endl << "Numbers sorted in descending order: ";
        ostream_iterator<int> os(cout << endl, "\n");
        copy(numbers.begin(), numbers.end(), os);
    }
    catch (FileNotFound error)
    {
        error.Error();
    }

    return 0;
}
