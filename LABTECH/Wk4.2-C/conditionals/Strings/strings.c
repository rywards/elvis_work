/* strings.c - do some stuff with strings
 *
 * D Provine, 24 Sept 2012
 */

#include <stdio.h>

int main()
{
    int  len(char *);
    char str1[] = "This is a test."; // compiler counts to find size
    char *str2;
    char *str3;

    printf("%s\n", str1);
    printf("%d\n", len(str1)); // len() counts until it finds \0
    str2 = &str1[10];          // str2 is address of first 't' in "test"
    printf("%s\n", str2);
    str3 = str2 + 5;           // str3 is address of \0 at end of str1
    *str3 = 'x';               // we just stomped the null character.

    printf("%s\n", str1);      // runs off end of string now

    printf("This is a very long string that I need for error\n " 
          " messages nor something in my code and it breaks\n " 
	   "my 75-character limit what\ndo I do?\n");
    /*
      The correct way to format this is as follows:
      printf("This is a very long string that I need for error \n \
           messages nor something in my code and it breaks \n \
           my 75-character limit what\ndo I do?\n");
	    
	   \ (backslash) at the end of a line allows continuation on to 
	   the next line... but it includes all the white space in between
	   them as well.  So, you need the \n to skip it.

	   Yes, we could also just do the following:
	     printf("This is a very long string that I need for error " 
          " messages nor something in my code and it breaks " 
           "my 75-character limit what\ndo I do?\n");

	   However, then our sentence will wrap around (which we do not want,
	   RE: Coding Standards), so you need newlines here too

	   
     */
    return 0;
}

// return lenth of a string
int len(char *s)
{
    int i = 0;
    while( *(s+i) != '\0' )
        i++;
    return i;

}
