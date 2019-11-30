#include <stdio.h>
#include <strings.h>

#define MAXSIZE  500    /* maximum size of input line */

/*
 * Program Name: textRW.c
 * Author(s): Deb Stacey
 * Purpose: reads input from STDIN line by line and
 *          prints them out to STDOUT
 */

int main ( int argc, char *argv[] ) {
   char line[MAXSIZE];

   while ( fgets ( line, MAXSIZE, stdin ) != NULL ) {
      printf ( "%s", line );
   }

   return ( 0 );
}
