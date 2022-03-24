#include "Chapter6.h"

int fact(int val)
{
    try
    {
        if (val <= 0)
            throw range_error("Value cannot be less or equal than zero.");
    }
    catch (const range_error &e)
    {
        cerr << e.what() << '\n';
    }
    int factor = 1;
    while (val)
        factor *= val--;

    return factor;
}

string::size_type find_char(const string &s, const char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }

    return ret;
}

int max(const int A, const int *B)
{
    return A > *B ? A : *B;
}

void switch_ptr(int *&A, int *&B)
{
    int *temp = A;
    A = B;
    B = temp;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << ' ';
    cout << endl;
}

void error_msg(initializer_list<string> il)
{
    for (const string &s : il)
        cout << s << " ";
    cout << endl;
}

int sum(initializer_list<int> il)
{
    int sum = 0;
    for (const int &i : il)
        sum += i;
    return sum;
}