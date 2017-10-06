/*Programmer: Jeffery Fonda
Class: CptS 122, Spring 2015; Lab Section 5
Programming Assignment: Assignment 1, Part 3
Date: January 21, 2015
Description: This program checks if a string is a palindrome using recursion.
*/

#include "header.h"

int main (void)
{
	char string[25];
 
    printf ("Enter a string to check if it is a palindrome: \n");
    gets (string);
	remove_puncuation_and_make_lower_case (string);
	printf ("Converted string: %s\n", string);
	is_it_palindrome (string, 0);

	return 0;
}