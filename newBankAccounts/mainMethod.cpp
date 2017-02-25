/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* Bank account program with virtual and abstract
* February 5, 2017 */

#include <iostream>
#include "info.h"
#include "savingsAccount.h"
#include "highInterestSavings.h"
#include "noServiceChargeChecking.h"
//#include "bankAccountUI.h"
//using namespace std;

void main()
{
	info myInfo("Paul Heintz", 3, "Virtual and Abstract");
	myInfo.displayInfo();

	savingsAccount paul("Paul Heintz", "8675309", 1000.00);
	cout << paul.print() << endl;
	cout << paul.withdraw(499.75);
	cout << paul.createMonthlyStatement() << endl;
	cout << paul.postInterest() << endl;

	highInterestSavings mark("Mark Heintz", "8675309", 5000.00, 1.15, 100);
	cout << mark.print() << endl;
	cout << mark.withdraw(5050.00) << endl;
	cout << mark.withdraw(4950.00) << endl;
	cout << mark.withdraw(50.00) << endl;
	cout << mark.createMonthlyStatement() << endl;
	cout << mark.postInterest() << endl;

	noServiceChargeChecking tim("Tim Heintz", "9", 10000.00);
	cout << tim.print() << endl;
	cout << tim.createMonthlyStatement() << endl;

	//bankAccountUI theUI;
	//theUI.displayAcctTypeMenu();

	cin.ignore();
}