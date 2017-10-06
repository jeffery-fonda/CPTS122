#ifndef CIPHER_H
#define CIPHER_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::getline;

class Cipher
{
	public:
		// cipher functions, constructors, setters, getters, destructor 
		Cipher ();
		Cipher (string new_text, string new_encoded_text, string new_decoded_text, int new_shift_value);

		Cipher (Cipher &copy_object);

		string get_text () const;
		string get_encoded_text () const;
		string get_decoded_text () const;
		int get_shift_value () const;

		void set_text (string new_text);
		void set_encoded_text (string new_encoded_text);
		void set_decoded_text (string new_decoded_text);
		void set_shift_value (int new_shift_value);

		~Cipher ();

		// operator overloaded functions
		friend istream & operator >> (istream &input, Cipher &rhs);
		friend ostream & operator << (ostream &output, Cipher &lhs);

	protected:
		string text;
		string encoded_text;
		string decoded_text;
		int shift_value;
};

#endif