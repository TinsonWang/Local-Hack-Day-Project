#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* filter;
    FILE* text;
    int wordState;
    wordState = 0;

    if ( (filter = fopen("list.txt", "r") != NULL) )
    {
        printf("Filter successfully loaded!\n");
    }
    else
    {
        printf("ERROR: Could not load in filter!\n");
    }

    if ( (text = fopen(argv[1], "r") != NULL) )
    {
        printf("Text successfully loaded!\n");
    }
    else
    {
        printf("ERROR: Could not load in text!\n");
    }

    return 0;

}