#include <stdio.h>
#include <string.h>

int chop(char *line)
{
    int counter, i;
    counter = 0;
    if (line == NULL)
    {
        return -1;
    }

    for (i = 0; i < strlen(line); i++)
    {
        if (line[i] == '\n')
        {
            line[i] = ' ';
            counter++;
        }
    }

    return 0;

}