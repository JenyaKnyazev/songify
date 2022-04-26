#include "Artist.h"
#include "albom.h"
#include "song.h"
#include "songify.h"
#include <string.h>
#include <stdio.h>
#ifndef REC_H
#define REC_H

struct Artist* get_artist(struct Artist* head,struct Artist a);
struct album* get_album(struct album* head, struct album a);
struct song* get_song(struct album* head, struct song a);
void free_memory(struct songify* s);
#endif