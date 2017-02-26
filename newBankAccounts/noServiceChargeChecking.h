/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* No service charge checking account derived class header
* February 19, 2017 */

#ifndef NOSERVICECHARGECHECKING_H
#define NOSERVICECHARGECHECKING_H

#include "checkingAccount.h"

class noServiceChargeChecking :
	public checkingAccount
{
protected:
	double minimumBalance;
	double interestRate;

private:
	static const double MIN_BALANCE;
	static const double INTEREST_RATE;

public:
	noServiceChargeChecking(string n, string acctNum, double bal);
	noServiceChargeChecking(string n, string acctNum, double bal, double minBalance, double intRate);
	double getMinimumBalance();
	void setMinimumBalance(double minBalance);
	bool verifyMinimumumBalance(double amount);
	string writeCheck(double amount);
	string withdraw(double amount);
	string postInterest();
	virtual string createMonthlyStatement();
	virtual string print() const;
	~noServiceChargeChecking();
};

#endif