/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Service charge checking account derived class
* February 5, 2017 */

#include "serviceChargeChecking.h"

serviceChargeChecking::serviceChargeChecking(string n, string acctNumber, double bal) : checkingAccount(n, acctNumber, bal)
{
	serviceChargeAccount = ACCOUNT_SERVICE_CHARGE;
	serviceChargeCheck = SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS;
	numberOfChecksWritten = 0;
}

serviceChargeChecking::serviceChargeChecking(string n, string acctNumber, double bal, double servChargeAmount, double servChargeCheck) : checkingAccount(n, acctNumber, bal)
{
	serviceChargeAccount = servChargeAmount;
	serviceChargeCheck = servChargeCheck;
	numberOfChecksWritten = 0;
}

double serviceChargeChecking::getServiceChargeAccount()
{
	return serviceChargeAccount;
}

void serviceChargeChecking::setServiceChargeAccount(double amount)
{
	serviceChargeAccount = amount;
}

double serviceChargeChecking::getServiceChargeChecks()
{
	return serviceChargeCheck;
}

void serviceChargeChecking::setServiceChargeChecks(double amount)
{
	serviceChargeCheck = amount;
}

int serviceChargeChecking::getNumberOfChecksWritten()
{
	return numberOfChecksWritten;
}

void serviceChargeChecking::setNumberOfChecksWritten(int num)
{
	numberOfChecksWritten += num;
}

string serviceChargeChecking::writeCheck(double amount)
{
	string result;
	stringstream ss;
	ss << std::fixed << std::setprecision(2) << amount;

	balance -= amount;
	setNumberOfChecksWritten(1);
	result = "Your check for $";
	result += ss.str();
	result += " has been sent.\n";
	result += "Your new balance is $";
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << balance;
	result += ss.str();
	result += "\n";

	if (numberOfChecksWritten > MAXIMUM_NUM_OF_CHECKS)
	{
		postServiceCharge('c');
		result += "\nYou've exceeded your maximum number of checks for the month.\n";
		result += "You've been charged $";
		ss.str(string());
		ss.clear();
		ss << std::fixed << std::setprecision(2) << serviceChargeCheck;
		result += ss.str();
		result += "\nYour new balance is $";
		ss.str(string());
		ss.clear();
		ss << std::fixed << std::setprecision(2) << balance;
		result += ss.str();
		result += "\n";
	}

	return result;
}

void serviceChargeChecking::postServiceCharge(char type)
{
	// type = a for account charge, c for check charge
	if (type == 'a')
	{
		balance -= serviceChargeAccount;
	}
	else if (type == 'c')
	{
		balance -= serviceChargeCheck;
	}
}

string serviceChargeChecking::createMonthlyStatement()
{
	string result;
	postServiceCharge('a');
	result = print();
	numberOfChecksWritten = 0;
	return result;
}

string serviceChargeChecking::print() const
{
	ostringstream ss;
	string result;

	result = "Account for " + name + "\n";
	result += "Account number:                   " + accountNumber + "\n";
	result += "Maximum number of checks:         " + to_string(MAXIMUM_NUM_OF_CHECKS) + "\n";
	result += "Checks written this month:        " + to_string(numberOfChecksWritten) + "\n";
	result += "Monthly service fee:              $";
	ss << std::fixed << std::setprecision(2) << serviceChargeAccount;
	result += ss.str() + "\n";
	result += "Charge for exceeding max checks:  $";
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << serviceChargeCheck;
	result += ss.str() + "\n";
	ss.str(string());
	ss.clear();
	ss << std::fixed << std::setprecision(2) << balance;
	result += "Account balance:                  $" + ss.str() + "\n";

	return result;
}

serviceChargeChecking::~serviceChargeChecking()
{
}
