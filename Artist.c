#define _CRT_SECURE_NO_WARNINGS
#include "Artist.h"

struct songify* addAlbum(struct songify* s, struct Artist c, struct album a)
{
    struct Artist* run;
    run = get_artist(s->artists, c);
    if (run==NULL)
    {
        puts("artist not found");
        return s;
    }
    struct album *elem=(struct album*)malloc(sizeof(struct album));
    elem->name = (char*)malloc(sizeof(char) * 100);
    strcpy(elem->name,a.name);
    elem->songs=a.songs;
    elem->next = run->albums;
    run->albums = elem;
    return s;
}
void printAlbums(struct songify* s, struct Artist c)
{
    struct Artist* run=s->artists;
    struct album* run2;
    run = get_artist(s->artists, c);
    if (run==NULL)
    {
        puts("artist not found");
        return;
    }
    run2=run->albums;
    printf("Artist: %s ",c.name);
    if (run2 == NULL)
    {
        puts("Dnot have albums");
        return;
    }
    printf("albums:\n");
    while (run2 != NULL)
    {
        puts(run2->name);
        run2=run2->next;

    }
    
}