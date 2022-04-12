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
    forward_list<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = ivec.begin();
    auto prev = ivec.before_begin();
    auto end = ivec.end();
    while (iter != end)
    {
        if (*iter & 1)
        {
            iter = ivec.insert_after(prev, *iter);
            iter++;iter++;
            prev++;prev++;
        }
        else
            iter = ivec.erase_after(prev);
    }
    for (int i : ivec)
        cout << i << endl;

    return 0;
}
