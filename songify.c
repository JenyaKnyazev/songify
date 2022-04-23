#define _CRT_SECURE_NO_WARNINGS
#include "songify.h"
#include <string.h>
struct songify* add_artist(struct songify* a, struct  artist b)
{
    struct artist* find2;
    struct artist* find =(struct artist*)malloc(sizeof(struct artist));
    find->name = (char*)malloc(sizeof(char) * 100);
    strcpy(find->name,b.name);
    find->active.firstYear=b.active.firstYear;
    find->active.lastYear=b.active.lastYear;
    find->albums=b.albums;
    find->next=NULL;
    if (a == NULL)
    {
        a=(struct songify*)malloc(sizeof(struct songify));

    }
    
    if (a->artists==NULL)
    {
        a->artists=find;

    }
    else
    {
        find2=a->artists;
        while (find2->next != NULL)
        {
            find2=find2->next;
        }
        find2->next=find;
    }
    return a;
}