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
    vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int>::size_type min_len = iv.size() / 2;
    vector<int>::iterator iter = iv.begin(),
                          mid = iv.begin() + min_len;
    vector<int>::difference_type count = 0;
    while (iter != mid)
    {
        if (*iter == 2)
        {
            ++count;
            iter = iv.insert(iter, 2 * 2);
            ++iter;
            mid = iv.begin() + min_len + count;
        }
        ++iter;
    }
    for (int i : iv)
        cout << i << endl;

    return 0;
}
