#include <iostream>
// #include "Screen.h"
// #include "Window_mgr.h"
// #include "Sales_data.h"
// #include "Debug.h"
#include "Account.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
// using std::vector;
// using std::string;

int main(int argc, char const *argv[])
{
    Account LEO("Leonardwoo", 4709.);
    cout << LEO.balance() << endl;
    LEO.calculate();
    cout << LEO.balance() << endl;

    return 0;
}