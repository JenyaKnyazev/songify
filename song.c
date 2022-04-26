#include "song.h"



void playSong(struct songify* s, struct Artist artist, struct album b, struct song c)
{
    
    struct Artist* run;
    struct album* run2;
    struct song* run3;
    run = get_artist(s->artists, artist);
    if (run==NULL)
    {
        puts("artist not found");
        return;
    }

    run2 = get_album(run->albums, b);
    if (run2==NULL)
    {
        puts("album not found");
        return;
    }
    
    run3 = get_song(run2->songs, c);
    if (run3==NULL)
    {
        puts("SONG NOT FOUND");
        return;
    }
    run3->timePlayed++;
    printf("name song :%s,length %d: ,%s\n",run3->name,run3->length,(run3->liked) ? "fave" : "not fave");
}



void addSongFav(struct songify* s, struct  Artist artist, struct album b , struct song c)
{
    struct Artist* run=s->artists;
    struct album* run2;
    struct song* run3;
    run = get_artist(s->artists, artist);
    if (run == NULL)
    {
        puts("artist not found");
        return;
    }

    run2 = get_album(run->albums, b);
    if (run2 == NULL)
    {
        puts("album not found");
        return;
    }

    run3 = get_song(run2->songs, c);
    if (run3 == NULL)
    {
        puts("song not found");
        return;
    }
    run3->liked=true;

}