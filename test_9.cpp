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

int main(int argc, char const *argv[])
{
    forward_list<int> i_fl{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto prev = i_fl.before_begin(),
         curr = i_fl.begin();

    while (curr != i_fl.end())
        if (*curr & 1)
            curr = i_fl.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }

    return 0;
}
