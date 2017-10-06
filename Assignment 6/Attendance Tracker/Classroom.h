#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "StudentNode.h"

class Classroom
{
	friend class Student;
	friend class Menu;

	public:

		Classroom();
		Classroom(Classroom &copyObject);
		~Classroom();

		// Make

		Student *makeStudent(int ID, int Record, string name1, string name2, string email, string major, string Year, string Credits);
		bool insert(int ID, int Record, string name1, string name2, string email, string major, string Year, string Credits);

		bool markAbsences (Student* pFirst, int absense);
		Student *generateReport(Student* pFirst, int absense, string date);

	private:
		Student *mpFirst;
};

#endif