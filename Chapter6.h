#ifndef CHAPTER6_H
#define CHAPTER6_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <initializer_list>

using std::cerr;
using std::cout;
using std::endl;
using std::range_error;
using std::string;
using std::initializer_list;

int fact(int);
string::size_type find_char(const string &, const char, string::size_type &);
int max(const int, const int *);
void switch_ptr(int *&, int *&);
void print(const int *, const int *);
void error_msg(initializer_list<string>);
int sum(initializer_list<int>);

#endif