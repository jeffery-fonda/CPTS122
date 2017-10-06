#include "Cipher.h"
#include "Caesar.h"
#include "Menu.h"
#include "Sub.h"

Sub::Sub ()
{
	shift_value = 0;
}

Sub::Sub (string new_text, string new_encoded_text, string new_decoded_text, int new_shift_value)
{
	text = new_text;
	encoded_text = new_encoded_text;
	decoded_text = new_decoded_text;
	shift_value = new_shift_value;
}

Sub::~Sub ()
{

}

void Sub::sub_menu_sub (string text, string encoded_text, string decoded_text, int shift_value)
{
	Sub s1;
	int option_sub;

	do
	{
		cout << "1. Encode Message (Substitution)" << endl;
		cout << endl;
		cout << "2. Decode Message (substitution)" << endl;
		cout << endl;

		cout << "Enter choice: ";

		cin >> option_sub;
		cout << endl;

		switch (option_sub) {
		case 1:		s1.encode_message (text, encoded_text, shift_value);
			break;
		case 2:		s1.decode_message (text, encoded_text, decoded_text, shift_value);
			break;
		default: cout << "Invalid choice" << endl;
			break;
		}
		system ("pause");
		system ("cls");
	} while (option_sub != 2);
}

char Sub::generate_random_string () 
{
	static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int string_length = sizeof(alphanum) - 1;

    return alphanum[rand() % string_length];
}

string Sub::encode_message (string text, string encoded_text, int shift_value)
{
	string answer;

	cout << "Please enter message to encode: " << endl << endl;
	cin.ignore();
	getline (cin, text);
	cout << endl;
	cout << "Here is the message you want to encode: " << endl << endl;
	cout << text << endl << endl;

	int index_1, index_2; // index_1 corresponds to text, index_2 corresponds to encoded_text
	char temp;

	for (index_1 = 0, index_2 = 0; index_1 < text.size(); index_1++)
    {
		if((text[index_1] != ' ') && (ispunct(text[index_1]) == false))
        {
			temp = toupper(text[index_1]);
			encoded_text.push_back(temp);
			index_2++;
        }
    }

	cout << "Here is your modified message: " << endl << endl;
	cout << encoded_text << endl << endl;

	string random_string;

	for (int index_3 = 0; index_3 < 26; ++index_3)
    {
		random_string += generate_random_string();
    }

	cout << random_string << endl << endl;

	cout << "This is as far as I got, I couldn't figure out how to restrict the characters from showing up in the generated string. Wasn't able to figure out the substitution either..." << endl;

	return encoded_text;
}

string Sub::decode_message (string text, string encoded_text, string decoded_text, int shift_value)
{
	cout << "Not enough time to finish this one." << endl;

	return decoded_text;
}