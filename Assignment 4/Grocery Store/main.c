/*
Programmer: Jeffery Fonda
Class: CptS 122, Spring 2015; Lab Section 5
Programming Assignment: Assignment 4
Date: Febuary 20, 2015
Description: This program is supposed to simulate a grocery store line. I didn't understand 
the actual program description so I followed the assignment out of the book. I'm well aware 
that this isn't the program we were supposed to write but I didn't have any time to talk to
a tutor. The program doesn't work. It errors out at line 60 in main. 
*/

#include "header.h"

int main (void)
{
	int i; 
	int t_time = 0; //track global time in secs 
	int t_arrival = 0; //track arrival time 
	int t_depart = -1; //track departure and time needed to serve last customer 
	int customer_n = 0; 
	int serv_time = 0; 
	int MAX_SERV_TIME = serv_time; 
	int tot_wait_t = 0;

	customerPtr headptr = NULL, tailptr = NULL;

	srand ((int)time(NULL));

	while (t_time != 10) 
	{ 
		printf ("Time: %d\n Max service time: %d\n Total wait time: %d\n", t_time, MAX_SERV_TIME, tot_wait_t); 
		
		if (t_time == t_depart && !isEmpty(headptr)) //its time to depart and list isn't empty 
		{ 
			printf ("customer %d ON\n\n", headptr->cust_n); 
			serv_time = headptr->serv_t; //present customer's service time 
			tot_wait_t += (t_time - headptr->arr_t); 
			dequeue(&headptr,&tailptr); //customer 'n' gets serviced

			if (!isEmpty(headptr))
			{
				t_depart = serv_time + t_time; // cutomer 'n+1' will get serviced at 
			}
		}

		if (t_time == t_arrival) //customer arrives
		{
			customer_n++;
			serv_time = rand()%4 + 1; //get service time
			MAX_SERV_TIME = (serv_time>MAX_SERV_TIME?serv_time:MAX_SERV_TIME);

			if (isEmpty(headptr))
			{
				t_depart = t_time + serv_time;
			}

			enqueue (&headptr,&tailptr,customer_n,serv_time,t_arrival); //customer joins the Q
			t_arrival += rand()%4 + 1;
			// messes up after the next line, no idea why
			printf ("Customer %d joins at %d\n Service time: %d\n", tailptr->cust_n, tailptr->arr_t, tailptr->serv_t);
		}

		printQueue (headptr); 
		getchar(); 
		t_time++;
	}

	customer_n = (tailptr->cust_n - headptr->cust_n)+ 1; //total no. of customers unserved 
	printf ("Average wait time = %d.\n Max service time = %d.\n Total customers unserved %d.\n\n", tot_wait_t/customer_n, MAX_SERV_TIME, customer_n); 
	
	for(i = 0;i<customer_n;i++) 
	{ 
		//puts("TEST"); 
		printQueue(headptr); 
		getchar();
		dequeue(&headptr,&tailptr); 
	} 
	//printQueue(headptr);


	return 0;
}