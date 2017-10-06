#include "Cipher.h"
#include "Caesar.h"
#include "Menu.h"

Caesar::Caesar ()
{
	shift_value = 0;
}

Caesar::Caesar (string new_text, string new_encoded_text, string new_decoded_text, int new_shift_value)
{
	text = new_text;
	encoded_text = new_encoded_text;
	decoded_text = new_decoded_text;
	shift_value = new_shift_value;
}

Caesar::~Caesar ()
{

}

char Caesar::caesar (char c, int shift_value)
{
	if (shift_value > 0)
	{
		c = (((c-65) + shift_value) % 26) + 65;
	}
	if (shift_value < 0)
	{
		c = (((c+65) + shift_value) % 26) + 65;
	}

    return c;
}

void Caesar::sub_menu_caesar (string text, string encoded_text, string decoded_text, int shift_value)
{
	Caesar ca1;
	int option_cipher;

	do
	{
		cout << "1. Encode Message (Caesar)" << endl;
		cout << endl;
		cout << "2. Decode Message (Caesar)" << endl;
		cout << endl;

		cout << "Enter choice: ";

		cin >> option_cipher;
		cout << endl;

		switch (option_cipher) {
		case 1:		ca1.encode_message (text, encoded_text, shift_value);
			break;
		case 2:		ca1.decode_message (text, encoded_text, decoded_text, shift_value);
			break;
		default: cout << "Invalid choice" << endl;
			break;
		}
		system ("pause");
		system ("cls");
	} while (option_cipher != 2);
}

string Caesar::encode_message (string text, string encoded_text, int shift_value)
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
	cout << "Enter shift number: ";
	cin >> shift_value;
	cout << endl;

	int index_3 = 0; // index for stepping through encrypt loop
	string temp_encoded;

	for (index_3 = 0; index_3 < encoded_text.length(); index_3++)
    {
		temp_encoded += caesar(encoded_text[index_3], shift_value);
    }

	encoded_text = temp_encoded;

	cout << "Here is the encrypted message: " << endl << endl;
	cout << encoded_text << endl;

	do {
		cout << "Save this message to a file, yes or no? ";
		cin >> answer;
		cout << endl;

		if (answer == "yes")
		{
			ofstream output_file ("output.txt");

			if (output_file.is_open())
			{
				output_file << encoded_text;
				output_file.close();

				cout << "Message written successfully!" << endl << endl;
			}
			else
			{
				cout << "Something screwed up, your message was not written to another file." << endl;
			}
		}
		if (answer == "no")
		{
			cout << "Too bad, you have to write it to a file" << endl;
		}
	} while (answer != "yes");

	return encoded_text;
}

string Caesar::decode_message (string text, string encoded_text, string decoded_text, int shift_value)
{
	string answer;
	string temp_encoded_text;

	do {
		cout << "Do you have your encoded message, yes or no? ";
		cin >> answer;
		cout << endl;

		if (answer == "yes")
		{
			string file_answer;
			cout << "Is the message in a file, yes or no? ";
			cin >> file_answer;
			cout << endl;

			if (file_answer == "yes")
			{
				ifstream input;

				string filename;

				cout << "Enter filename: ";
				cin >> filename;

				input.open (filename.c_str (), std::ios::in);

				if (input.is_open())
				{
					input >> encoded_text;
					input.close();

					cout << endl << "Message read successfully!" << endl << endl;
				}
				else
				{
					cout << "Something screwed up, your file couldn't be opened." << endl;
				}
			}
			if (file_answer == "no")
			{
				cout << "Enter encoded message below: " << endl << endl;
				cin.ignore ();
				getline (cin, encoded_text);
			}
		}
		if (answer == "no")
		{
			cout << "Sucks for you, find it." << endl << endl;
		}
	} while (answer != "yes");

	cout << "Here is your encoded message: " << endl << endl;
	cout << encoded_text << endl << endl;

	cout << "Do you know your shift key, yes or no? \nIt should be the negative value you used to previously shift. ";
	cin >> answer;

	if (answer == "yes")
	{
		cout << "Enter shift key now: ";
		cin >> shift_value;
		cout << endl;

		int index_1 = 0; // index for stepping through encrypt loop

		for (index_1 = 0; index_1 < encoded_text.length(); index_1++)
		{
			temp_encoded_text += caesar(encoded_text[index_1], shift_value);
		}
	}
	if (answer == "no")
	{
		string option;

		cout << "Time to brute force the shift key!" << endl << endl;

		do
		{
			cout << "Enter shift value: ";
			cin >> shift_value;
			cout << endl;

			decoded_text = encoded_text;

			int index_1;

			for (index_1 = 0; index_1 < encoded_text.length(); index_1++)
			{
				temp_encoded_text += caesar(encoded_text[index_1], shift_value);
			}

			cout << temp_encoded_text << endl;

			cout << "Is this correct, yes or no? ";
			cin >> option;
			cout << endl;
			
			if (option == "no")
			{
				decoded_text = temp_encoded_text;
				temp_encoded_text.clear();
			}
		} while (option != "yes");
	}

	decoded_text = temp_encoded_text;

	cout << "Decoded message: " << endl << endl;
	cout << decoded_text << endl;

	return decoded_text;
}