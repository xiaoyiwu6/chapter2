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

int main(int argc, char const *argv[])
{

    string s = "tho thru tho!";
    SubAbbr(s, "thru", "through");
    cout << s << endl;

    SubAbbr(s, "tho", "though");
    cout << s << endl;

    SubAbbr(s, "through", "");
    cout << s << endl;

    return 0;
}
