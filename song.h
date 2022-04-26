#ifndef SONG
#define SONG

#include "Artist.h"
#include <stdio.h>
#include <string.h>
#include "rec.h"
enum bool
{
    false,
    true
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

 void playSong(struct songify* s, struct Artist artist, struct album b, struct song c);
 void addSongFav(struct songify* s, struct Artist artist, struct album b, struct song c);
#endif