#include <stdio.h>

#define MAXSIZE 999
#define DELTA 32

int printWord (array[MAXSIZE][MAXSIZE])
{
    int i, j;

    for (i = 0; i < MAXSIZE; i++)
    {
        for (j = 0; j < MAXSIZE; j++)
        {
            if ( (ispunct(array[i][j-1]) == 0) && (isalpha(array[i][j])  == 0) )
            {
                toupper(array[i][j]);
                printf("%c", array[i][j]);
            }
            else
            {
                printf("%c", array[i][j]);
            }

        }
    }

    return 0;
}
