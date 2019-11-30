#include <stdio.h>

#define MAXSIZE 999

int main(int argc, char* argv[])
{
    FILE* f1;
    FILE* f2;
    FILE* f3;
    char badLog[MAXSIZE][MAXSIZE];
    char goodLog[MAXSIZE][MAXSIZE];
    char textLog[MAXSIZE][MAXSIZE];
    int i = 0;


    if ( (f1 = fopen("badWords.txt", "r")) != NULL )
    {
	    while (fgets(badLog[i], MAXSIZE, f1) != NULL) 
	    {
		    i++;
	    }

    } else 
    {
	    printf ("ERROR: File cannot be opened\n");
	    exit(1);
    }
    i = 0;

    if ( (f2 = fopen("goodWords.txt", "r")) != NULL )
    {
	    while (fgets(goodLog[i], MAXSIZE, f2) != NULL) 
	    {
		    i++;
	    }

    }else 
    {
	    printf ("ERROR: File cannot be opened\n");
	    exit(1);
    }

    i = 0;

    if ( (f3 = fopen("text.txt", "r")) != NULL )
    {
	    while (fgets(textLog[i], MAXSIZE, f3) != NULL) 
	    {
		    i++;
	    }

    } else 
    {
	    printf ("ERROR: File cannot be opened\n");
	    exit(1);
    }

    
    return 0;
    
}
