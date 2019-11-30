#include <stdio.h>
#include <string.h>
#include <ctype.h>

int reduceSpace(char *line)
{
    /*  Will give a warning about an implicit declaration for the isblank function
        However, the library that the function has been defined in has been properly included.
        The function also works as intended. */

    int counter, i;
    counter = 0;

    if (line == NULL)
    {
        return -1;
    }

    for (i = 0; i <strlen(line); i++)
    {
        if (isblank(line[i]))
        {
            line[i] = ' ';
            counter++;
        }
    }

    return counter;
}