#define _CRT_SECURE_NO_WARNINGS

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

struct queueNode 
{ 
	int cust_n; 
	int serv_t; 
	int arr_t; 
	struct queueNode *nextPtr; 
}; 

typedef struct queueNode customer; 
typedef customer *customerPtr; 

void printQueue (customerPtr currentPtr);
int isEmpty (customerPtr headPtr);
void dequeue (customerPtr *headPtr, customerPtr *tailPtr);
void enqueue (customerPtr *headPtr, customerPtr *tailPtr,int cust_n,int serv_t,int arr_t);

#endif