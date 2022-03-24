#include <iostream>
#include <vector>
#include <cctype>
#include <stdexcept>
#include "Chapter6.h"

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::domain_error;
using std::end;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    cout << sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;

    return 0;
}
