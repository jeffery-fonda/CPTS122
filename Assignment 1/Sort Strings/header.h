#define _CRT_SECURE_NO_WARNINGS

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_program (char *names[], int length);
char sort_strings_descending (char *names[], int length);
char sort_strings_ascending (char *names[], int length);

#endif