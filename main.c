//============================================================================
// Name        : Assignment1.cpp
// Author      : Hamza Yasin
// Version     :
// Copyright   : Your copyright notice
// Description : Sort and Shuffle Songs and Artist
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "sortAndShuffle.h"

int main(void)
{
  //The array containing artists names
  char artists[4][80];
  //The array containing the sorted artists
  char sortedArtists[4][80];
  //Songs for Artist 1
  char songsArtist1[3][80] = {0};
  //Songs for Artist 2
  char songsArtist2[3][80] = {0};
  //Songs for Artist 3
  char songsArtist3[3][80] = {0};
  //Songs for Artist 4
  char songsArtist4[3][80] = {0};
  //The total number of artists (Note it can be less than 4)
  int numOfArtists = 0;
  //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
  int numSongsPerArtist[4] = {0};

  int i, j, k = 0;
  int count = 1;
  int numOfSongs = 0;



  /* INPUT GATHERING MODULE */
  /* Here i got the artists as input and got their songs and amount of songs per artist, i used a temporary array to store the artist being
   * inputted and strncmp to see if the input recieved was '!' and if it was then the loop would break and no more artists would be taken
   * however if it wasnt '!' then the artist would be put into the actual array containing the artists and while row was 0,1,2 or 3 it would
   * execute its specific function to insertSongs and the number of songs for that artist.*/
printf("Press '!' to stop receiving more Artists/Songs. \n \n");
fflush(stdout);


  for (int row = 0; row < 4; row++)
   {
	 char temp[80];
	 int length;
  	 printf("Insert an artist/group name: \n");
  	 fflush(stdout);
  	 fgets(temp, 80, stdin);
  	 length = strlen(temp);
  	 temp[length - 2] = '\0';

  	 if (! strncmp(temp, "!", 1))
  	 {
  		 break;
  	 }

  	 else
  	 {
  		 strcpy(artists[row], temp);
  	  	 numOfArtists++;
  	 }

  	 switch(row)
  	 {
  	 case 0:
 		  numSongsPerArtist[row] = insertSongs(artists[row], songsArtist1);
 		  break;

  	 case 1:
 		  numSongsPerArtist[row] = insertSongs(artists[row], songsArtist2);
 		  break;

  	 case 2:
 		  numSongsPerArtist[row] = insertSongs(artists[row], songsArtist3);
 		  break;

  	 case 3:
 		  numSongsPerArtist[row] = insertSongs(artists[row], songsArtist4);
 		  break;
  	 }


   }



/* SORTING ARTISTS/SONGS MODULE */
  /* i added all the artists in the sortedArtists array*/
  for (i = 0; i < numOfArtists; i++)
  {
	  strcpy(sortedArtists[i], artists[i]);
  }



/* ran the functions*/
   sortArtists(sortedArtists, numOfArtists);
   sortSongs(songsArtist1, numSongsPerArtist[0]);
   sortSongs(songsArtist2, numSongsPerArtist[1]);
   sortSongs(songsArtist3, numSongsPerArtist[2]);
   sortSongs(songsArtist4, numSongsPerArtist[3]);

   printf("Sorted list of songs: \n");
   fflush(stdout);

   /* now the for loop runs for certain iteration until artists are finished and if sortedArtist is 1,2,3 or 4 it prints
    * that artists name alongside that artists sorted songs*/
   for (i = 0; i < numOfArtists; i++)
   {
       printf("%s\n", sortedArtists[i]);
       fflush(stdout);

       if (strcmp(sortedArtists[i], artists[0]) == 0)
       {
           printf("- %s\n", songsArtist1[0]);
           fflush(stdout);
           printf("- %s\n", songsArtist1[1]);
           fflush(stdout);
           printf("- %s\n", songsArtist1[2]);
           fflush(stdout);
           printf("\n");
           fflush(stdout);
       }
       else if (strcmp(sortedArtists[i], artists[1]) == 0)
       {
           printf("- %s\n", songsArtist2[0]);
           fflush(stdout);
           printf("- %s\n", songsArtist2[1]);
           fflush(stdout);
           printf("- %s\n", songsArtist2[2]);
           fflush(stdout);
           printf("\n");
           fflush(stdout);
       }
       else if (strcmp(sortedArtists[i], artists[2]) == 0)
       {
           printf("- %s\n", songsArtist3[0]);
           fflush(stdout);
           printf("- %s\n", songsArtist3[1]);
           fflush(stdout);
           printf("- %s\n", songsArtist3[2]);
           fflush(stdout);
           printf("\n");
           fflush(stdout);
       }
       else if (strcmp(sortedArtists[i], artists[3]) == 0)
       {
           printf("- %s\n", songsArtist4[0]);
           fflush(stdout);
           printf("- %s\n", songsArtist4[1]);
           fflush(stdout);
           printf("- %s\n", songsArtist4[2]);
           fflush(stdout);
           printf("\n");
           fflush(stdout);
       }
   }



   /* SHUFFLING SONGS MODULE */
   /* I doubled the amount of songs in numOfSongs since each song has to be shuffled twice */
   numOfSongs = numSongsPerArtist[0] + numSongsPerArtist[1] + numSongsPerArtist[2] + numSongsPerArtist[3] + numSongsPerArtist[0] + numSongsPerArtist[1] + numSongsPerArtist[2] + numSongsPerArtist[3];
    char allSongs[numOfSongs][80];
    /* In these for loops I added all the songs from the Artists TWICE since each song has to be shuffled twice */

    if (numSongsPerArtist[0] > 0)
    {
    	 for (i = 0; i < numSongsPerArtist[0]; i++)
    	 {
            strcpy(allSongs[k++], songsArtist1[i]);
        }
    }

    if (numSongsPerArtist[1] > 0)
    {
        for (i = 0; i < numSongsPerArtist[1]; i++)
        {
            strcpy(allSongs[k++], songsArtist2[i]);
        }
    }

    if (numSongsPerArtist[2] > 0)
    {
        for (i = 0; i < numSongsPerArtist[2]; i++)
        {
            strcpy(allSongs[k++], songsArtist3[i]);
        }
    }

    if (numSongsPerArtist[3] > 0)
    {
        for (i = 0; i < numSongsPerArtist[3]; i++)
        {
            strcpy(allSongs[k++], songsArtist4[i]);
        }
    }

    if (numSongsPerArtist[0] > 0)
    {
    	 for (i = 0; i < numSongsPerArtist[0]; i++)
    	 {
            strcpy(allSongs[k++], songsArtist1[i]);
        }
    }

    if (numSongsPerArtist[1] > 0)
    {
        for (i = 0; i < numSongsPerArtist[1]; i++)
        {
            strcpy(allSongs[k++], songsArtist2[i]);
        }
    }

    if (numSongsPerArtist[2] > 0)
    {
        for (i = 0; i < numSongsPerArtist[2]; i++)
        {
            strcpy(allSongs[k++], songsArtist3[i]);
        }
    }

    if (numSongsPerArtist[3] > 0)
    {
        for (i = 0; i < numSongsPerArtist[3]; i++)
        {
            strcpy(allSongs[k++], songsArtist4[i]);
        }
    }


   shuffleSongs(allSongs, numOfSongs);

   /* to print the shuffled songs ALONGSIDE the correct artist, i used for loops and if statements
    * so if the song matches to any of songs in songArtist1,2,3,4 array then it prints that artists name with the song*/

	printf("Shuffled Playlist:\n \n");
	fflush(stdout);

   	for (i = 0; i < numOfSongs; i++)
   	{
   		for (j = 0; j < numSongsPerArtist[0]; j++)
   		{
   			if (strcmp(allSongs[i], songsArtist1[j]) == 0)
   			{
   				printf("%s - %s\n", artists[0], allSongs[i]);
   				fflush(stdout);
   			}
   		}

   		for (j = 0; j < numSongsPerArtist[1]; j++)
   		{
   			if (strcmp(allSongs[i], songsArtist2[j]) == 0)
   			{
   				printf("%s - %s\n", artists[1], allSongs[i]);
   				fflush(stdout);
   			}
   		}

   		for (j = 0; j < numSongsPerArtist[2]; j++)
   		{
   			if (strcmp(allSongs[i], songsArtist3[j]) == 0)
   			{
   				printf("%s - %s\n", artists[2], allSongs[i]);
   				fflush(stdout);
   			}
   		}

   		for (j = 0; j < numSongsPerArtist[3]; j++)
   		{
   			if (strcmp(allSongs[i], songsArtist4[j]) == 0)
   			{
   				printf("%s - %s\n", artists[3], allSongs[i]);
   				fflush(stdout);
   			}
   		}
   	}






  return 0;
}

