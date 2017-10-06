#include "header.h"

void run_program (char *string) // this function runs the program, tried to reduce code in main.c
{
	printf ("String to encode: \n%s\n", string);
	convert_string (string);
	printf ("Converted string: \n%s\n", string);
	encode_string (string);
	printf ("Encoded string: \n%s\n", string);
	decode_string (string);
	printf ("String decoded: \n%s\n", string);
}

void convert_string (char *string) // takes string and removes puncuation and convert to uppercase
{
	char *destination = string, *source = string;

	while (*source)
	{
		if (ispunct((char)*source)) // skip puncuation
		{
			source++;
		}
		else if (islower((char)*source)) // convert to uppercase
		{
			*destination++ = toupper((char)*source);
			source++;
		}
		else if (source == destination)
		{
			source++;
			destination++;
		}
		else // copy string
		{
		   *destination++ = *source++;
		}
	}
    *destination = 0;
}

void encode_string (char *string) // encodes the string
{
	char *destination = string, *source = string;
	int index = 0, length = 0, shift_number = 0, temp = 0;

	printf ("Please enter number to shift string: ");
	scanf ("%d", &shift_number);

	length = strlen (string);

	for (index = 0; index < length; index++)
	{
		if (isspace((char)(*source)))
		{
			source++;
			destination++;
		}
		else if (shift_number + *source > 90) // for letters towards the end of the range
		{
			temp = (shift_number + *source + 65 - 26) % 26;
			*destination = temp + 65;
			destination++;
			source++;
		}
		else if (shift_number + *source < 65) // for letters near the beginning of the range
		{
			temp = (shift_number + *source - 65 + 26) % 26;
			*destination = 65 + temp;
			destination++;
			source++;
		}
		else // middle numbers
		{
			*source = shift_number + *source;
			destination++;
			source++;
		}
	}
	*destination = 0;
}

void decode_string (char *string) // decodes the string, must enter the negative shift number
{
	char *destination = string, *source = string;
	int index = 0, length = 0, shift_number = 0, temp = 0;

	printf ("Please enter number to shift string back, must be the opposite: ");
	scanf ("%d", &shift_number);

	length = strlen (string);

	for (index = 0; index < length; index++)
	{
		if (isspace((char)(*source)))
		{
			source++;
			destination++;
		}
		else if (shift_number + *source > 90) // for letters towards the end of the range
		{
			temp = (shift_number + *source + 65 - 26) % 26;
			*destination = temp + 65;
			destination++;
			source++;
		}
		else if (shift_number + *source < 65) // for letters near the beginning of the range
		{
			temp = (shift_number + *source - 65 + 26) % 26;
			*destination = 65 + temp;
			destination++;
			source++;
		}
		else // middle numbers
		{
			*source = shift_number + *source;
			destination++;
			source++;
		}
	}
	*destination = 0;
}