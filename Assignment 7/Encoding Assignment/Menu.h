#ifndef MENU_H
#define MENU_H

#define _CRT_SECURE_NO_WARNINGS

#include "Cipher.h"

class Menu
{
	friend class Cipher;
	friend class Caesar;
	friend class Sub;

	public:
		Menu ();
		~Menu ();

		void main_menu ();

	private:
		// I prefer to use local variables for the menu instead of a member variable
		// I am satisfying the requirements of having a class for the menu though
};

#endif