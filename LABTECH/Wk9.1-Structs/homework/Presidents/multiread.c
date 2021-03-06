/*
 * multiread.c - reading presidents files
 * Used person-read.c as a reference
 * Ryan Edwards
 */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <errno.h>


// Struct of type president
typedef struct {
  
  int order;
  char inits[3];
  
} president;

int main(int argc, char *argv[] )
{
  president information;
  FILE *inputfile;
  int numread;
  int i;

  // Make sure argument amount is correct.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
    exit(1);
  }
  
  // Opening the right file; r means open text file for reading
  // Taking second argument as our input file.  
  if ( ( inputfile = fopen(argv[1], "r") ) == NULL ) {
    perror(argv[1]);
    exit(1);
  }

  // Scooping, reading
  printf("Num  Inits\n");
  while (!feof(inputfile))
    {
      numread = fread(&information.inits, sizeof(information), 1, inputfile);
      printf("%s\n", information.inits);
  }
  
  
  printf("End of data\n");
  fclose(inputfile);
  return 0;
}
