#include "header.h"

void run_program (char *artist_name, char *album_name, char *song_name, char *genre, 
				  int minutes, int seconds, int times_played, int rating, FILE *input_file, FILE *output_file, Track *ptr_track)
{
	int option = 1;

	input_file = fopen ("records.txt", "r");
	output_file = fopen ("records_updated.txt", "w");

	do
	{
		system ("cls");
		printf ("This is a Digital Music Manager\n");
		printf ("\n");
		printf ("1. Load Track\n");
		printf ("\n");
		printf ("2. Store Track\n");
		printf ("\n");
		printf ("3. Display Track\n");
		printf ("\n");
		printf ("4. Insert Track\n");
		printf ("\n");
		printf ("5. Delete Track\n");
		printf ("\n");
		printf ("6. Edit Track\n");
		printf ("\n");
		printf ("7. Sort Tracks\n");
		printf ("\n");
		printf ("8. Rate Track\n");
		printf ("\n");
		printf ("9. Exit Program\n");
		printf ("\n");
		printf ("Enter option: ");
		scanf ("%d", &option);

		switch (option) {
		case 1: load_track (artist_name, album_name, song_name, genre, minutes, seconds, times_played, rating, input_file);
		break;
		case 2: store_track (artist_name, album_name, song_name, genre, minutes, seconds, times_played, rating, output_file, ptr_track);
		break;
		case 3: display_track (ptr_track);
		break;
		case 4: insert_track ();
		break;
		case 5: delete_track ();
		break;
		case 6: edit_track ();
		break;
		case 7: sort_tracks (artist_name, album_name, song_name, genre, minutes, seconds, times_played, rating, input_file, output_file, ptr_track);
		break;
		case 8: rate_track ();
		break;
		case 9: exit_program ();
		break;
		default: printf ("Invalid choice.\n");
		}
		system ("pause");
		system ("cls");
	} while (option != 9);
}

Track *make_track_node (char *artist_name, char *album_name, char *song_name, char *genre, 
						int minutes, int seconds, int times_played, int rating)
{
	Track *ptr_mem = NULL;

	// 1. dynamically allocate memory - malloc ()
	ptr_mem = (Track *) malloc (sizeof (Track)); // heap

	// 2. initialize
	ptr_mem -> artist_name = (char *) malloc (sizeof (char) * (strlen (artist_name) + 1));
	strcpy (ptr_mem -> artist_name, artist_name);
	ptr_mem -> album_name = (char *) malloc (sizeof (char) * (strlen (album_name) + 1));
	strcpy (ptr_mem -> artist_name, album_name);
	ptr_mem -> song_name = (char *) malloc (sizeof (char) * (strlen (song_name) + 1));
	strcpy (ptr_mem -> artist_name, song_name);
	ptr_mem -> genre = (char *) malloc (sizeof (char) * (strlen (genre) + 1));
	strcpy (ptr_mem -> artist_name, genre);
	ptr_mem -> minutes = minutes;
	ptr_mem -> seconds = seconds;
	ptr_mem -> times_played = times_played;
	ptr_mem -> rating = rating;
	ptr_mem -> track_prev = NULL;
	ptr_mem -> track_next = NULL;

	return ptr_mem;
}

