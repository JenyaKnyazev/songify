#include "song.h"



void play_song(struct songify* a, struct artist b, struct album c, struct song d)
{
    
    struct artist* find=a->artists;
    struct album* find2;
    struct song* find3;
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
    while (find2 != NULL && strcmp(find2->name,c.name) != 0)
    {
        find2=find2->next;
    }
    if (find2==NULL)
    {
        puts("album not found");
        return;
    }
    
    find3=find2->songs;
    while (find3 != NULL && find3->id != d.id)
    {
        find3=find3->next;
    }
    if (find3==NULL)
    {
        puts("song not found");
        return;
    }
    find3->timePlayed++;
    printf("name song :%s,length %d: ,%s\n",find3->name,find3->length,(find3->liked) ? "favorite" : "not favorite");
}



void add_song_to_fav(struct songify* a, struct  artist b, struct album c , struct song d)
{
    struct artist* find=a->artists;
    struct album* find2;
    struct song* find3;
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
    while (find2 != NULL && strcmp(find2->name,c.name) != 0)
    {
        find2=find2->next;
    }
    if (find2==NULL)
    {
        puts("album not found");
        return;
    }
    
    find3=find2->songs;
    while (find3 != NULL && find3->id != d.id)
    {
        find3=find3->next;
    }
    if (find3==NULL)
    {
        puts("song not found");
        return;
    }
    find3->liked=true;

}