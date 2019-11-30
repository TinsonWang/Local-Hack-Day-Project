#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 500 /*The maximum size for both a line of input
                      and an array of type char */

/*  This program will count the number of unique words
    and print out how many times that word appears */

int main(int argc, char *argv[])
{
    char line[MAXSIZE];
    char *words[MAXSIZE];
    int totalwords, counter;
    int i, j, k;

    totalwords = 0;
    i = 0;

    /*Referenced from: https://stackoverflow.com/questions/14452335/using-fgets-to-copy-lines-into-string-array
    This function essentially copies the contents from argument 2 to argument 1
    This function is required because the same buffer gets used by fgets() with each line read
    such that the contents stored in the buffer gets written over continuously. */
    char *strdup (const char *str)
    {
        size_t len = strlen(str) + 1;
        char *dup = malloc(len);
        if (dup != 0)
        {
            memmove(dup, str, len);
        }
        return (dup);
    }

    /*The strdup function is used here to store the input read from fgets() into a different array
    before it gets written over by the next call of fgets()*/
   while (fgets(line,MAXSIZE,stdin) != NULL)
   {
        totalwords++;
        words[i++] = strdup(line);

    }

    /*Compare each of the words stored into the array with all of the other words in that array
    If more than one occurrence of the word is count, j is increased to skip over the same word
    being counted twice*/
   for (j = 0; j<totalwords; j++)
   {
        counter = 0;

       for (k = 0; k<totalwords; k++)
       {
           if (strcmp(words[j], words[k]) == 0)
           {
               counter++;
           }
       }

       if (counter > 001)
       {
           j++;
       }

        printf("%03d %s", counter, words[j]);

   }

    return 0;
}