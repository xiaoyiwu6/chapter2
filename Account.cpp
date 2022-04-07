#include "Account.h"

double Account::initRate(){
    return .0225;
}

double Account::interestRate = initRate();

void Account::rate(double newRate) 
{
    interestRate = newRate; 
}

