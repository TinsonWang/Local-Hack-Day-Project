#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 999

int main(int argc, char* argv[])
{
    FILE* f1;
    FILE* f2;
    FILE* usrFile;

    char badLog[MAXSIZE][MAXSIZE];
    char goodLog[MAXSIZE][MAXSIZE];

    char line[1000];
    char temporary[1000];
    int lineState = 0;
    char word[20];
    int charCount = 0;
    int randNo;
    int badword = 0; /* boolean for bad word check*/
    int i=0;
    int j = 0;
    int k=0;
    char temp[MAXSIZE];
    srand(time(0));

    /*Saving bad words from a file to an array*/
    if ( (f1 = fopen("list.txt", "r")) != NULL )
    {
	    while (fgets(temp, MAXSIZE, f1) != NULL)
	    {
        for (j = 0; j < strlen(temp); j++)
    {
        if (temp[j] == '\n')
        {
            temp[j] = '\0';
        }
    }
        strcpy(badLog[k++], temp);
		    i++;
	    }

    } else
    {
	    printf ("ERROR: File cannot be opened\n");
	    exit(1);
    }

    /*Saving good words from a file to an array*/
    i = 0;
    k=0;
    if ( (f2 = fopen("goodWords.txt", "r")) != NULL )
    {
	    while (fgets(temp, MAXSIZE, f2) != NULL)
	    {
		    for (j = 0; j < strlen(temp); j++)
    {
        if (temp[j] == '\n')
        {
            temp[j] = '\0';
        }
    }
        strcpy(goodLog[k++], temp);
		    i++;
	    }

    }else
    {
	    printf ("ERROR: File cannot be opened\n");
	    exit(1);
    }


    /*printing out users file for referance*/
    if ( (usrFile = fopen(argv[1], "r")) != NULL ) {
      while ( fgets ( temporary, MAXSIZE, usrFile ) != NULL ) {
        printf("%s",temporary );
      }
    }else{
      printf("error - file does not exists\n" );
      exit(0);
    }
    printf("\n");
    fclose(usrFile);

    /*opening the usr file to check bad words*/
    if ( (usrFile = fopen(argv[1], "r")) != NULL ) {

    }else{
      printf("error - file does not exists\n" );
      exit(0);
    }

    while ( fgets ( line, MAXSIZE, usrFile ) != NULL ) {
      for (i = 0; i < strlen(line) ; i++) {

        /*checks if its checking in a word or out and processing*/
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
          word[charCount] = '\0';

          for (j = 0; j < 500; j++) {

            if (strcmp(word, badLog[j]) == 0) { /*comparing word with bard word library*/
              badword = 1;
            }
          }

          if (badword == 1) {
            randNo = (rand() % 101) ;
            printf("%s ", goodLog[randNo] ); /*printing good words in random*/
            badword = 0;
          } else{
            printf("%s ",word );
          }

          lineState = 0;
        } else if (lineState == 0){

          for (k = 0; k < 20; k++) {
            word[k]='\0';
          }

          lineState = 1;
          charCount = 0;
        }

        if (lineState == 1) {
          word[charCount++] = line[i];
        }

      }
      printf("\n");
    }


    return 0;



}