void search_track (Track *ptr_track)
{
	int option = 0;
	int temp_times_played = 0, temp_rating = 0;
	char *temp_artist_name; 
	char *temp_album_name; char *temp_song_name; char *temp_genre;
 
	Track *temp_ptr = ptr_track;

	do
	{
		system ("cls");
		printf ("Search Tracks by:\n");
		printf ("\n");
		printf ("1. Artist Name\n");
		printf ("\n");
		printf ("2. Album Name\n");
		printf ("\n");
		printf ("3. Song Name\n");
		printf ("\n");
		printf ("4. Genre\n");
		printf ("\n");
		printf ("5. Times Played\n");
		printf ("\n");
		printf ("6. Rating\n");
		printf ("\n");
		scanf ("%d", &option);

		if (option == 1)
		{
			system ("cls");
			printf ("Enter Artist Name to search by: ");
			scanf ("%s", &temp_artist_name);
			printf ("Tracks by this artist: \n");

			while (temp_ptr != NULL)
			{
				if (temp_ptr ->artist_name == temp_artist_name)
				{
					printf ("Song Name: %s\n", temp_ptr -> song_name);
					printf ("Artist Name: %s\n", temp_ptr -> artist_name);
					printf ("Album Name: %s\n", temp_ptr -> album_name);
					printf ("Genre : %s\n", temp_ptr -> genre);
					printf ("Song Length: %d:%d", temp_ptr -> minutes, temp_ptr -> seconds);
					printf ("Rating: %d", temp_ptr -> rating);
					return;
				}
				else
				{
					printf ("None found!");
					return;
				}
			}
		}
		if (option == 2)
		{
			system ("cls");
			printf ("Enter Album Name to search by: ");
			scanf ("%s", &temp_album_name);
			printf ("Albums from this artist: \n");

			while (temp_ptr != NULL)
			{
				if (temp_ptr ->album_name == temp_album_name)
				{
					printf ("Song Name: %s\n", temp_ptr -> song_name);
					printf ("Artist Name: %s\n", temp_ptr -> artist_name);
					printf ("Album Name: %s\n", temp_ptr -> album_name);
					printf ("Genre : %s\n", temp_ptr -> genre);
					printf ("Song Length: %d:%d", temp_ptr -> minutes, temp_ptr -> seconds);
					printf ("Rating: %d", temp_ptr -> rating);
					return;
				}
				else
				{
					printf ("None found!");
					return;
				}
			}
		}
		if (option == 3)
		{
			system ("cls");
			printf ("Enter Song Name to search by: ");
			scanf ("%s", &temp_song_name);
			printf ("Tracks with this song name: \n");

			while (temp_ptr != NULL)
			{
				if (temp_ptr ->song_name == temp_song_name)
				{
					printf ("Song Name: %s\n", temp_ptr -> song_name);
					printf ("Artist Name: %s\n", temp_ptr -> artist_name);
					printf ("Album Name: %s\n", temp_ptr -> album_name);
					printf ("Genre : %s\n", temp_ptr -> genre);
					printf ("Song Length: %d:%d", temp_ptr -> minutes, temp_ptr -> seconds);
					printf ("Rating: %d", temp_ptr -> rating);
					return;
				}
				else
				{
					printf ("None found!");
					return;
				}
			}
		}
		if (option == 4)
		{
			system ("cls");
			printf ("Enter Genre to search by: ");
			scanf ("%s", &temp_genre);
			printf ("Tracks with this genre: \n");

			while (temp_ptr != NULL)
			{
				if (temp_ptr ->genre == temp_genre)
				{
					printf ("Song Name: %s\n", temp_ptr -> song_name);
					printf ("Artist Name: %s\n", temp_ptr -> artist_name);
					printf ("Album Name: %s\n", temp_ptr -> album_name);
					printf ("Genre : %s\n", temp_ptr -> genre);
					printf ("Song Length: %d:%d", temp_ptr -> minutes, temp_ptr -> seconds);
					printf ("Rating: %d", temp_ptr -> rating);
					return;
				}
				else
				{
					printf ("None found!");
					return;
				}
			}
		}
		if (option == 5)
		{
			system ("cls");
			printf ("Enter number Times Played to search by: ");
			scanf ("%d", &temp_times_played);
			printf ("Tracks played %d times: \n", temp_times_played);

			while (temp_ptr != NULL)
			{
				if (temp_ptr ->times_played == temp_times_played)
				{
					printf ("Song Name: %s\n", temp_ptr -> song_name);
					printf ("Artist Name: %s\n", temp_ptr -> artist_name);
					printf ("Album Name: %s\n", temp_ptr -> album_name);
					printf ("Genre : %s\n", temp_ptr -> genre);
					printf ("Song Length: %d:%d", temp_ptr -> minutes, temp_ptr -> seconds);
					printf ("Rating: %d", temp_ptr -> rating);
					return;
				}
				else
				{
					printf ("None found!");
					return;
				}
			}
		}
		if (option == 6)
		{
			system ("cls");
			printf ("Enter Rating to search by: ");
			scanf ("%d", &temp_rating);
			printf ("Tracks with %d rating: \n", temp_rating);

			while (temp_ptr != NULL)
			{
				if (temp_ptr ->rating == temp_rating)
				{
					printf ("Song Name: %s\n", temp_ptr -> song_name);
					printf ("Artist Name: %s\n", temp_ptr -> artist_name);
					printf ("Album Name: %s\n", temp_ptr -> album_name);
					printf ("Genre : %s\n", temp_ptr -> genre);
					printf ("Song Length: %d:%d", temp_ptr -> minutes, temp_ptr -> seconds);
					printf ("Rating: %d", temp_ptr -> rating);
					return;
				}
				else
				{
					printf ("None found!");
					return;
				}
			}
		}
	} while (option != 6);
}

