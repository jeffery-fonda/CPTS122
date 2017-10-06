#include "Classroom.h"
#include "StudentNode.h"
#include "Menu.h"

Student *Classroom::makeStudent (int ID, int Record, string name1, string name2, string email, string major, string Year, string Credits)
{
	Student*pCur = NULL;
	pCur = new Student;
	pCur -> numberAbsences = 0;
	pCur -> units = Credits;
	pCur -> email = email;
	pCur -> firstName = name1;
	pCur -> lastName = name2;
	pCur -> studentID = ID;
	pCur -> program = major;
	pCur -> recordNumber = Record;
	pCur -> level = Year;
	return pCur;
 
}

bool Classroom::insert(int ID, int Record, string name1, string name2, string email, string major, string Year, string Credits)
{
	Student *pCur = NULL;
	bool success = false;
	 
	pCur = makeStudent (ID, Record, name1, name2, email, major, Year, Credits);

	if (pCur != NULL)
	{
		pCur -> pNext = this -> mpFirst;
		this -> mpFirst = pCur;
		success = true;
	}
	return success;
}

bool Classroom::markAbsences (Student* pFirst, int absense)
{
	Student *pCur = NULL;
	char option;
	bool success = false;
	pCur = mpFirst;
  
	time_t t = time(0);
	struct tm *time = localtime(&t);
	string date;

	date = to_string (time -> tm_mon + 1) + "/" + to_string (time -> tm_mday) + "/" + to_string (time -> tm_year + 1900);
  
	while (pCur!= NULL)
	{
		do
		{
			cout << "Is" << pCur -> getFirstName () << " " << pCur-> getLastName () << " present?" << endl;
			cin >> option;
			if (option != 'Y' && option != 'y' && option != 'n' && option != 'N')
			{
				cout << "Invalid input. Try again" << endl;
			}
		} while (option == 'Y' && option == 'y' && option == 'n' && option == 'N');

		switch (option)
		{
		case 'n':
		case 'N':
			pCur -> addNewAbsence(date);
			break;
		}
		pCur = pCur -> pNext;
		success = true;
	}
	return success;
}
  
//bool ClassRoom::Edit_Absences(Student* pFirst, int absense, string date)
//{
//	Student * pCur = NULL;
//	string option;
//	pFirst = pCur;
//	while(pCur!= NULL)
//	{
//		Student * pCur = NULL;
//		string option;
//		pFirst = pCur;
//		while(pCur!= NULL)
//		{
//			while((option !="Yes")||(option != "yes")|| (option != "No")||(option != "no"))
//			{
//				//then we want to prompt if they are present or not
//				cout<<"Which Date would you like to refine by? in (mm/dd/yyyy)"<<endl;
//				cin>>date;
//				while(pCur->mDate ==date)
//				{
//					cout<<"\t\t\tPresent that day? (Yes or No)"<<endl;
//					cin>>option;
//					if((option =="No")||(option == "no")) 
//						{
//							pCur->mabsenses = pCur->mabsenses +1;
//							pCur->mDate = date;
//							pCur = pCur->mpNext;
//						}
//					else if((option == "Yes")||(option == "yes"))
//						{
//							pCur = pCur->mpNext;
//		
//						}
//				}
//			}
//		}
//	}
//
//
//}

Student *Classroom::generateReport(Student* pFirst, int absense, string date)
{
	int option;

	do {
		system ("cls");
		cout << "Which type of report is requested" << endl << endl;
		cout << "1. A report that shows all of the students in the class and the number of times they have been absent along with the corresponding dates they were absent." << endl << endl;
		cout << "2. A report that provides only the students that have been absent greater than some threshold set by the user." << endl << endl;
		cout << "3. A report that provides the students that were absent on a certain date." << endl << endl;
	
		cin >> option;

		//The reports only need to report the each student’s name, email, 
		//along with the absences information. Write each report to a different .txt file.

		int theshold = 0;
	
		switch (option)	{
			case 1: //all of the students and number of times
				break;
			case 2: //prompt for theshold
				cout<<"What amount of absences are you looking for"<<endl;
      
				cin>>theshold;
      
				if(theshold != 0)
				{
				
				}
				break;
			case 3: //search a date and find who is absent
				break;
		}
		system ("pause");
		system ("cls");
	} while (option != 3);

	return pFirst;
}