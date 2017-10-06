#ifndef CAESAR_H
#define CAESAR_H

#define _CRT_SECURE_NO_WARNINGS

#include "Cipher.h"

class Caesar : public Cipher
{
	public:
		Caesar ();
		Caesar (string new_text, string new_encoded_text, string new_decoded_text, int new_shift_value);
		~Caesar ();

		string encode_message (string text, string encoded_text, int shift_value);
		string decode_message (string text, string encoded_text, string decoded_text, int shift_value);

		void sub_menu_caesar (string text, string encoded_text, string decoded_text, int shift_value);

		char caesar (char c, int shift_value);

	private:
		// no members really needed since I am just using the protected members of Cipher class
};

#endif