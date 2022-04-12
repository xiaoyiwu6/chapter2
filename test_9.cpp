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

int main(int argc, char const *argv[])
{
    forward_list<string> sflst = {"Hello", "!", "world", "!"};

    InsertStr(sflst, "Hello", "你好");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); ++curr)
        cout << *curr << " ";
    cout << endl;

    InsertStr(sflst, "!", "?");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); ++curr)
        cout << *curr << " ";
    cout << endl;

    InsertStr(sflst, "Bye", "再见");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); ++curr)
        cout << *curr << " ";
    cout << endl;

    return 0;
}
