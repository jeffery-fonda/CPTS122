#include "Cipher.h"
#include "Caesar.h"
#include "Menu.h"
#include "Sub.h"

Menu::Menu ()
{

}

Menu::~Menu ()
{
	cout << "Menu destroyed." << endl;
}

void Menu::main_menu ()
{
	Caesar ca1;
	Cipher c1;
	Sub s1;
	int option;

	system ("cls");

	do
	{
		cout << "1. Caeser Cipher" << endl;
		cout << endl;
		cout << "2. Substitution Cipher" << endl;
		cout << endl;
		cout << "3. Exit Program" << endl;
		cout << endl;

		cout << "Enter choice: ";

		cin >> option;
		cout << endl;

		switch (option) {
		case 1:		ca1.sub_menu_caesar (c1.get_text(), c1.get_encoded_text(), c1.get_decoded_text(), c1.get_shift_value());
			break;
		case 2:		s1.sub_menu_sub (s1.get_text(), s1.get_encoded_text(), s1.get_decoded_text(), s1.get_shift_value());
			break;
		case 3:		c1.~Cipher ();
					exit (EXIT_FAILURE);
			break;
		default: cout << "Invalid choice" << endl;
			break;
		}
		system ("pause");
		system ("cls");
	} while (option != 3);

}