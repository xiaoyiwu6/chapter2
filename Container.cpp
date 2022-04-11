#include "Container.h"

bool searchInt(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int num)
{
    while (begin!=end && *begin!=num)
        ++begin;
    if(begin!=end)
        return true;
    return false;
}

std::vector<int>::const_iterator searchIntSec(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int num)
{
    while(begin!=end && *begin!=num)
        ++begin;
    if(begin!=end)
        return begin;
    return end;
}