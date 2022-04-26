#define _CRT_SECURE_NO_WARNINGS
#include "run.h"
#include "song.h"
#include "songify.h"
#include "Artist.h"
#include "albom.h"
#include <stdio.h>
#include <stdlib.h>
#include "rec.h"
void cleanBuff()
{
    while (getchar()!= '\n');
   
}


void run()
{
    struct songify* s = (struct songify*)malloc(sizeof(struct songify));
    s->artists=NULL;
    struct Artist a;
    a.name = (char*)malloc(sizeof(char) * 100);
    a.albums=NULL;
    struct album b;
    b.name = (char*)malloc(sizeof(char) * 100);
    b.songs=NULL;
    struct song c;
    c.name = (char*)malloc(sizeof(char) * 100);
   int ch;
   do
   {
      puts("1.add artist ");
      puts("2.add album ");
      puts("3.print albums of artist ");
      puts("4.add song to album ");
      puts("5.get number songs of album");
      puts("6.get len of album");
      puts("7.play song ");
      puts("8.add song to fav");
      puts("9.exit");
      scanf("%d",&ch);
      switch (ch){
        case 2 :
        case 4 :
        case 5 :
        case 6 :
        case 7 :
        case 8 :
            printf("enter name of artist : ");
            cleanBuff();
            gets(a.name);
            printf("enter album name : " );
            gets(b.name);
      
      }
    switch (ch)
    {
        case 1:
            printf("enter name: ");
            cleanBuff();
            gets(a.name);
            printf("enter active years start and end : ");
            scanf("%d %d",&a.active.firstYear,&a.active.lastYear);
            a.albums=NULL;
            addArtist(s,a);
        break;

        case 2:
            addAlbum(s,a,b);
        break;

        case 3:
            printf("enter name of artist : ");
            cleanBuff();
            gets(a.name);
            printAlbums(s,a);
        break;

        case 4:   
            printf("enter song id : ");
            scanf("%d",&c.id);
            cleanBuff();
            printf("enter song name: ");
            gets(c.name);
            printf("enter song length : ");
            scanf("%d",&c.length);
            c.next=NULL;
            c.timePlayed=0;
            c.liked=false;
            addSongToAlbum(s,a,b,c);
        break;

        case 5:
            printf("number of songs of album : %d\n", numberSongsOfAlbum(s, a, b));
        break;

        case 6:
            printf("length of album : %d\n",lenOfAlbum(s, a, b));
        break;

        case 7:
            printf("enter song id : ");
            scanf("%d",&c.id);
            playSong(s,a,b,c);
        break;
      
        case 8:
            printf("enter song id : ");
            scanf("%d",&c.id);
            addSongFav(s, a, b, c);
        break;
    }
   } while (ch >=1 && ch<=8);
   free_memory(s->artists, NULL, NULL);
   free(s);
   puts("goodbey");
   cleanBuff();
   getchar();
}

