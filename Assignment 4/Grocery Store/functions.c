#include "header.h"

void enqueue (customerPtr *headPtr, customerPtr *tailPtr,int cust_n,int serv_t,int arr_t) 
{ 
	customerPtr newPtr; 
	newPtr = malloc( sizeof( customer ) );
	if ( newPtr != NULL ) 
	{ 
		newPtr->cust_n = cust_n; 
		newPtr->serv_t = serv_t; 
		newPtr->arr_t = arr_t; 
		newPtr->nextPtr = NULL; 
		if ( isEmpty( *headPtr ) )
		{
			*headPtr = newPtr; 
		}
		else 
		{
			( *tailPtr )->nextPtr = newPtr;
			*tailPtr = newPtr; 
		}
	} 
	else 
	{
		printf("No memory available.\n"); 
	}
}

void dequeue (customerPtr *headPtr, customerPtr *tailPtr) 
{ 
	customerPtr tempPtr; 
	
	tempPtr = *headPtr; 
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
	{
		*tailPtr = NULL; 
		free (tempPtr); 
	}
}

int isEmpty (customerPtr headPtr) 
{ 
	return headPtr == NULL; 
} 

void printQueue (customerPtr currentPtr) 
{ 
	if (currentPtr == NULL) 
	{
		printf ("Queue is empty.\n\n");
	}
	else 
	{ 
		printf ("The queue is:\n");
		while (currentPtr != NULL) 
		{ 
			printf ("%d <-- ", currentPtr->cust_n); 
			currentPtr = currentPtr->nextPtr; 
		} 
		printf ("NULL\n\n"); 
	} 
}