// #include "Sales_data.h"
#include <iostream>
#include "Screen.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;

    return 0;
}