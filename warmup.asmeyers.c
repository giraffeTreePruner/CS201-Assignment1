#include "warmup.asmeyers.h"
#include "string.h"

Song *createSong(char *title, char *artist, unsigned int year){
    Song song;
    if(title && artist){
        if(strlen(title) > 0 && strlen(title) <= MAXNAMELEN &&
                strlen(artist) > 0 && strlen(artist) <= MAXNAMELEN){
            strcpy(song.title, title);
            strcpy(song.artist, artist);
            song.year = year;
            return &song;
        }
    }
    return NULL;
}


int compareSongs(Song *songOne, Song *songTwo){
    int titlesCom = strcmp(songOne->title, songTwo->title);
    if(titlesCom == 0){
        int artistsCom = strcmp(songOne->artist, songTwo->artist);
        if (artistsCom == 0){
            if (songOne->year == songTwo->year)
                return 0;
            return (songOne->year < songTwo->year) ? -1 : 1;
        }
    } else
        return titlesCom;
}