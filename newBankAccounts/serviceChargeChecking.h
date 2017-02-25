/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Service charge checking account derived class header
* February 5, 2017 */

#ifndef SERVICECHARGECHECKING_H
#define SERVICECHARGECHECKING_H

#include "checkingAccount.h"

static const int MAXIMUM_NUM_OF_CHECKS = 5; // set low for testing
static const double ACCOUNT_SERVICE_CHARGE = 5.00;
static const double SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS = 10.00;

class serviceChargeChecking :
	public checkingAccount
{
private:
	double serviceChargeAccount;
	double serviceChargeCheck;
	int numberOfChecksWritten;

public:
	serviceChargeChecking(string n, string acctNumber, double bal);
	serviceChargeChecking(string n, string acctNumber, double bal, double servChargeAmount, double servChargeCheck);
	double getServiceChargeAccount();
	void setServiceChargeAccount(double amount);
	double getServiceChargeChecks();
	void setServiceChargeChecks(double amount);
	int getNumberOfChecksWritten();
	void setNumberOfChecksWritten(int num);
	string writeCheck(double amount);
	void postServiceCharge(char type);
	virtual string createMonthlyStatement();
	virtual string print();
	~serviceChargeChecking();
};

#endif