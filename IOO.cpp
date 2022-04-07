#include "IOO.h"

std::istream &process_input(std::istream &is)
{
    std::string str;
    std::string temp;
    while (!is.eof())
    {
        is >> temp;
        str += temp;
    }
    std::cout << str << std::endl;
    is.clear(is.rdstate() & ~is.eofbit);
    
    return is;
}