/*
Programmer: Jeffery Fonda
Class: CptS 122, Spring 2015; Lab Section 5
Programming Assignment: Assignment 3
Date: Febuary 9, 2015
Description: This program converts from infix to postfix. The evaluation of
the postfix expression doesn't work correctly. The result isn't getting 
pushed back to the stack. And I get this odd ÿ character. Added a special case 
for that one. Answer doesn't evaluate correctly. Extra time from Andy because I was sick.
*/

#include "header.h"

int main (void)
{
	struct infix ptr_head;
    char expression[MAX];
	double solution = 0;

	initinfix (&ptr_head); // makes the struct

    printf ("Enter an expression in infix form: \n"); // allow you to enter any expression
	gets (expression); // scans in the expression

	setexpr (&ptr_head, expression); // sets expression to struct
	convert (&ptr_head); // conversion

	printf ("The postfix expression is: \n");
	show (ptr_head); // prints postfix expression
	system ("pause");

	setexpr (&ptr_head, ptr_head.target); // sets expression back to struct
	evaluatePostFixExpression (&ptr_head, ptr_head.target); // this is where it evaluates 

    return 0;
}