#include "Menu.h"

Menu::Menu ()
{
	mOption = 0;
}

Menu::Menu (int newmOption)
{
	mOption = newmOption;
}

Menu::Menu (Menu &copyObject)
{
	mOption = copyObject.mOption;
}

Menu::~Menu ()
{
	// destructor for menu
}

int Menu::getOption () const
{
	return mOption;
}

void Menu::setOption (int newmOption)
{
	mOption = newmOption;
}

void Menu::display_menu ()
{
	do
	{
		system ("cls");
		cout << "This is an attendance tracker." << endl << endl;
		cout << "1. Import course list." << endl << endl;
		cout << "2. Load master list." << endl << endl;
		cout << "3. Store master list." << endl << endl;
		cout << "4. Mark absences." << endl << endl;
		cout << "5. Edit Absences." << endl << endl;
		cout << "6. Generate report." << endl << endl;
		cout << "7. Exit" << endl << endl;

		cout << "Enter option: " << endl;
		cin >> mOption;
		cout << endl;

		switch (mOption) {
			case 1: importCourseList ();
				break;
			case 2: cout << "load master list" << endl;
				break;
			case 3: cout << "store master list" << endl;
				break;
			case 4: cout << "mark absences" << endl;
				break;
			case 5: cout << "edit absences" << endl;
				break;
			case 6: cout << "generate report" << endl;
          		break;
			case 7:
        		cout << "Exiting program" << endl;
						exit (EXIT_FAILURE);
			default:	cout << "Error! Invalid choice." << endl;
				break;
		}
		system ("pause");
		system ("cls");
	} while (mOption != 7);
}

bool Menu::importCourseList()
{
	Classroom c1;
	bool success = false;
	string filename, buffer;
	istringstream parseStream;

	cout << "Enter the filename for the course list to import (include file extension):\n> ";
	getline(cin, filename);
  
	ifstream infile(filename, ifstream::in); // opens file with read permissions
  
	if (infile != NULL)
	{
		success = true;

		// declare Student object variables - can also be done in while loop
		int newID = 0, newRecordNum = 0;
		string newFirstName, newLastName, newEmail, newUnits, newProgram, newLevel;
		getline(infile, buffer); // gets first line with empty data

		while (infile.peek() != EOF)//peek means checking the next character in the file but doesnt extract it 
		{
			// get Record Number
			getline(infile, buffer, ','); // reads infile until the comma is found and gets rid of the comma
			parseStream.str(buffer); // takes the contents of the string buffer and puts them into istringstream
			parseStream >> newRecordNum; // extracts an integer from istringstream just like cin >>
			parseStream.clear(); // clears potential flags - when all characters have been read from istringstream, it sets an EOF flag 
          // and nothing can be read from it again until the flag is cleared

			// get StudentID
			getline(infile, buffer, ',');
			parseStream.str(buffer);
			parseStream >> newID;
			parseStream.clear(); // clears potential flags in istringstream

			// get last name
			infile.ignore(5, '"'); // ignores up to 5 characters until the quote is found in file and gets rid of it
			getline(infile, buffer, ',');
			newLastName = buffer;

			// get first name
			getline(infile, buffer, '"'); // reads until the quote is found
			newFirstName = buffer;
			infile.ignore(5, ','); // ignores the comma after the quote

			// get email
			getline(infile, buffer, ',');
			newEmail = buffer;

			// get units
			getline(infile, buffer, ',');
			newUnits = buffer;

			// get program
			getline(infile, buffer, ',');
			newProgram = buffer;

			// get level
			getline(infile, buffer); // reads until end of line since this is the last item
			newLevel = buffer;

			c1.insert (newRecordNum, newID, newFirstName, newLastName, newEmail, newUnits, newProgram, newLevel);
			// node created and inserted at front of list
		}

		infile.close();
	}
	else
	{
		cout << "Error opening " << filename << endl;
	}

	return success;
}