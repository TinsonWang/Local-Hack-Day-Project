#include <stdio.h>
#include <string.h>
#include <ctype.h>

int replaceDigits(char *line)
{
    int counter, i;
    counter = 0;

    if (line == NULL)
    {
        return -1;
    }

    for (i = 0; i < strlen(line); i++)
    {
        if (isdigit(line[i]))
        {
            line[i] = ' ';
            counter++;
        }
    }

    return counter;
}