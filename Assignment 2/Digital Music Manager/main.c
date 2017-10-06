//Programmer: Jeffery Fonda
//Class: CptS 122, Spring 2015; Lab Section 5
//Programming Assignment: Assingment 2
//Date: January 31st, 2015
//Description: This is a digital music manager. It does not work. I spent every minute I could with a tutor to get
// it to work but I physically could not complete it. It does build but could not figure out the linked list. 

#include "header.h"

int main (void)
{
	char *artist_name = 0; char *album_name = 0; char *song_name = 0; char *genre = 0;
	int minutes = 0; int seconds = 0; int times_played = 0; int rating = 0;
	Track *ptr_track;
	Track *ptr_head = NULL;

	FILE* input_file = NULL;
	FILE* output_file = NULL;

	ptr_track = (Track *) malloc (sizeof (Track));

	run_program (artist_name, album_name, song_name, genre, minutes, 
				seconds, times_played, rating, input_file, output_file, ptr_track);

	return 0;
}