#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DELTA 32 /*Difference in decimal value between upper and lowercase letters*/

int convertLowerCase(char *line)
{
    int counter, i;
    counter = 0;

    if (line == NULL)
    {
        return -1;
    }

    for (i = 0; i < strlen(line); i++)
    {
        if (isalpha(line[i]) && isupper(line[i]))
        {
            line[i] += DELTA;
            counter++;
        }
    }

    return counter;

}