void load_track (char *artist_name, char *album_name, char *song_name, char *genre, 
				 int minutes, int seconds, int times_played, int rating, FILE *input_file)
{
	//make_track_node (artist_name, album_name, song_name, genre, minutes, seconds, times_played, rating);

	printf ("Reading track from file...\n\n");
	fscanf (input_file, "%s", artist_name);
	fscanf (input_file, "%s", album_name);
	fscanf (input_file, "%s", song_name);
	fscanf (input_file, "%s", genre);
	fscanf (input_file, "%d", minutes);
	fscanf (input_file, "%d", seconds);
	fscanf (input_file, "%d", times_played);
	fscanf (input_file, "%d", rating);
	printf ("Track read: \n");
	printf ("Arist Name: %s\n", artist_name);
	printf ("Album Name: %s\n", album_name);
	printf ("Song Name: %s\n", song_name);
	printf ("Genre: %s\n", genre);
	printf ("Song Length: %d:%d\n", minutes, seconds);
	printf ("Times Played: %d\n", times_played);
	printf ("Rating: %d\n", rating);
}

void store_track (char *artist_name, char *album_name, char *song_name, char *genre, 
				 int minutes, int seconds, int times_played, int rating, FILE *output_file, Track *ptr_track)
{
	search_track (ptr_track);

	printf ("Saving track to file...\n\n");
	fprintf (output_file, "%s", artist_name);
	fprintf (output_file, "%s", album_name);
	fprintf (output_file, "%s", song_name);
	fprintf (output_file, "%s", genre);
	fprintf (output_file, "%d", minutes);
	fprintf (output_file, "%d", seconds);
	fprintf (output_file, "%d", times_played);
	fprintf (output_file, "%d", rating);
}

void display_track (Track *ptr_track)
{
	search_track (ptr_track);
}

void insert_track (char *artist_name, char *album_name, char *song_name, char *genre, 
				 int minutes, int seconds, int times_played, int rating, FILE *input_file, FILE *output_file, Track **ptr_head, Track *ptr_track)
{
	Track *ptr_mem = NULL, *ptr_prev = NULL, *ptr_next = NULL, *ptr_cur = NULL;

	printf ("Insert Track: \n");
	printf ("\n");

	//make_track_node (artist_name, album_name, song_name, genre, minutes, seconds, times_played, rating);

	printf ("Enter Arist Name: \n");
	scanf ("%s", artist_name);
	printf ("Enter Album Name: \n");
	scanf ("%s", album_name); 

	//*ptr_head = sort_tracks (artist_name, album_name, song_name, genre, minutes, seconds, times_played, rating, input_file, output_file, ptr_track);

	/*if (*ptr_head == NULL)
	{
		*ptr_head = ptr_mem;
	}
	else
	{
		ptr_cur = *ptr_head;

		while (ptr_cur != NULL && ((ptr_cur -> artist_name) < (ptr_mem -> artist_name)))
		{
			ptr_cur = ptr_cur -> track_next;
		}
		ptr_cur -> track_next = ptr_mem;
		ptr_mem -> track_next = ptr_cur;
		ptr_mem -> track_prev = ptr_cur -> track_prev;
		ptr_cur -> track_prev = ptr_mem;
	}*/
}

void delete_track (void)
{
	printf ("Deleting track.\n");

	// in this function, you would first update the pointers, copy the data to a file
	// and then you would free the data in the node, then the node itself
}

void edit_track (void)
{
	printf ("Editing track.\n");

	// in this function, you would update the contents of the struct
	// and then display them to the screen
}

Track *sort_tracks (char *artist_name, char *album_name, char *song_name, char *genre, 
				  int minutes, int seconds, int times_played, int rating, FILE *input_file, FILE *output_file, Track *ptr_track)
{
	int option = 0;

	do
	{
		system ("cls");
		printf ("Sorting options:\n");
		printf ("\n");
		printf ("1. Default (Artist Name)\n");
		printf ("\n");
		printf ("2. Album\n");
		printf ("\n");
		printf ("3. Genre\n");
		printf ("\n");
		printf ("4. Rating\n");
		printf ("\n");
		printf ("5. Main Menu\n");
		printf ("\n");
		printf ("Enter option: ");
		scanf ("%d", &option);

		if (option == 1)
		{
			
		}
		if (option == 2)
		{

		}
		if (option == 3)
		{

		}
		if (option == 4)
		{

		}
		if (option == 5)
		{
			run_program (artist_name, album_name, song_name, genre, minutes, 
				seconds, times_played, rating, input_file, output_file, ptr_track);
		}
		system ("pause");
		system ("cls");
	} while (option != 5);
}

void rate_track (void)
{
	printf ("Rating track.\n");

	// search for track
	// update the rating

	// this function would update the rating of any track after first searching for the track
}

void exit_program (void)
{
	// this function would save all of the current tracks to a file

	printf ("Exiting program.\n");
	exit (0);
}