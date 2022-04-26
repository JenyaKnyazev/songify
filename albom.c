#define _CRT_SECURE_NO_WARNINGS
#include "albom.h"
#include <string.h>

struct songify* addSongToAlbum(struct songify* s, struct Artist b, struct album a , struct song c )
{
    struct Artist* run;
    struct album* run2;
    struct song* elem;
    run = get_artist(s->artists,b);
    if (run==NULL)
    {
        puts("artist not found");
        return s;
    }

    run2=get_album(run->albums,a);
    if (run2==NULL)
    {
        puts("album not found ");
        return s;
    }
    elem=(struct song*)malloc(sizeof(struct song));
    elem->id=c.id;
    elem->name = (char*)malloc(sizeof(char) * 100);
    strcpy(elem->name,c.name);
    elem->length=c.length;
    elem->timePlayed=c.timePlayed;
    elem->liked=c.liked;
    elem->next = run2->songs;
    run2->songs = elem;
    return s;
}


int numberSongsOfAlbum(struct songify* s, struct  Artist b, struct album a )
{
    
    struct Artist* run;
    struct album* run2;
    struct song* run3;
    int sum=0;
    run = get_artist(s->artists, b);
    if (run==NULL)
    {
        puts("artist not found");
        return -1;
    }
    run2 = get_album(run->albums, a);
    if (run2==NULL)
    {
        puts("album not found ");
        return -1;
    }
    run3=run2->songs;
    while (run3 != NULL)
    {
        sum++;
        run3=run3->next;
    }
    return sum;
}

int lenOfAlbum(struct songify* s , struct  Artist a , struct album b)
{
    struct Artist* run=s->artists;
    struct album* run2;
    struct song* run3;
    int sum=0;
    run = get_artist(s->artists, a);
    if (run == NULL)
    {
        puts("artist not found");
        return -1;
    }
    run2 = get_album(run->albums, b);
    if (run2 == NULL)
    {
        puts("album not found ");
        return -1;
    }
    run3 = run2->songs;
    while (run3 != NULL)
    {
        sum+=run3->length;
        run3=run3->next;
    }
    return sum;
}