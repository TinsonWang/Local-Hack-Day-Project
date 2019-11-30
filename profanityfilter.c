#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 999

int main(int argc, char* argv[])
{
    FILE* f1;
    FILE* f2;
    File* usrFile;

    char badLog[MAXSIZE][MAXSIZE];
    char goodLog[MAXSIZE][MAXSIZE];
    char textLog[MAXSIZE][MAXSIZE];

    char line[1000];
    int lineState = 0;
    char word[20];
    int charCount = 0;
    int randNo;
    int RAND_MAX = 100;
    int badword = 0; /* boolean for bad word check*/
    int i, j, k;

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

    /*opening the usr file */
    if ( (usrFile = fopen("argv[1]", "r") != NULL) ){

    }else{
      printf("error - file does not exists\n" );
      exit(0);
    }

    while ( fgets ( line, MAXSIZE, usrFile ) != NULL ) {
      for (i = 0; i < strlen(line) ; i++) {

        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
          word[charCount] = '\0'

          for (j = 0; j < 500; j++) {
            if (strcmp(word, badLog[j]) == 0) {
              badword = 1;
            }
          }

          if (badword == 1) {
            randNo = random();
            printf("%s", goodLog[randNo] );
          } else{
            printf("%s",word );
          }

          lineState = 0;
        } else if (lineState == 0){

          for (k = 0; k < 20; k++) {
            word[k]='\0'
          }

          lineState = 1;
          charCount = 0;
        }

        if (lineState == 1) {
          word[charCount++] = line[i];
        }

      }
    }


    return 0;

}
