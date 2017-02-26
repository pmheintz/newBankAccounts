/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* High interest savings account derived class
* February 19, 2017 */

#include "highInterestSavings.h"


highInterestSavings::highInterestSavings(string n, string acctNumber, double bal) : savingsAccount(n, acctNumber, bal)
{
	interestRate = INTEREST_RATE;
	minimumBalance = MINIMUM_BALANCE;
}

highInterestSavings::highInterestSavings(string n, string acctNumber, double bal, double intRate, double minBalance) : savingsAccount(n, acctNumber, bal)
{
	interestRate = intRate;
	minimumBalance = minBalance;
}

highInterestSavings::~highInterestSavings()
{
}

double highInterestSavings::getMinimumBalance()
{
	return minimumBalance;
}

// Returns true if balance - amount withdrawn is below the min. balance
bool highInterestSavings::verifyMinimumBalance(double amount)
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

	return result;
}

string highInterestSavings::withdraw(double amount)
{
	string result;
	stringstream ss;
	ss << std::fixed << std::setprecision(2) << amount;

	if ((balance - amount) < 0)
	{
		result = "Insufficient funds in acount " + accountNumber;
		ss.str(string());
		ss.clear();
		ss << std::fixed << std::setprecision(2) << balance;
		result += "\nCurrent account balance is " + ss.str() + "\n";
	}
	else
	{
		if (verifyMinimumBalance(amount))
		{
			result = "Unable to withdraw money.\nThis will drop you below your minimum balance.\n";
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
	}
	return result;
}

string highInterestSavings::createMonthlyStatement()
{
	postInterest();
	return print();
}

string highInterestSavings::print() const
{
	ostringstream ss;
	string result;

	result = "Account for " + name + "\n";
	result += "Account type:     High Interest Savings\n";
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
