#include <iostream>
#include "Screen.h"
#include "Window_mgr.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char const *argv[])
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    Window_mgr win;
    /*
    win.push(&myScreen).clear(0); 错误。
    因为引用不能绑定临时值，
    &myScreen直接给出了一个地址的临时值交给实参引用绑定，
    此时实参需要机上const
    */
    Screen *ms_ptr = &myScreen;
    win.push(ms_ptr).clear(0);
    myScreen.display(cout);
    cout << endl;

    return 0;
}