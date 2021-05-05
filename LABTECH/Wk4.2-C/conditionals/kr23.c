/* kr23.c - notes from K&R chapters 2 & 3
 *
 * (Not a whole lot, Java and C++ are both like C in most
 *  respects.)
 * D Provine, 22 Feb 2010
 * Modified, Jake Levy 2/3/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

int main()
{
	//  variables start with a letter, '_' counts but don't use it
     	//  first.
	int    i;
	float  f;
	double d;
	char   c = 'X';  // single quotes for single character
	char   str[] = "1023 foo bar17";  // double quotes for string

	(void) printf("int: %d,  float %d,  double %d\n",
		sizeof(int), sizeof(float), sizeof(double));
	int mask = 0xf0;
	i = 12;    // decimal
	i = 0xC;   // hexadecimal
	i = 014;   // octal - this one causes bugs sometimes!
	int x = 5;

	if( (x & mask) == 0 ){
	  //5 = 0101, 0 = 0000, 0101 & 0000 = 0000, 0000 == 0 evaluates to true
	printf("You always parenthesize bitwise operations\n\n");
	}
	  //& has lower precedence than ==,so == is evaluated first
	  //mask is not equal to 0, so the expression evaluates as 0
	  //0101 & 0000 evaluates to 0(false) and the calculation stops.
	if (x & mask == 0){
	  printf("Otherwise things will go wrong");
	}

	
	//  if you want an untypeable character
	//  c = \OOO  (octal value you want)
        //  c = \xHH  (hex value you want)
	printf(" \x7C (7C in Hex) is a tool  that we've been discussing\n");
	printf(" \174 is 124 in octal\n\n");
	
	(void) printf("Enter something and then hit enter.\n");
	while ( ( c = getchar() ) != '\n' )
		/* discard input */ ;

	//set c to the NULL character, aka '\0'
	c = '\0';

	//This will print the entire string
	(void) printf("%s\n", str);
	//atoi (ascii TO Integer) will pull out the first integer it can parse
	//from the given string
	(void) printf("%d\n", atoi(str));

        /* A "cast" is how you make a variable into another type.
         * You put the type you want in parentheses.  So
         *    x = (int) y;
         * converts y to an integer for assignment to x.
         * Many casts happen automatically, but not all of them do.
         *
         * The man page ("man 2 time") says:
         *
         *      time_t time(time_t *t);
         *
         * so we need an argument of type "pointer to time_t",
         * and the return value is a time_t, which we have to make
         * into an int.
         */
        i = (int) time( (time_t *) NULL );

	(void) printf("Time is now %d\n", i);


        /* The "ternary" operator takes three arguments; and it's
         * a super-compact if-then-else.  Avoid overuse.
         */
	printf("Enter a number: ");
	scanf("%d", &i);

	printf("If the number of computers is %d, you would say:\n",
		i);
	printf(" %d computer%s\n", i, i != 1 ? "s" : "");


	printf("Enter some stuff, stop with EOF (probably ^D).\n");
	printf("('i' will be ignored; 'o' will print and then quit).\n");
	while ( ( c = getchar() ) != EOF ) {
		if ( c == 'i' )
			continue; // skip rest of loop
		putchar(c);
		if ( c == 'o' )
			break;    // bail out of loop
	}

	return 0;
}

