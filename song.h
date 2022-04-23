#ifndef SONG_H
#define SONG_H

#include "artist.h"
#include <stdio.h>
#include <string.h>

enum bool
{
    false=0,
    true=1
};
 

struct song
{
    int id;
    char* name;
    int length ;//The length of the song in seconds
    int timePlayed;//How many times the song have been played
    enum bool liked; //The user liked the song
    struct song_t* next;
};

 void play_song(struct songify* a, struct artist b, struct album c, struct song d);
 void add_song_to_fav(struct songify* a, struct artist b, struct album c, struct song d);
#endif