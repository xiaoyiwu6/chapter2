#ifndef CHAPTER6_H
#define CHAPTER6_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::initializer_list;
using std::range_error;
using std::string;
using std::vector;
using std::domain_error;

int fact(int);
string::size_type find_char(const string &, const char, string::size_type &);
int max(const int, const int *);
void switch_ptr(int *&, int *&);
void print(const int *, const int *);
void error_msg(initializer_list<string>);
int sum(initializer_list<int>);
char &get_char(string &, size_t);
int &get(int *, int);
void print_vec(const vector<int> &, vector<int>::iterator);
inline const string &shorterString(const string &, const string &);
string &shorterString(string &, string &);
void base_operation(const int, const int);

#endif