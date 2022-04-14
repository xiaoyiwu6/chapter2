#ifndef CHAPTER9_H
#define CHAPTER9_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

void printStr(const std::vector<std::string> &words)
{
    for (const auto &str : words)
        std::cout << str << " ";
    std::cout << std::endl;
}

void elimDups(std::vector<std::string> &words)
{
    printStr(words);
    std::sort(words.begin(), words.end());
    printStr(words);
    auto end_unique = std::unique(words.begin(), words.end());
    printStr(words);
    words.erase(end_unique, words.end());
    printStr(words);
}

void elimStrDups(std::string &str)
{
    std::vector<std::string> svec;
    std::istringstream input(str);
    std::string tmp;

    while (input >> tmp)
        svec.push_back(tmp);
    input.clear();

    elimDups(svec);
}

#endif