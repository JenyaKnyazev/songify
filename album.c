#define _CRT_SECURE_NO_WARNINGS
#include "album.h"
#include <string.h>

struct songify* add_song_to_album(struct songify* a, struct artist b, struct album c , struct song d )
{
    struct artist* find=a->artists;
    struct album* find2;
    struct song* find3;
    struct song* elem;
    while (find != NULL && strcmp(find->name,b.name) != 0)
    {
        find=find->next;
    }
    if (find==NULL)
    {
        puts("artist not found");
        return a;
    }

    find2=find->albums;
    while (find2 != NULL && strcmp(find2->name,c.name) != 0)
    {
        find2=find2->next;
    }
    if (find2==NULL)
    {
        puts("album not found ");
        return a;
    }
    find3=find2->songs;
    elem=(struct song*)malloc(sizeof(struct song));
    elem->id=d.id;
    elem->name = (char*)malloc(sizeof(char) * 100);
    strcpy(elem->name,d.name);
    elem->length=d.length;
    elem->timePlayed=d.timePlayed;
    elem->liked=d.liked;
    elem->next=NULL;

    if (find2->songs==NULL)
    {
        find2->songs=elem;
        return a;
    }
    while (find3->next != NULL)
    {
        find3=find3->next;
    }
    find3->next=elem;
    return a;
}


int number_songs_of_album(struct songify* a, struct  artist b, struct album c )
{
    
    struct artist* find=a->artists;
    struct album* find2;
    struct song* find3;
    int sum=0;
    while (find != NULL && strcmp(find->name,b.name) != 0)
    {
        find=find->next;
    }
    if (find==NULL)
    {
        puts("artist not found");
        return -1;
    }

    find2=find->albums;
    while (find2 != NULL && strcmp(find2->name,c.name) != 0)
    {
        find2=find2->next;
    }
    if (find2==NULL)
    {
        puts("album not found ");
        return -1;
    }
    find3=find2->songs;
    while (find3 != NULL)
    {
        sum++;
        find3=find3->next;
    }
    return sum;
}

int len_of_album(struct songify* a , struct  artist b , struct album c)
{
    struct artist* find=a->artists;
    struct album* find2;
    struct song* find3;
    int sum=0;
    while (find != NULL && strcmp(find->name,b.name) != 0)
    {
        find=find->next;
    }
    if (find==NULL)
    {
        puts("artist not found");
        return -1;
    }

    find2=find->albums;
    while (find2 != NULL && strcmp(find2->name,c.name) != 0)
    {
        find2=find2->next;
    }
    if (find2==NULL)
    {
        puts("album not found ");
        return -1;
    }
    find3=find2->songs;
    while (find3 != NULL)
    {
        sum+=find3->length;
        find3=find3->next;
    }
    return sum;
}