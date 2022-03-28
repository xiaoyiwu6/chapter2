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

char &get_char(string &str, size_t ix)
{
    return str[ix];
}

int &get(int *array, int index)
{
    return array[index];
}

/*
迭代器是右值，因为迭代器返回的是临时量，
如果要引用形参必须加const来初始化，
但是这样一来就没办法++或者--
*/
void print_vec(const vector<int> &ivec, vector<int>::iterator beg)
{
    if (beg == ivec.end())
    {
        cout << endl;
        return;
    }
    cout << *beg++ << " ";
    print_vec(ivec, beg);
}

inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1),
                            const_cast<const string &>(s2));
    return const_cast<string &>(r);
}

int plus(const int a, const int b) { return a + b; }
int minus(const int a, const int b) { return a - b; }
int mutiple(const int a, const int b) { return a * b; }
int divide(const int a, const int b)
{
    try
    {
        if (b == 0)
            throw domain_error("b cannot be zero.");
        return a / b;
    }
    catch (const domain_error &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}

void base_operation(const int a, const int b)
{
    using PF = int (*)(const int, const int);

    vector<PF> fvec;
    fvec.push_back(plus);
    fvec.push_back(minus);
    fvec.push_back(mutiple);
    fvec.push_back(divide);

    for (auto F : fvec)
        cout << F(a, b) << endl;
}