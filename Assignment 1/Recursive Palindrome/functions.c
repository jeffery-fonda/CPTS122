#include "header.h"

void remove_puncuation_and_make_lower_case (char *string) // removes puncuation, spaces and convert to lowercase
{
    char *source = string, *destination = string;

    while (*source)
    {
       if (ispunct((char)*source)) // skip puncuation
       {
          source++;
       }
	   else if (isspace((char)*source)) // skip space
       {
          source++;
       }
       else if (isupper((char)*source)) // convert to lowercase
       {
          *destination++ = tolower((char)*source);
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

void is_it_palindrome (char string[], int index) // checks if string is a palindrome
{
    int length = strlen(string) - (index + 1);

    if (string[index] == string[length])
    {
        if (index + 1 == length || index == length)
        {
            printf ("The entered string is a palindrome.\n");
            return;
        }
		is_it_palindrome (string, index + 1); // recursive step
    }
    else
    {
        printf ("The entered string is not a palindrome.\n");
    }
}