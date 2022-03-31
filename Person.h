#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
    friend std::ostream &print(std::ostream &, const Person &);
    friend std::istream &read(std::istream &, Person &);

private:
    std::string name;
    std::string address;

public:
    // constructor
    Person() = default;
    Person() : name(""), address("") {}
    Person(std::istream &is) { read(is, *this); }
    Person(const std::string &n, const std::string &a) : name(n), address(a) {}
    // menber functions
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
};

std::ostream &print(std::ostream &os, const Person &people)
{
    os << people.name << " " << people.address;
    return os;
}

std::istream &read(std::istream &is, Person &people)
{
    is >> people.name >> people.address;
    return is;
}

#endif