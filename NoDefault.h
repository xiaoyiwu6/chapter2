#ifndef NOEFAULT_H
#define NOEFAULT_H

#include <string>

class NoDefault
{
private:
    std::string s;
    std::string s2;
public:
    NoDefault(const std::string&str):s(str){}
};

#endif