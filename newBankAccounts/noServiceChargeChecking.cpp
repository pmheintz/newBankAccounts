/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* No service charge checking account derived class
* February 19, 2017 */

#include "noServiceChargeChecking.h"

noServiceChargeChecking::noServiceChargeChecking(string n, string acctNum, double bal) : checkingAccount(n, acctNum, bal)
{
	static const double MIN_BALANCE = 100.00;
	static const double INTEREST_RATE = 0.5;
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

noServiceChargeChecking::noServiceChargeChecking(string n, string acctNum, double bal, double minBalance, double intRate) : checkingAccount(n, acctNum, bal)
{
	minimumBalance = minBalance;
	interestRate = intRate;
}

double noServiceChargeChecking::getMinimumBalance()
{
	return minimumBalance;
}

void noServiceChargeChecking::setMinimumBalance(double minBalance)
{
	minimumBalance = minBalance;
}
// Returns true if balance - amount withdrawn is below the min. balance
bool noServiceChargeChecking::verifyMinimumumBalance(double amount)
{
	bool result;

	if ((balance - amount) < minimumBalance)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return false;
}

string noServiceChargeChecking::writeCheck(double amount)
{
	string result;
	stringstream ss;
	ss << std::fixed << std::setprecision(2) << amount;

	if (verifyMinimumumBalance(amount))
	{
		result = "Unable write check.\nThis will drop you below your minimum balance.\n";
	}
	else
	{
		balance -= amount;

		result = "Your check for $";
		result += ss.str();
		result += " has been sent.\n";
		result += "Your new balance is $";
		ss.str(string());
		ss.clear();
		ss << std::fixed << std::setprecision(2) << balance;
		result += ss.str();
		result += "\n";
	}
	return result;
}

string noServiceChargeChecking::withdraw(double amount)
{
	string result;
	stringstream ss;
	ss << std::fixed << std::setprecision(2) << amount;

	if (verifyMinimumumBalance(amount))
	{
		result = "Unable withdraw money.\nThis will drop you below your minimum balance.\n";
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

string noServiceChargeChecking::postInterest()
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

string noServiceChargeChecking::createMonthlyStatement()
{
	postInterest();
	return print();
}

string noServiceChargeChecking::print()
{
	ostringstream ss;
	string result;

	result = "Account for " + name + "\n";
	result += "Account number:   " + accountNumber + "\n";
	ss << std::fixed << std::setprecision(2) << interestRate;
	result += "Interest rate:    %" + ss.str() + "\n";
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << minimumBalance;
	result += "Minimum balance:  $" + ss.str() + "\n";
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << balance;
	result += "Account balance:  $" + ss.str() + "\n";

	return result;
}

noServiceChargeChecking::~noServiceChargeChecking()
{
}
