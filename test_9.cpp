#include "Container.h"
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <array>
#include "Sales_data.h"
#include <fstream>
#include <deque>
#include <iostream>

using std::array;
using std::cout;
using std::deque;
using std::endl;
using std::forward_list;
using std::ifstream;
using std::list;
using std::string;
using std::vector;

void InsertStr(forward_list<string> &slist, const string &A, const string &B)
{
    auto prev = slist.before_begin(),
         curr = slist.begin();

    while (curr != slist.end())
    {
        if (*curr == A)
        {
            slist.insert_after(curr, B);
            return;
        }
        prev = curr;
        ++curr;
    }
    slist.insert_after(prev, B);
}

void SubAbbr(string &s, string oldVal, string newVal)
{
    if (oldVal.empty())
        return;
    auto olen = oldVal.size();
    auto nlen = newVal.size();
    auto iter = s.begin();

    while (iter <= s.end() - olen) //这里必须使用<=符号，!=号无法检查iter越过边界
    {
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        //遍历对比oldVal
        while (iter2 != oldVal.end() && *iter1 == *iter2)
        {
            iter1++;
            iter2++;
        }
        //中标
        if (iter2 == oldVal.end())
        {
            iter = s.erase(iter, iter + olen);
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += nlen; //指向下一个字符
        }
        else
            iter++;
    }
}

void SubAbbr2(string &s, string oldVal, string newVal)
{
    auto len = s.size(),
         olen = oldVal.size(),
         nlen = newVal.size();
    size_t ix = 0;

    if (oldVal.empty())
        return;

    while (ix <= len - olen)
    {
        size_t ix1 = ix,
               ix2 = 0;
        while (s[ix1] == oldVal[ix2] && ix2 < olen)
        {
            ix1++, ix2++;
        }
        if (ix2 == olen)
        {
            s = s.replace(ix, olen, newVal);
            ix += nlen;
        }
        else
            ix++;
    }
}

void Decorate(string &s, string prefix, string suffix)
{
    s.insert(s.begin(), 1, ' ');
    s.insert(s.begin(), prefix.begin(), prefix.end());
    s.append(" ");
    s.append(suffix);
}

void Decorate2(string &s, string prefix, string suffix)
{
    s.insert(0, 1, ' ');
    s.insert(0, prefix);
    s.insert(s.size(), 1, ' ');
    s.insert(s.size(), suffix);
}

void SplitChar(const string &s)
{
    string::size_type pos = 0;
    string decimal("0123456789");
    string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    while ((pos = s.find_first_of(decimal, pos)) != string::npos)
        cout << s[pos++] << " ";
    cout << endl;
    pos = 0;
    while ((pos = s.find_first_of(alphabet, pos)) != string::npos)
        cout << s[pos++] << " ";
    cout << endl;
}

void SplitChar2(const string &s)
{
    string::size_type pos = 0;
    string decimal("0123456789");
    string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    while ((pos = s.find_first_not_of(alphabet, pos)) != string::npos)
        cout << s[pos++] << " ";
    cout << endl;
    pos = 0;
    while ((pos = s.find_first_not_of(decimal, pos)) != string::npos)
        cout << s[pos++] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{

    string s = "ab2c3d7R4E6";
    SplitChar2(s);

    return 0;
}
