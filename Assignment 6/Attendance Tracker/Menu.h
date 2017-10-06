#ifndef MENU_H
#define MENU_H

#include "Classroom.h"
#include "StudentNode.h"

class Menu
{
	friend class Student;
	friend class Classroom;

	public:
		Menu ();
		Menu (int newmOption);
 
		//Copy constructor
		Menu (Menu &copyObject);

		//Destructor
  		~Menu ();
		//this should just get options
		//Getters
		int getOption () const;

		//Setters
		void setOption (int newmOption);

		void display_menu ();
		bool importCourseList();

	private:
		int mOption;
};

#endif