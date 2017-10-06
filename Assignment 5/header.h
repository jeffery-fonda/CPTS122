#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

class account
{
	public:
		// account functions, constructors, setters, getters, destructor
		account ();
		account (double new_balance, int new_account_number, string new_customer_name, string new_creation_date);

		account (account &copy_object);

		double get_balance () const;
		int get_account_number () const;
		string get_customer_name () const;
		string get_creation_date () const;

		void set_balance (double new_balance);
		void set_account_number (int new_account_number);
		void set_customer_name (string new_customer_name);
		void set_creation_date (string new_creation_date);

		~account ();

		// change account info functions
		void deposit (double credit);
		void withdraw (double debit);
		void change_name (string new_name);

		// operator overload functions
		friend istream & operator >> (istream &input, account &rhs);
		friend ostream & operator << (ostream &output, account &lhs);

	private:
		double balance;
		int account_number;
		string customer_name;
		string creation_date;
};

#endif