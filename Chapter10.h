#ifndef CHAPTER9_H
#define CHAPTER9_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "Sales_data.h"
#include <fstream>

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

void printStr(const std::vector<std::string> &words)
{
    for (const auto &str : words)
        std::cout << str << " ";
    std::cout << std::endl;
}

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

// Ex 10.9
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

// Ex 10.12
void sortSales(const char *path)
{
    std::ifstream input;
    input.open(path);
    Sales_data tmp;
    std::vector<Sales_data> svec;

    while (read(input, tmp))
        svec.push_back(tmp);

    std::sort(svec.begin(), svec.end(), [](const Sales_data &lhs, const Sales_data &rhs)
              { return lhs.isbn() < rhs.isbn(); });

    for (const auto &item : svec)
    {
        print(std::cout, item);
        std::cout << "\n";
    }
}

// Ex 10.13
bool lengthSTFive(const std::string &s)
{
    return s.size() >= 5;
}
void partStr(std::vector<std::string> &words)
{
    // auto end_part = std::partition(words.begin(), words.end(), [](const std::string &s)->bool{return s.size()>=5;}); lambda表达式
    auto end_part = std::partition(words.begin(), words.end(), lengthSTFive);
    for (const auto &word : words)
        std::cout << word;
    std::cout << "\n";
}

// Ex 10.16
std::string make_plural(size_t count, std::string a, std::string b)
{
    return count > 1 ? a + b : a;
}
void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), [](const std::string &s1, const std::string &s2) -> bool
                     { return s1.size() < s2.size(); });
    auto wc = std::stable_partition(words.begin(), words.end(), [sz](const std::string &s) -> bool
                           { return s.size() < sz; });
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s")
              << " of length " << sz << " or longer" << std::endl;

    for_each(wc, words.end(), [](const std::string &s)
             { std::cout << s << " "; });

    std::cout << std::endl;
}

#endif