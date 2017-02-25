/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* High interest savings account derived class header
* February 19, 2017 */

#ifndef HIGHINTERESTSAVINGS_H
#define HIGHINTERESTSAVINGS_H

#include <string>
#include <iostream>
#include "savingsAccount.h"
using namespace std;

static const double MINIMUM_BALANCE = 500.00;
static const double INTEREST_RATE = 1.05;

class highInterestSavings :
	public savingsAccount
{
protected:
	double minimumBalance;

public:
	highInterestSavings(string n, string acctNumber, double bal);
	highInterestSavings(string n, string acctNumber, double bal, double intRate, double minBalance);
	~highInterestSavings();
	double getMinimumBalance();
	bool verifyMinimumBalance(double amount);
	virtual string withdraw(double amount);
	virtual string createMonthlyStatement();
	virtual string print();
};

#endif