#define _CRT_SECURE_NO_WARNINGS

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *artist_name;
	char *album_name;
	char *song_name;
	char *genre;
	int minutes;
	int seconds;
	int times_played;
	int rating;

	struct Track *track_prev;
	struct Track *track_next;
} Track;

// Main Functions

void run_program (char *artist_name, char *album_name, char *song_name, char *genre, 
				int minutes, int seconds, int times_played, int rating, FILE *input_file, FILE *output_file, Track *ptr_track);
void load_track (char *artist_name, char *album_name, char *song_name, char *genre, 
				int minutes, int seconds, int times_played, int rating, FILE *input_file);
void store_track (char *artist_name, char *album_name, char *song_name, char *genre, 
				 int minutes, int seconds, int times_played, int rating, FILE *output_file, Track *ptr_track);
void display_track (Track *ptr_track);
void insert_track (void);
void delete_track (void);
void edit_track (void);
Track *sort_tracks (char *artist_name, char *album_name, char *song_name, char *genre, 
				  int minutes, int seconds, int times_played, int rating, FILE *input_file, FILE *output_file, Track *ptr_track);
void rate_track (void);
void exit_program (void);
void search_track (Track *ptr_track);

// Sort Functions

void sort_track_artist (void);
void sort_track_album (void);
void sort_track_genre (void);
void sort_track_rating (void);

// List Functions

Track *make_track_node (char *artist_name, char *album_name, char *song_name, 
						char *genre, int minutes, int seconds, int times_played, int rating);
Track *make_list (Track **ptr_head);

#endif