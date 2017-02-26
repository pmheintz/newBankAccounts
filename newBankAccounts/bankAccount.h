/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Bank account base class header
* February 5, 2017 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

class bankAccount
{
protected:
	string name;
	string accountNumber;
	double balance;

public:
	bankAccount(string n = "", string acctNum = "0", double bal = 0);
	~bankAccount();
	string getAccountNumber();
	void setAccountNumber(string acctNum);
	double getBalance();
	string getName();
	void setName(string n);
	virtual string withdraw(double amount);
	string deposit(double amount);
	virtual string createMonthlyStatement() = 0;
	virtual string print() const;
	string displayMenu();
};

#endif // !BANKACCOUNT_H
