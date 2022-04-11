#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

//不能使用引用，除非实参是定义的变量，不能是临时值，如果使用引用需要常量引用来接受临时值，但是迭代器需要改变值
bool searchInt(std::vector<int>::const_iterator, std::vector<int>::const_iterator, int);
std::vector<int>::const_iterator searchIntSec(std::vector<int>::const_iterator, std::vector<int>::const_iterator, int);

#endif