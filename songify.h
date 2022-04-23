#ifndef SONGIFY_H
#define SONGIFY_H

#ifndef ARTIST_H
#include "artist.h"
#endif

#include <stdlib.h>

struct songify 
{
    struct artist* artists;
};
struct songify* add_artist(struct songify* a, struct artist b);
#endif