#define _CRT_SECURE_NO_WARNINGS
#include "song.h"
#include "songify.h"
#include "Artist.h"
#include "album.h"
#include <stdio.h>
#include <stdlib.h>
void print_menu() {
	printf("Add Artist = 1\n");
	printf("Add Album = 2\n");
	printf("Print Albums by Artist = 3\n");
	printf("Add song to album = 4\n");
	printf("Count songs of album = 5\n");
	printf("Length of all album = 6\n");
	printf("Play Song = 7\n");
	printf("Add song to favorite = 8\n");
}
void game() {
	char x;
	struct songify* a=(struct songify*)malloc(sizeof(struct songify));
	struct artist b;
	struct album c;
	struct song d;
	a->artists = NULL;
	b.name = (char*)malloc(sizeof(char) * 100);
	c.name = (char*)malloc(sizeof(char) * 100);
	d.name = (char*)malloc(sizeof(char) * 100);
	print_menu();
	x = getchar();
	getchar();
	while (x >= '1' && x <= '8') {
		switch (x) {
			case '1':
				printf("Enter artist name\n");
				b.name = gets(b.name);
				printf("Enter activity years start and end\n");
				scanf("%d %d", &b.active.firstYear,&b.active.lastYear);
				getchar();
				b.next = NULL;
				b.albums = NULL;
				add_artist(a, b);
				printf("Artist add succeeded\n");
				break;
			case '2':
				printf("Enter artist name\n");
				b.name = gets(b.name);
				printf("Enter album name\n");
				c.name = gets(c.name);
				c.next = NULL;
				c.songs = NULL;
				add_album(a, b, c);
				printf("Add album succeded\n");
				break;
			case '3':
				printf("Enter artist name\n");
				b.name = gets(b.name);
				print_albums(a,b);
				printf("Print albums succeded\n");
				break;
			case '4':
				printf("Enter artist name\n");
				b.name = gets(b.name);
				printf("Enter album name\n");
				c.name = gets(c.name);
				printf("Enter song name\n");
				d.name = gets(d.name);
				printf("Enter song length\n");
				scanf("%d", &d.length);
				getchar();
				printf("Enter song id\n");
				scanf("%d", &d.id);
				getchar();
				d.next = NULL;
				d.liked = false;
				d.timePlayed = 0;
				add_song_to_album(a, b, c, d);
				printf("Add song to album succeded\n");
				break;
			case '5':
				printf("Enter artist name\n");
				b.name = gets(b.name);
				printf("Enter album name\n");
				c.name = gets(c.name);
				printf("Count songs of album = %d\n", number_songs_of_album(a, b, c));
				printf("count songs succeded\n");
				break;
			case '6':
				printf("Enter artist name\n");
				b.name = gets(b.name);
				printf("Enter album name\n");
				c.name = gets(c.name);
				printf("length of album = %d\n", len_of_album(a, b, c));
				printf("length of album succeded\n");
				break;
			case '7':
				printf("Enter artist name\n");
				b.name = gets(b.name);
				printf("Enter album name\n");
				c.name = gets(c.name);
				printf("Enter song id\n");
				scanf("%d", &d.id);
				getchar();
				play_song(a, b, c, d);
				printf("play song succeded\n");
				break;
			case '8':
				printf("Enter artist name\n");
				b.name = gets(b.name);
				printf("Enter album name\n");
				c.name = gets(c.name);
				printf("Enter song id\n");
				scanf("%d", &d.id);
				getchar();
				add_song_to_fav(a, b, c, d);
				printf("Add song to favorite succeded\n");
				break;
		}
		print_menu();
		x = getchar();
		getchar();
	}
	printf("Good Bye");
	getchar();
}
void main() {
	game();
}