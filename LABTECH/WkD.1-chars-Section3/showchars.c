/* showchars.c - Show characters
 *
 * D Provine, 20 March 2012
 *
 * INCOMPLETE: Only shows one character!
 *
 * "-l" flag shows guidelines
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chars/All_Chars.h"

int main(int argc, char *argv[])
{
    int line;     // line we're printing
    int bit;      // which bit we're on
    int charnum;  // what's the ASCII value for this character
    int arraypos; // where in the array is this character
    int thearg;   // which command-line argument do we care about?

    if (argc < 2 || (argc == 3 && strcmp(argv[1], "-l") ) ) {
        fprintf(stderr, "Usage: %s [-l] string\n", argv[0]);
        exit(1);
    }

    if (argc == 3) {
        thearg = 2;
    } else {
        thearg = 1;
    }
        
    for (line=0; line < 10; line++) {
        /* argv[thearg][0] is the first character of the argument
         * we want.
         * (The argument is a null-terminated string, even if the
         *  user only types one character.)
         * Converting it to an int gives us the ASCII value.
         */
        charnum = (int) argv[thearg][0];

        /* Our array starts at index 0, which is for the " " char.
         * The " " char has ASCII value 0x20, but has array index zero.
         * So we have to subtract 0x20 from the ASCII value to get the
         * array index.
         */
        arraypos = charnum - 0x20;

        for (bit = 7; bit >= 0; bit--) {
            if ( (*glyph[arraypos])[line] & ( 1 << bit ) )
                printf("X");
            else {
                // do we print guidelines?
                if (thearg == 2 && (line == 1 || line == 7)) 
                    printf("-");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

