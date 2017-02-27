/* Paul Heintz heintzpm@gmatc.matc.edu
* ITDEV-154 Downtown
* User interface for bank accounts app
* February 22, 2017 */

#include "bankAccountUI.h"

bankAccountUI::bankAccountUI()
{
}

bankAccountUI::~bankAccountUI()
{
}

void bankAccountUI::mainMethod()
{
	savingsAccount pauls("Paul Heintz", "8675309", 500.37);
	highInterestSavings marks("Mark Heintz", "5800456", 7057.23);
	noServiceChargeChecking debis("Debi Heintz", "9237451", 100.97);
	serviceChargeChecking tims("Timothy Heintz", "3649150", 932077.44);

	accounts.push_back(&pauls);
	accounts.push_back(&marks);
	accounts.push_back(&debis);
	accounts.push_back(&tims);

	cout << "Welcome to the bank accounts program!" << endl;
	cout << "Press any key to display all accounts in vector" << endl;
	cin.ignore();
	int selection;
	do
	{
		displayAccount(-2);
		selection = promptForAccount();
		if (selection != -1)
		{
			accountMenu(selection);
		}
	} while (selection != -1);


	//for (int i = 0; i < accounts.size(); i++)
	//{
	//	cout << "Account " << i << endl;
	//	cout << accounts[i]->print() << endl;
	//	/*if (dynamic_cast<checkingAccount*>(accounts[i]))
	//	{
	//	checkingAccount *temp;
	//	temp = static_cast<checkingAccount*>(accounts[i]);
	//	cout << temp->displayMenu() << endl;
	//	}
	//	else
	//	{
	//	cout << accounts[i]->displayMenu() << endl;
	//	}*/
	//}
}

int bankAccountUI::promptForAccount()
{
	int selection;
	int vectorSize = (accounts.size() - 1);
	cout << "Enter the account number you'd like to work with.\nEnter -1 to quit: ";
	selection = getInt();
	if (selection == -1) { return selection; }
	while (selection > vectorSize)
	{
		cout << "No account in that index. Please try again: ";
		selection = getInt();
	}  

	displayAccount(selection);
	return selection;
}

void bankAccountUI::displayAccount(int account)
{
	if (account == -2)
	{
		for (unsigned int i = 0; i < accounts.size(); i++)
		{
			cout << "Account #" << i << endl;
			cout << accounts[i]->print() << endl;
		}
	}
	else
	{
		cout << "Account " << account << endl;
		cout << accounts[account]->print() << endl;
	}
}

int bankAccountUI::getInt()
{
	int selection;
	do
	{
		cin >> selection;
		if (!(cin))
		{
			cin.clear();
			cin.ignore();
			selection = -2;
			cout << "Invalid entry. Please try again: ";
		}
	} while (selection < -1);
	return selection;
}

void bankAccountUI::accountMenu(int accountIndex)
{
	int selection;

	if (dynamic_cast<checkingAccount*>(accounts[accountIndex]))
	{
		checkingAccount *temp;
		temp = static_cast<checkingAccount*>(accounts[accountIndex]);
		cout << temp->displayMenu() << endl;
	}
	else
	{
		cout << accounts[accountIndex]->displayMenu() << endl;
	}

	double money;
	do
	{
		cout << "Enter your selection: ";
		selection = getInt();
		switch (selection)
		{
		case 0:
			break;
		case 1:
			cout << accounts[accountIndex]->print() << endl;
			if (dynamic_cast<checkingAccount*>(accounts[accountIndex]))
			{
				checkingAccount *temp;
				temp = static_cast<checkingAccount*>(accounts[accountIndex]);
				cout << temp->displayMenu() << endl;
			}
			else
			{
				cout << accounts[accountIndex]->displayMenu() << endl;
			}
			break;
		case 2:
			if (dynamic_cast<checkingAccount*>(accounts[accountIndex]))
			{
				checkingAccount *temp;
				temp = static_cast<checkingAccount*>(accounts[accountIndex]);
				cout << temp->createMonthlyStatement() << endl;
				cout << temp->displayMenu() << endl;
			}
			else
			{
				cout << accounts[accountIndex]->displayMenu() << endl;
			}
			break;
		case 3:
			cout << endl << "How much money will you deposit: $";
			money = getDouble();
			if (dynamic_cast<checkingAccount*>(accounts[accountIndex]))
			{
				checkingAccount *temp;
				temp = static_cast<checkingAccount*>(accounts[accountIndex]);
				cout << temp->deposit(money) << endl;
				cout << temp->displayMenu() << endl;
			}
			else
			{
				cout << accounts[accountIndex]->displayMenu() << endl;
			}
			break;
		case 4:
			cout << endl << "How much money will you withdraw: $";
			money = getDouble();
			if (dynamic_cast<checkingAccount*>(accounts[accountIndex]))
			{
				checkingAccount *temp;
				temp = static_cast<checkingAccount*>(accounts[accountIndex]);
				cout << temp->withdraw(money) << endl;
				cout << temp->displayMenu() << endl;
			}
			else
			{
				cout << accounts[accountIndex]->displayMenu() << endl;
			}
			break;
		case 5:
			if (dynamic_cast<checkingAccount*>(accounts[accountIndex]))
			{
				checkingAccount *temp;
				temp = static_cast<checkingAccount*>(accounts[accountIndex]);
				cout << endl << "Enter check amount: $";
				money = getDouble();
				cout << temp->writeCheck(money) << endl;
				cout << temp->displayMenu() << endl;
			}
			else
			{
				cout << "Invalid selection!\n";
				cout << accounts[accountIndex]->displayMenu() << endl;
			}
			break;
		default:
			cout << "Invalid selection!\n";
			cout << accounts[accountIndex]->displayMenu() << endl;
			break;
		}
	} while (selection >= 1 && selection <= 5);
}

double bankAccountUI::getDouble()
{
	double myDouble;

	while (!(cin >> myDouble))
	{
		cin.clear();
		cin.ignore();
		cout << "*ERROR* Invalid value, try again: ";
	}
	return myDouble;
}
