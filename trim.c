#include <stdio.h>
#include <string.h>
#include <ctype.h>

int trim(char *line)
{
    int counter;
    counter = 0;

    if (line == NULL)
    {
        return -1;
    }

    if (isspace(line[0]))
    {
        line[0] = '\0';
        counter++;
    }

    if (isspace(line[strlen(line)]))
    {
        line[strlen(line)] = '\0';
        counter++;
    }

    return 0;
}

