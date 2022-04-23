#define _CRT_SECURE_NO_WARNINGS
#include "artist.h"

struct songify* add_album(struct songify* a, struct artist b, struct album c)
{
    struct artist* find=a->artists;
    struct album* find2;//מצביע לאלבום
    while (find != NULL && strcmp(find->name,b.name) != 0){
        find=find->next;
    }
    if (find==NULL)
    {
        puts("artist not found");
        return a;
    }
    struct album *elem=(struct album*)malloc(sizeof(struct album));
    find2=find->albums;
    elem->name = (char*)malloc(sizeof(char) * 100);
    strcpy(elem->name,c.name);
    elem->songs=c.songs;
    elem->next=NULL;

    if (find->albums==NULL)
    {
        find->albums=elem;
    }
    else
    {
        while (find2->next != NULL)
        {
            find2=find2->next;
        }
        find2->next=elem;
        
    }
    return a;
}
void print_albums(struct songify*a, struct artist b)
{
    struct artist* find=a->artists;
    struct album* find2;
    while (find != NULL && strcmp(find->name,b.name) != 0)
    {
        find=find->next;
    }
    if (find==NULL)
    {
        puts("artist not found");
        return;
    }
    find2=find->albums;
    printf("Artist: %s ",b.name);
    if (find2 == NULL)
    {
        puts("Dnot have albums");
        return;
    }
    while (find2 != NULL)
    {
        puts(find2->name);
        find2=find2->next;

    }
    
}