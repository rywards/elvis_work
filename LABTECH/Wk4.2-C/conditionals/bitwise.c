/* bitwise.c - illustrate bitwise manipulation
 *
 * D Provine, 31 Jan 2017
 */

#include <stdio.h>
#include <stdlib.h>

/* prints last byte of a value in hex and binary
 */
void printbyte(int value)
{
    int i;

    printf("    Decimal: %5d   Hex: 0x%02x   Binary: ", value, value);
    
    for (i = 7; i >= 0; i--) {
        if ( value & ( 1 << i ) ) {
            printf("1");
        } else {
            printf("0");
        }
        if ( i % 4 == 0 )
            printf(" ");
    }
    printf("\n");
}

/* argc = argument count (how many words on command line)
 * argv = argument vector (array of words; argv[0] is name of command)
 */
int main(int argc, char *argv[])
{
    int i, val1, val2;

    if ( argc != 3 ) {
        fprintf(stderr, "Usage: %s value1 value2\n", argv[0]);
	// Truncates the 255 bit space, will extend past 4 bytes shown
        fprintf(stderr, "(values above 255 are truncated\n");
        exit(1);
    }

    // atoi() = "ascii to integer"; it's in stdlib.h
    // bitwise and to get only last byte
    val1 = atoi(argv[1]) & 0xff;
    val2 = atoi(argv[2]) & 0xff;
    printf("Name of Program: %s", argv[0]);
    printf("original values:\n");
    printbyte(val1);
    printbyte(val2);

    /* Because these are integers, they're 32 bits.  Bit swapping
     * them makes them have 1 values in the left 24 bits, which
     * turns them into negative numbers.
     */
    printf("\nbitwise not:\n");
    printbyte(~val1);
    printbyte(~val2);
    printf("(truncated to bytes; read the source):\n");
    printbyte(~val1 & 0xff);
    printbyte(~val2 & 0xff);

    printf("\nbitwise and:\n");
    printbyte(val1 & val2);
    
    printf("\nbitwise or:\n");
    printbyte(val1 | val2);

    printf("\nexclusive or:\n");
    printbyte(val1 ^ val2);

    // note << and >> have higher precedence than &
    // See K&R table 2-1, "Precedence and Associativity of Operators"
    printf("\n%d shifted left 5 times:\n", val1);
    for (i = 1; i <= 5; i++)
        printbyte(val1 << i & 0xff);

    printf("\n%d shifted right 5 times:\n", val2);
    for (i = 1; i <= 5; i++)
        printbyte(val2 >> i & 0xff);

    return 0;
}
