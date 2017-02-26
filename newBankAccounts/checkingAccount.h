/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Checking account virtual class header
* February 5, 2017 */

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "bankAccount.h"

class checkingAccount :
	public bankAccount
{
public:
	checkingAccount(string n, string acctNumber, double bal);
	virtual string writeCheck(double amount) = 0;
	string displayMenu();
};

#endif