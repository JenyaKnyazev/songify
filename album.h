#ifndef ALBUM_H
#define ALBUM_H
#include <stdio.h>
#include <stdlib.h>
#include "songify.h"
#include "song.h"
#include "Artist.h"
#include "album.h"
struct album
{
    char* name;
    struct song* songs; //A LinkedList of songs
    struct album* next;
};

struct songify* add_song_to_album(struct songify* a , struct artist b, struct album c, struct song d);
int number_songs_of_album(struct songify* a, struct artist b, struct album c);
int len_of_album(struct songify*  a, struct artist  b, struct album c);
#endif