#ifndef ALBOM
#define ALBOM
#include <stdio.h>
#include <stdlib.h>
#include "songify.h"
#include "song.h"
#include "Artist.h"
#include "albom.h"
#include "rec.h"
struct album
{
    char* name;
    struct song* songs; //A LinkedList of songs
    struct album* next;
};

struct songify* addSongToAlbum(struct songify* s , struct Artist b, struct album a, struct song c);
int numberSongsOfAlbum(struct songify* s, struct Artist b, struct album a);
int lenOfAlbum(struct songify*  s, struct Artist  a, struct album b);
#endif