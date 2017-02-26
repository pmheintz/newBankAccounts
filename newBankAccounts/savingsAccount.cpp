/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Savings account derived class
* February 5, 2017 */

#include "savingsAccount.h"

savingsAccount::~savingsAccount()
{
}

savingsAccount::savingsAccount(string n, string acctNum, double bal, double intRate):bankAccount(n, acctNum, bal)
{
	interestRate = intRate;
}

double savingsAccount::getInterestRate() const
{
	return interestRate;
}

void savingsAccount::setInterestRate(double intRate)
{
	interestRate = intRate;
}

string savingsAccount::withdraw(double amount)
{
	string result;
	stringstream ss;
	ss << std::fixed << std::setprecision(2) << amount;

	if ((balance - amount) < 0)
	{
		result = "Insufficient funds in acount " + accountNumber;
		result += "\nCurrent account balance is $";
		ss.str(string());
		ss.clear();
		ss << std::fixed << std::setprecision(2) << balance;
		result += ss.str();
		result += "\n";
	}
	else
	{
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
	}
	return result;
}

string savingsAccount::postInterest()
{
	ostringstream ss;
	string result;
	double interest;

	if (balance <= 0)
	{
		result = "No interest gained.\n Your balance is $" + to_string(balance);
		return result;
	}

	interest = balance * (interestRate / 100);

	ss << std::fixed << std::setprecision(2) << interest;
	balance = balance + interest;
	result = "Interest of $";
	result += ss.str();
	result += " was added to account ";
	result += accountNumber;
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << balance;
	result += "\nYour new balance is $" + ss.str() + "\n";

	return result;
}

string savingsAccount::createMonthlyStatement()
{
	postInterest();
	return print();
}

string savingsAccount::print() const
{
	ostringstream ss;
	string result;

	result = "Account for " + name + "\n";
	result += "Account type:     Regular Savings\n";
	result += "Account number:   " + accountNumber + "\n";
	ss << std::fixed << std::setprecision(2) << interestRate;
	result += "Interest rate:    %" + ss.str() + "\n";
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << balance;
	result += "Account balance:  $" + ss.str() + "\n";

	return result;
}
