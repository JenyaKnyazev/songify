#ifndef SONGIFY
#define SONGIFY

#ifndef ARTIST
#include "Artist.h"
#endif

#include <stdlib.h>

struct songify 
{
    struct Artist* artists;
};
struct songify* addArtist(struct songify* head, struct Artist a);
#endif