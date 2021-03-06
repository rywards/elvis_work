/* by_val.c -- everything passed by value
 *
 * DFP
 * 
 * All Data in C is passed by value.  
 * Modified- Jake Levy
 * 
 */

#include <stdio.h>

void modify_wrong(int x)
{
    x *= 2;
    printf("Inside modify Wrong, %d\n",x);
}

void modify_right(int *x)
{
    *x *= 2;
        printf("Inside modified right: %d\n", *x);
    //this is like saying *(&i)
}

int main()
{
    int i = 0;

    printf("Enter an integer: ");
    scanf("%d", &i);

    printf("You entered %d\n\n", i);

    modify_wrong(i);
    printf("Outside modified wrong: %d\n", i);
    
    // note "address of"
    modify_right(&i);
    printf("outside modified right: %d\n", i);

    return 0;
}
