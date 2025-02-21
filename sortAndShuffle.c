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

/* i created this function to get input of songs, it gets the songs and puts them in the array
 * and also the number of songs that were input which is why it is a int function*/
int insertSongs(char artists[80], char songs[3][80])
{
	int i, length;
	char temp[80];
		 for (i = 0; i < 3; i++)
		 {

			 printf("Insert song %d for %s ", i + 1, artists);
			 fflush(stdout);
			 fgets(temp, 80, stdin);
			 length = strlen(temp);
			 temp[length - 2] = '\0';

			 if (! strncmp(temp, "!", 1)) /* checks if 1st char of temp is !, if true returns 0 and (! 0) returns true which then breaks the loop*/
			 {
				 break;
			 }

			 else /* copies the song from temp array to actual array*/
			 {
				 strcpy(songs[i], temp);
			 }
		 }

		 if (i > 0)
		 {
			 return i;
		 }

		 else
		 {
			 return 0;
		 }
}

/*
* This method sorts the artists alphabetically. It takes as input:
* - sortedArtists: the array of artists that that should be sorted
* - numOfArtists: the total number of artists
*
*/
/* i used the selection sort for my sort Algorithm, it compares j and minIndex (which is set to the 1st element) and checks if the j is
 * lexicographically smaller than the minIndex and if it is then minIndex is changed to j. at the end of the inner loop we find the
 * lexicographically smallest artist and swap it with i (which was the first element we started with).*/
void sortArtists(char sortedArtists[][80], int numOfArtists)
{
    int i, j, minIndex;
    char swap[80];

    for (i = 0; i < numOfArtists - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < numOfArtists; j++)
        {
            if (strcmp(sortedArtists[j], sortedArtists[minIndex]) < 0)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            strcpy(swap, sortedArtists[i]);
            strcpy(sortedArtists[i], sortedArtists[minIndex]);
            strcpy(sortedArtists[minIndex], swap);
        }
    }
}

/*
* This method sorts the songs of a specific artist alphabetically. It takes as input:
* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
* - numSongs: the number of songs provided from the standard input
*/

/* i used the selection sort for this sort algorithm aswell, the logic is the exact same as the sortArtists one.*/
void sortSongs(char songsOfAnArtist[][80], int numSongs)
{
    int i, j, minIndex;
    char swap[80];

    for (i = 0; i < numSongs - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < numSongs; j++)
        {
            if (strcmp(songsOfAnArtist[j], songsOfAnArtist[minIndex]) < 0)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            strcpy(swap, songsOfAnArtist[i]);
            strcpy(songsOfAnArtist[i], songsOfAnArtist[minIndex]);
            strcpy(songsOfAnArtist[minIndex], swap);
        }
    }
}

/*
* This method shuffles a set of songs. It takes as input:
* - songsToBeShuffled: the array of the songs that should be shuffled
* - numOfSongs: the number of songs to be shuffled
*/

/* i used the Fisher Yates Algorithm. i used a "for loop" that went through all the songs in the array and shuffled them and if a song
 * was repeated in the last 5 iterations then the boolean located was set to true and the do while loop got a new integer for j, if the song
 * was not repeated in the last 5 iterations then it was swapped and put into the array. If the user inputs less than 6 songs than it
 * shuffles normally ignoring the 5 consecutive rule however if input is 6 or more than it applies that rule */
void shuffleSongs(char songsToBeShuffled[][80], int numOfSongs)
{
	int i, j;
	char swap[200];
	srand(time(NULL));


	if (numOfSongs >= 12)
	{
		for (i = 0; i < numOfSongs; i++)
		{

			bool located = false;
			do
			{
				j = rand() % numOfSongs;

				located = false;



				if ((i >= 1 && (strcmp(songsToBeShuffled[j], songsToBeShuffled[i - 1]) == 0))
								|| (i >= 2 && (strcmp(songsToBeShuffled[j], songsToBeShuffled[i - 2]) == 0))
								|| (i >= 3 && (strcmp(songsToBeShuffled[j], songsToBeShuffled[i - 3]) == 0))
								|| (i >= 4 && (strcmp(songsToBeShuffled[j], songsToBeShuffled[i - 4]) == 0))
								|| (i >= 5 && (strcmp(songsToBeShuffled[j], songsToBeShuffled[i - 5]) == 0)))
				{
					located = true;
				}


			} while (located);

			strcpy(swap, songsToBeShuffled[j]);
			strcpy(songsToBeShuffled[j], songsToBeShuffled[i]);
			strcpy(songsToBeShuffled[i], swap);


		}
	}

	else
	{
		for (i = 0; i < numOfSongs; i++)
			{
				j = rand() % numOfSongs;

				strcpy(swap, songsToBeShuffled[j]);
				strcpy(songsToBeShuffled[j], songsToBeShuffled[i]);
				strcpy(songsToBeShuffled[i], swap);
			}
	}

}
