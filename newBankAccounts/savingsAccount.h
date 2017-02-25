/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Savings account derived class header
* February 5, 2017 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "bankAccount.h"

const double DEFAULT_INTEREST_RATE_SAVINGS = 0.5;

class savingsAccount :
	public bankAccount
{
protected:
	double interestRate;

public:
	savingsAccount(string n, string acctNum, double bal, double intRate = DEFAULT_INTEREST_RATE_SAVINGS);
	~savingsAccount();
	double getInterestRate() const;
	void setInterestRate(double intRate);
	string withdraw(double amount);
	string postInterest();
	virtual string createMonthlyStatement();
	string savingsAccount::print() const;
};

#endif