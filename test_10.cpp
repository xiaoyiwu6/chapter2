#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <numeric>
#include <iterator>
#include "Chapter10.h"
#include <sstream>
#include <fstream>
#include "Sales_data.h"

using std::accumulate;
using std::back_inserter;
using std::begin;
using std::cin;
using std::copy;
using std::count;
using std::cout;
using std::end;
using std::endl;
using std::fill_n;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::list;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;

auto f = [](int a, int b)
{ return a > b; };

int sum(int a)
{
    auto f = [a](int b)
    { return a > b; };
    return f(2);
}

int main(int argc, char const *argv[])
{
    cout << sum(3) << endl;

    return 0;
}
