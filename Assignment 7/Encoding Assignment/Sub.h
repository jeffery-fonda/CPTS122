#ifndef SUB_H
#define SUB_H

#define _CRT_SECURE_NO_WARNINGS

#include "Cipher.h"

class Sub : public Cipher
{
	friend class Cipher;
	friend class Caesar;

	public:
		Sub ();
		Sub (string new_text, string new_encoded_text, string new_decoded_text, int new_shift_value);
		~Sub ();

		void sub_menu_sub (string text, string encoded_text, string decoded_text, int shift_value);

		char generate_random_string ();

		string encode_message (string text, string encoded_text, int shift_value);
		string decode_message (string text, string encoded_text, string decoded_text, int shift_value);

	private:
		// I prefer to use local variables for the menu instead of a member variable
		// I am satisfying the requirements of having a class for the menu though
};

#endif