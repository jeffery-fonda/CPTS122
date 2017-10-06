#ifndef STUDENTNODE_H
#define STUDENTNODE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
using std::to_string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::istringstream;

class Student // node class for list
{
	friend class Menu;
	friend class Classroom;

	friend ostream & operator <<(ostream &output, Student &rhs); // returns ostream reference for chaining

	public:
		Student(); // default constructor
		Student(int newRecordNumber, int newID, string newFn, string newLn, string newEmail, string newUnits,
				string newProgram, string newLevel);
		Student(const Student &copyObject); // copy constructor

		~Student(); // destructor

		// getters/setters
		int getRecordNumber() const;
		int getID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmail() const;
		string getUnits() const;
		string getProgram() const;
		string getLevel() const;
		int getNumAbsences() const;
		string getAbsenceDate(int absenceNumber) const; // returns a specific absence date
		Student * getNextPtr() const;

		void setRecordNumber(int newNumber);
		void setID(int newID);
		void setFirstName(string newFirstName);
		void setLastName(string newLastName);
		void setEmail(string newEmail);
		void setUnits(string newUnits);
		void setProgram(string newProgram);
		void setLevel(string newLevel);
		// void setNumAbsences(int newAbsences); - this can only be done through other two member functions below
		void setAbsenceDate(string newDate, int absenceNumber); // only modifies existing absence
		void setNextPtr(Student *newPtr);

		// overloaded operators
		Student & operator =(Student &rhs); // returns reference to Student object that was assigned for chaining

		// other member functions
		void addNewAbsence(string absenceDate); // increments number absences
		void deleteAbsence(int absenceNumber); // decrements number absences

	private:
		int recordNumber;
		int studentID;
		string firstName;
		string lastName;
		string email;
		string units;
		string program;
		string level;
		int numberAbsences;
		vector<string> absenceDates;
		Student *pNext;
};

#endif