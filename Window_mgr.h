#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include "Screen.h"
#include <vector>

class Window_mgr
{
private:
    std::vector<Screen> scvec{Screen(24, 80, ' ')}; 
};

#endif