/* bits.c -- fun with bits!
 *
 * D Provine and his posse
 *
 * modified
 */

#include <stdio.h>

int main()
{
    int i;
    int val;
    int bitson = 0;

    printf("Enter a value: ");
    scanf("%d", &val);


    for (i = 0; i < 32; i++) {
        if ( val & ( 1 << i ) ) {
            bitson ++;
        }
    }

    printf("%d has %d bits switched on\n", val, bitson);

    for (i = 31; i >= 0; i--) {
        if ( val & ( 1 << i ) ) {
            printf("1");
        } else {
            printf("0");
        }
        if ( i % 4 == 0 )
            printf(" ");
    }
    printf("\n");

    return 0;
}

