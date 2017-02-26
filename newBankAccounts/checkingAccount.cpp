/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Checking account virtual class
* February 5, 2017 */

#include "checkingAccount.h"

checkingAccount::checkingAccount(string n, string acctNumber, double bal) : bankAccount(n, acctNumber, bal)
{
}

string checkingAccount::displayMenu()
{
	string menu;
	menu = bankAccount::displayMenu();
	menu += "5) Write check\n";
	return menu;
}
