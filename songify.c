#define _CRT_SECURE_NO_WARNINGS
#include "songify.h"
#include <string.h>
struct songify* addArtist(struct songify* head, struct  Artist a)
{
    struct Artist* run2;
    struct Artist* run=(struct Artist*)malloc(sizeof(struct Artist));
    run->name = (char*)malloc(sizeof(char) * 100);
    strcpy(run->name,a.name);
    run->active.firstYear=a.active.firstYear;
    run->active.lastYear=a.active.lastYear;
    run->albums=a.albums;
    if (head == NULL)
    {
        head=(struct songify*)malloc(sizeof(struct songify));
        head->artists = NULL;
    }
    run->next = head->artists;
    head->artists = run;
    return head;
}