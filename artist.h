


#ifndef ARTIST_H
#define ARTIST_H

#ifndef SONGIFY_H
#include "songify.h"
#endif

#include "album.h"
#include <stdlib.h>
typedef struct 
{
    int firstYear;
    int lastYear; // 0 == still active
}activeYears;

struct artist
{
    char* name; //A LinkedList of
    activeYears active;
    struct album* albums; //A LinkedList of albums
    struct artist* next;
};

struct songify* add_album(struct songify* a , struct artist b, struct album c);
void print_albums(struct songify* a, struct artist b);
#endif