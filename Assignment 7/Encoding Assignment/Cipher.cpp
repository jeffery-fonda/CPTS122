#include "Cipher.h"
#include "Caesar.h"
#include "Menu.h"

Cipher::Cipher ()
{
	shift_value = 0;
}

Cipher::Cipher (string new_text, string new_encoded_text, string new_decoded_text, int new_shift_value)
{
	text = new_text;
	encoded_text = new_encoded_text;
	decoded_text = new_decoded_text;
	shift_value = new_shift_value;
}

Cipher::Cipher (Cipher &copy_object)
{
	this -> text = copy_object.text;
	this -> encoded_text = copy_object.encoded_text;
	this -> decoded_text = copy_object.decoded_text;
	this -> shift_value = copy_object.shift_value;
}

string Cipher::get_text () const
{
	return text;
}

string Cipher::get_encoded_text () const
{
	return encoded_text;
}

string Cipher::get_decoded_text () const
{
	return decoded_text;
}

int Cipher::get_shift_value () const
{
	return shift_value;
}

void Cipher::set_text (string new_text)
{
	text = new_text;
}

void Cipher::set_encoded_text (string new_encoded_text)
{
	encoded_text = new_encoded_text;
}

void Cipher::set_decoded_text (string new_decoded_text)
{
	decoded_text = new_decoded_text;
}

void Cipher::set_shift_value (int new_shift_value)
{
	shift_value = new_shift_value;
}

Cipher::~Cipher ()
{
	cout << "All code has been destroyed" << endl << endl;
}

istream & operator >> (istream &input, Cipher &rhs)
{
	input >> rhs.text;
	input >> rhs.encoded_text;
	input >> rhs.decoded_text;
	input >> rhs.shift_value;

	return input;
}

ostream & operator << (ostream &output, Cipher &lhs)
{
	output << lhs.text << endl;
	output << lhs.encoded_text << endl;
	output << lhs.decoded_text << endl;
	output << lhs.shift_value << endl;

	return output;
}