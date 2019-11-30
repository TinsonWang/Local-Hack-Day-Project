#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "textProc.h"

#define MAXSIZE  500    /* maximum size of input line */
#define MAXWORDS 1000   /* maximum number of unique words */


int main(int argc, char* argv[])
{
    FILE* filter;
    FILE* file;
    char line[MAXSIZE];
    int i, j;
    int length;
    int numWords;
    int words[MAXSIZE];

    /*if (filter = fopen("listofbadwords.txt", "r") != NULL)
    {
        printf("Filter successfully loaded!\n");
    }
    else
    {
        printf("ERROR: Could not read in filter!\n");
        return 1;
    }
    */

    if ((file = fopen(argv[1], "r")) != NULL)
    {
        printf("Text successfully read!\n");
    }
    else
    {
        printf("ERROR: Could not read in text!\n");
        return 2;
    }

    while ( fgets ( line, MAXSIZE, file ) != NULL )
    {
      chop ( line );
      convertLowerCase ( line );
      replaceDigits ( line );
      replacePunc ( line );
      reduceSpace ( line );
      trim ( line );


        length = strlen(line) + 1;
        j = 0;
        numWords = 0;
        words[j++] = 0;
        for ( i=1; i<length; i++ )
        {
            if ( line[i] == ' ' || line[i] == '\0' )
            {
                line[i] = '\0';
                numWords++;
                words[j++] = i+1;
            }
        }
        for ( i=0; i<numWords; i++ )
        {
            printf ( "%s\n",&line[words[i]] );
        }

    }

    return 0;
}