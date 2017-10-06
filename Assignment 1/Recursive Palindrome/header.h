#define _CRT_SECURE_NO_WARNINGS

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void remove_puncuation_and_make_lower_case (char *string);
void is_it_palindrome (char string[], int index);

#endif