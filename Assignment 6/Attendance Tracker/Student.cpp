#include "StudentNode.h"

ostream & operator << (ostream &output, Student &rhs)
{
	output << "Record Number: " << rhs.recordNumber << "\n";
	output << "Name: " << rhs.lastName << ", " << rhs.firstName << "\n";
	output << "Student ID: " << rhs.studentID << "\n";
	output << "Number Absences: " << rhs.numberAbsences << "\n";
	output << "Units: " << rhs.units << "\n";
	output << "Program: " << rhs.program << "\n";
	output << "Level: " << rhs.level << "\n";
	output << "Email: " << rhs.email;

	return output;
}

Student::Student()
{
	// initialize all data to default values - each will be assigned individually while reading in from csv file
	// new student will be declared in loop that iterates through the file and values will be given as read
	recordNumber = 0;
	studentID = 0;
	// all strings/vector of strings will be default constructed to the empty string through their own default constructors
	numberAbsences = 0;
	pNext = NULL;
}

Student::Student(int newRecordNumber, int newID, string newFn, string newLn, string newEmail, string newUnits,
				string newProgram, string newLevel)
{
	recordNumber = newRecordNumber;
	studentID = newID;
	firstName = newFn;
	lastName = newLn;
	email = newEmail;
	units = newUnits;
	program = newProgram;
	level = newLevel;
	numberAbsences = 0;
	// vector with absence dates is made empty
	pNext = NULL;
}

Student::Student(const Student &copyObject)
{
	recordNumber = copyObject.recordNumber;
	studentID = copyObject.studentID;
	firstName = copyObject.firstName;
	lastName = copyObject.lastName;
	email = copyObject.email;
	units = copyObject.units;
	program = copyObject.program;
	level = copyObject.level;
	numberAbsences = copyObject.numberAbsences;
	absenceDates = copyObject.absenceDates;
	pNext = copyObject.pNext;
}

Student::~Student()
{
	// doesn't need to do anything - list will take care of dynamic memory
}

int Student::getRecordNumber() const
{
	return recordNumber;
}

int Student::getID() const
{
	return studentID;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

string Student::getEmail() const
{
	return email;
}

string Student::getUnits() const
{
	return units;
}

string Student::getProgram() const
{
	return program;
}

string Student::getLevel() const
{
	return level;
}

int Student::getNumAbsences() const
{
	return numberAbsences;
}

string Student::getAbsenceDate(int absenceNumber) const
{
	string result;

	if (absenceNumber <= numberAbsences) // makes sure absenceNumber doesn't go beyond bounds of vector
	{
		result = absenceDates[absenceNumber-1];
	}
	else
	{
		result = "Invalid absence number.";
	}

	return result;
}

Student * Student::getNextPtr() const
{
	return pNext;
}

void Student::setRecordNumber(int newNumber)
{
	recordNumber = newNumber;
}

void Student::setID(int newID)
{
	studentID = newID;
}

void Student::setFirstName(string newFirstName)
{
	firstName = newFirstName;
}

void Student::setLastName(string newLastName)
{
	lastName = newLastName;
}

void Student::setEmail(string newEmail)
{
	email = newEmail;
}

void Student::setUnits(string newUnits)
{
	units = newUnits;
}

void Student::setProgram(string newProgram)
{
	program = newProgram;
}

void Student::setLevel(string newLevel)
{
	level = newLevel;
}

void Student::setAbsenceDate(string newDate, int absenceNumber)
{
	if (absenceNumber <= numberAbsences)
	{
		absenceDates[absenceNumber-1] = newDate;
	}
}

void Student::setNextPtr(Student *newPtr)
{
	pNext = newPtr;
}

Student & Student::operator =(Student &rhs)
{
	recordNumber = rhs.recordNumber;
	studentID = rhs.studentID;
	firstName = rhs.firstName;
	lastName = rhs.lastName;
	email = rhs.email;
	units = rhs.units;
	program = rhs.program;
	level = rhs.level;
	numberAbsences = rhs.numberAbsences;
	absenceDates = rhs.absenceDates;
	pNext = rhs.pNext;

	return *this;
}

void Student::addNewAbsence(string absenceDate)
{
	absenceDates.push_back(absenceDate);
	numberAbsences++;
}

void Student::deleteAbsence(int absenceNumber)
{
	if (numberAbsences > 0)
	{
		absenceDates.erase(absenceDates.begin() + (absenceNumber-1)); // deletes element at index [absenceNumber-1]
		numberAbsences--;
	}
}