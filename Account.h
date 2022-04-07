#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    Account(const std::string &o, double a) : owner(o), amount(a) {}
    double balance() { return amount; }
    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

#endif