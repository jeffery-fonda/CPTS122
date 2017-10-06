#include "header.h"

void run_program (char *names[], int length) // function runs program, reduces code in main
{
	char option = '\0';

	do {
		printf ("Please enter 'A' for ascending order.\n");
		printf ("Please enter 'D' for descending order.\n");
		printf ("Enter 'C' to close program.\n");
		scanf ("%c", &option);

		switch (option) {
		case 'A': sort_strings_ascending (names, length);
		break;
		case 'D': sort_strings_descending (names, length);
		break;
		case 'C': printf ("Exiting program...\n");
				  exit(0);
		default:  printf ("Invalid input.\n");
		}
		system ("pause");
		system ("cls");
	} while (option != 'C');
}

char sort_strings_descending (char *names[], int length) // sorts string in decending order
{
	const char *string1, *string2;
	char* temp;
	int list, index, index2;
    
	length = 6;

	printf ("List of names to be sorted: \n"); // prints list of unsorted names

	for (index = 0; index < length; index++)
	{
		printf ("%s ", names[index]);
	}

	printf ("\n");
	printf ("Sorted names: \n");
    
	for (index = 0; index < length; index++)
	{
        for (index2 = index + 1; index2 < length; index2++)
		{
            string1 = names[index]; // Dscending order
            string2 = names[index2];
            list = 0;

            while (*string1 && *string2)
			{              
                if(*string1 != *string2)
				{               
                    list = *string1 - *string2;     
                    break;                   
                }                           
                ++string1;
                ++string2;
            }
            if (list > 0 || (list == 0 && *string1))
			{
                temp = names[index];
                names[index] = names[index2];
                names[index2] = temp;
            }
        }
        printf("%s ", names[index]);
    }
    printf("\n");
}

char sort_strings_ascending (char *names[], int length) // sorts string in ascending order
{
	const char *string1, *string2;
	char* temp;
	int list, index, index2;
    
	length = 6;

	printf ("List of names to be sorted: \n"); // prints unsorted list

	for (index = 0; index < length; index++)
	{
		printf ("%s ", names[index]);
	}

	printf ("\n");
	printf ("Sorted names: \n");
    
	for (index = 0; index < length; index++)
	{
        for (index2 = index + 1; index2 < length; index2++)
		{
            string1 = names[index2]; // Ascending order, switched contents of string1 with string2
            string2 = names[index];
            list = 0;

            while (*string1 && *string2)
			{              
                if(*string1 != *string2)
				{               
                    list = *string1 - *string2;     
                    break;                   
                }                           
                ++string1;
                ++string2;
            }
            if (list > 0 || (list == 0 && *string1))
			{
                temp = names[index];
                names[index] = names[index2];
                names[index2] = temp;
            }
        }
        printf("%s ", names[index]);
    }
    printf("\n");
}