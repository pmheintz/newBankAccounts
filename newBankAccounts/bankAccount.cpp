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
	ss << std::fixed << std::setprecision(2) << amount;

	balance -= amount;

	result = "You have withdrawn $";
	result += ss.str();
	result += " from account ";
	result += accountNumber;
	result += "\nYour new balance is $";
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << balance;
	result += ss.str();
	result += "\n";

	return result;
}

string bankAccount::deposit(double amount)
{
	stringstream ss;
	string result;
	ss << std::fixed << std::setprecision(2) << amount;

	balance += amount;

	result = "You have deposited $";
	result += ss.str();
	result += " into account ";
	result += accountNumber;
	result += "\nYour new balance is $";
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << balance;
	result += ss.str();
	result += "\n";

	return result;
}

string bankAccount::print() const
{
	stringstream ss;
	string result;
	ss << std::fixed << std::setprecision(2) << balance;

	result = "Account for ";
	result += name;
	result += "\nAccount number:  ";
	result += accountNumber;
	result += "\nAccount balance: $";
	result += ss.str();
	result += "\n";

	return result;
}

string bankAccount::displayMenu()
{
	string menu;
	menu = "0) Exit\n";
	menu += "1) Print account information\n";
	menu += "2) Create monthly statement\n";
	menu += "3) Deposit money\n";
	menu += "4) Withdraw money\n";
	return menu;
}
