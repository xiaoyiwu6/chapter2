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
    ifstream input(argv[1]);
    string tmp;
    deque<string> sdeq;
    while (input >> tmp)
        sdeq.push_back(tmp);
    for (auto itr = sdeq.cbegin(); itr != sdeq.cend(); itr++)
        cout << *itr << endl;

    return 0;
}
