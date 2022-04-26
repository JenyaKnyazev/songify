


#ifndef ARTIST
#define ARTIST

#ifndef SONGIFY
#include "songify.h"
#endif
#include "rec.h"
#include "albom.h"
#include <stdlib.h>
typedef struct 
{
    int firstYear;
    int lastYear; // 0 == still active
}activeYears;

struct Artist
{
    char* name; //A LinkedList of
    activeYears active;
    struct album* albums; //A LinkedList of albums
    struct Artist* next;
};

struct songify* addAlbum(struct songify* s , struct Artist c, struct album a);
void printAlbums(struct songify* s, struct Artist c);
#endif