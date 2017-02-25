/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Service charge checking account derived class
* February 5, 2017 */

#include "serviceChargeChecking.h"

serviceChargeChecking::serviceChargeChecking(string n, string acctNumber, double bal) : checkingAccount(n, acctNumber, bal)
{
	serviceChargeAccount = ACCOUNT_SERVICE_CHARGE;
	serviceChargeCheck = SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS;
}

serviceChargeChecking::serviceChargeChecking(string n, string acctNumber, double bal, double servChargeAmount, double servChargeCheck) : checkingAccount(n, acctNumber, bal)
{
	serviceChargeAccount = servChargeAmount;
	serviceChargeCheck = servChargeCheck;
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

serviceChargeChecking::~serviceChargeChecking()
{
}
