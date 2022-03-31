#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.h"

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen *>::size_type;
    void clear(ScreenIndex);
    Window_mgr &push(Screen *&sc)
    {
        scvec.push_back(sc);
        return *this;
    }

private:
    std::vector<Screen *> scvec;
};

void Window_mgr::clear(ScreenIndex si)
{
    Screen *&sc = scvec[si];
    sc->contents = std::string(sc->height * sc->width, ' ');
}

#endif