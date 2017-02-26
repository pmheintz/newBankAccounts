/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Header for user interface for bank accounts app
* February 22, 2017 */

#ifndef BANKACCOUNTUI_H
#define BANKACCOUNTUI_H

#include "bankAccount.h"
#include "savingsAccount.h"
#include "highInterestSavings.h"
#include "checkingAccount.h"
#include "noServiceChargeChecking.h"
#include "serviceChargeChecking.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class bankAccountUI
{
public:
	bankAccountUI();
	~bankAccountUI();
};

#endif