/* person-read.c - sample program to read structs
 *
 * dfp
 *
 * NOTE: fread() takes a pointer as an argument, so we have to
 *       allocate space and give a pointer to it.  If a function
 *       takes a pointer as an argument, you have to allocate space.
 *
 * See the file "person_write.c" for more comments.
 */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <errno.h>

// our type holds one number and one name
typedef struct {
	int number;
	char name[19];
} person;

int main()
{
	person Pontiff;
	FILE   *inputfile;
	int    howmany;

        // Open "pope.dat" as a file stream for reading.  Quit
        // if the file couldn't be opened.
	if ( ( inputfile = fopen("pope.dat", "r") ) == NULL ) {
		perror("pope.dat");
		exit(1);
	}
      
        // Into the memory location "Pontiff", in chunks the size
        // of a "person" object, one chunk, from the stream "inputfile".
        // If we don't get one, something went wrong.
	if ( (howmany = fread(&Pontiff, sizeof(person), 1, inputfile)) != 1) {
  		if ( feof(inputfile) != 0 ) {
			fprintf(stderr, "EOF on file.\n");
		} else {
			perror("pope.dat");
		}
		exit(1);
	}

        // The data has been stored in the "Pontiff" object, and we
        // can access its elements with the familiar dot notation
        // that languages use for object data members.
	printf("File data:  name: %s, number: %d.\n", Pontiff.name, 
						      Pontiff.number);

        // Close the input file before quitting.
	fclose(inputfile);
	return 0;
}
