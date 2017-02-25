/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Bank account base class
* February 5, 2017 */

#include "bankAccount.h"

bankAccount::bankAccount(string n, string acctNum, double bal)
{
	name = n;
	accountNumber = acctNum;
	balance = bal;
}

bankAccount::~bankAccount()
{
}

string bankAccount::getAccountNumber()
{
	return accountNumber;
}

void bankAccount::setAccountNumber(string acctNum)
{
	accountNumber = acctNum;
}

double bankAccount::getBalance()
{
	return balance;
}

string bankAccount::getName()
{
	return name;
}

void bankAccount::setName(string n)
{
	name = n;
}

string bankAccount::withdraw(double amount)
{
	stringstream ss;
	string result;
	ss << std::fixed << setw(10) << std::setprecision(2) << amount;

	balance -= amount;

	result = "You have withdrawn $";
	result += ss.str();
	result += " from account ";
	result += accountNumber;
	result += "\nYour new balance is $";
	result += to_string(balance);
	result += "\n";

	return result;
}

string bankAccount::deposit(double amount)
{
	stringstream ss;
	string result;
	ss << std::fixed << setw(10) << std::setprecision(2) << amount;

	balance += amount;

	result = "You have deposited $";
	result += ss.str();
	result += " into account ";
	result += accountNumber;
	result += "\nYour new balance is $";
	result += to_string(balance);
	result += "\n";

	return result;
}

string bankAccount::print() const
{
	stringstream ss;
	string result;
	ss << std::fixed << setw(10) << std::setprecision(2);

	result = "Account holder's name: ";
	result += name;
	result += "\nAccount number: ";
	result += accountNumber;
	result += "\nAccount balance: $";
	result += to_string(balance);
	result += "\n";

	return result;
}
