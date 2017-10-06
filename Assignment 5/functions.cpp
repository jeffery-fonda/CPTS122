#include "header.h"

account::account ()
{
	balance = 0.0;
	account_number = 0;
	customer_name = ("", 15);
	creation_date = ("", 10);
}

account::account (double new_balance, int new_account_number, string new_customer_name, string new_creation_date)
{
	balance = new_balance;
	account_number = new_account_number;
	customer_name = new_customer_name;
	creation_date = new_creation_date;
}

account::account (account &copy_object)
{
	this -> balance = copy_object.balance;
	this -> account_number = copy_object.account_number;
	this -> customer_name = copy_object.customer_name;
	this -> creation_date = copy_object.creation_date;
}

double account::get_balance () const
{
	return balance;
}

int account::get_account_number () const
{
	return account_number;
}

string account::get_customer_name () const
{
	return customer_name;
}
		
string account::get_creation_date () const
{
	return creation_date;
}

void account::set_balance (double new_balance)
{
	balance = new_balance;
}

void account::set_account_number (int new_account_number)
{
	account_number = new_account_number;
}

void account::set_customer_name (string new_customer_name)
{
	customer_name = new_customer_name;
}

void account::set_creation_date (string new_creation_date)
{
	creation_date = new_creation_date;
}

account::~account ()
{
	cout << "Destroyed variable." << endl;
}

istream & operator >> (istream &input, account &rhs)
{
	input >> rhs.balance;
	input >> rhs.account_number; 
	input >> rhs.customer_name;
	input >> rhs.creation_date;

	return input;
}

ostream & operator << (ostream &output, account &lhs)
{
	output << lhs.balance << endl;
	output << lhs.account_number << endl;
	output << lhs.customer_name << endl;
	output << lhs.creation_date << endl;

	return output;
}

// this function allows you to deposit money
void account::deposit (double credit)
{
    balance += credit;
	cout << balance;
}

// this function allows you to withdraw money
void account::withdraw (double debit)
{
    if (debit > balance)
	{
        cout << "ERROR, insufficient funds!" << endl;
		cout << balance;
	}
    else
	{
        balance -= debit;
		cout << balance;
	}
}

// this function allows you to change your name
void account::change_name (string new_name)
{
	customer_name = new_name;
	cout << customer_name;
}