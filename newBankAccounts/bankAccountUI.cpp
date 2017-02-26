/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* User interface for bank accounts app
* February 22, 2017 */

#include "bankAccountUI.h"

bankAccountUI::bankAccountUI()
{
	vector<bankAccount*> accounts;
	savingsAccount pauls("Paul Heintz", "8675309", 500.37);
	highInterestSavings marks("Mark Heintz", "5800456", 7057.23);
	noServiceChargeChecking debis("Debi Heintz", "9237451", 100.97);
	serviceChargeChecking tims("Timothy Heintz", "3649150", 932077.44);

	accounts.push_back(&pauls);
	accounts.push_back(&marks);
	accounts.push_back(&debis);
	accounts.push_back(&tims);

	for (int i = 0; i < accounts.size(); i++)
		cout << accounts[i]->print() << endl;
}

bankAccountUI::~bankAccountUI()
{
}
