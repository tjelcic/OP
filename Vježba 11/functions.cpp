#include "exception.h"
#include "functions.h"

void read_file(vector<int>& nums)
{
    ifstream in_file("numbers.txt");


    if (!in_file.is_open())
    {
        in_file.close();
        throw FileNotFound();
    }

    istream_iterator<int> in_stream(in_file), eos;
    copy(in_stream, eos, back_inserter(nums));
}

bool check_greater(int num)
{
    return (num > 500);
}

void count_greater(vector<int> nums)
{
    cout << count_if(nums.begin(), nums.end(), check_greater) << " numbers are greater than 500." << endl;
}

void min_max_el(vector<int> nums)
{
    auto result = minmax_element(nums.begin(), nums.end());

    cout << endl << "Min element: " << *result.first << "\t Max element: " << *result.second << endl;
}

bool check_lower(int i)
{
    return (i < 300);
}

void delete_lower(vector<int>& nums)
{
    nums.erase(remove_if(nums.begin(), nums.end(), check_lower), nums.end());
}

void sort_descending(vector<int>& nums)
{
    sort(nums.begin(), nums.end(), greater<int>());
}
