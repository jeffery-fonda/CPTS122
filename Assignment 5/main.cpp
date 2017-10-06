/*Programmer: Jeffery Fonda
Class: CptS 122, Spring 2015; Lab Section 5
Programming Assignment: Assingment 5
Date: March 1, 2015
Description: Basic bank application, like any bank account, 
you can only change the name, or withdraw/deposit. Max length 
name can be is 15 characters. Do NOT enter spaces when putting
name in. 
*/

#include "header.h"

int main (void)
{
	account account_1;
	int option; 
	double credit, debit;
	string new_name;
	
	system ("cls");

	do
	{
		cout << "1. Enter your account information" << endl;
		cout << endl;
		cout << "2. Change name on account" << endl;
		cout << endl;
		cout << "3. Deposit money to account" << endl;
		cout << endl;
		cout << "4. Withdrawl money from account" << endl;
		cout << endl;
		cout << "5. Print account information" << endl;
		cout << endl;
		cout << "6. Exit program" << endl;
		cout << endl;
		cout << "Enter choice: ";
		cin >> option;
		cout << endl;

		switch (option) {
		case 1:		cout << "Enter account information" << endl << endl;
					cout << "Balance: " << endl;
					cout << "Account Number: " << endl;
					cout << "Customer Name (NO spaces): " << endl;
					cout << "Creation Date: " << endl;
					cin >> account_1;
					cout << endl;
			break;
		case 2:		cout << "Change name" << endl << endl;
					cout << "Enter new name (NO spaces): " << endl;
					cin >> new_name;
					cout << "New name on account: " << endl;
					account_1.change_name (new_name);
					cout << endl;
			break;
		case 3:		cout << "Deposit money to account" << endl << endl;
					cout << "Enter amount you wish to add: " << endl;
					cin >> credit;
					cout << "Your account balance is: " << endl;
					account_1.deposit (credit);
					cout << endl;
			break;
		case 4:		cout << "Withdraw money from account" << endl << endl;
					cout << "Enter amount you wish to withdraw: " << endl;
					cin >> debit;
					cout << "Your account balance is now: " << endl;
					account_1.withdraw (debit);
					cout << endl;
			break;
		case 5:		cout << "Account information" << endl << endl;
					cout << "Balance: " << endl;
					cout << "Account Number: " << endl;
					cout << "Customer Name: " << endl;
					cout << "Creation Date: " << endl;
					cout << account_1 << endl;
			break;
		case 6:		cout << "Exiting program" << endl;
					exit (EXIT_FAILURE);
			break;
		default: cout << "Invalid choice" << endl;
			break;
		}
		system ("pause");
		system ("cls");
	} while (option != 6);

	return 0;
}