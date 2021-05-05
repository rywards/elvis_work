/* passvalue.c - pass by value
 *
 * D Provine, 2011-03-08
 */

#include <stdio.h>

/* All C parameters are pass-by-value
 */

void swap_broken(int a, int b) // gets copies, won't work.
{
    int t;

    t = a;
    a = b;
    b = t;
    return;
}



void swap(int *a, int *b) // gets pointers, will work.
{// here b actually means &b, and *b =  *&b
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int A1 = 5;
    int B1 = 6;
    int a2 = 2;
    int b2 = 8;

    printf("A1 = %d, B1 = %d\n", A1, B1);
    swap_broken(A1, B1);
    printf("A1 = %d, B1 = %d\n", A1, B1);
    printf("a2 = %d, b2 = %d\n", a2, b2);
    swap(&a2, &b2);
    printf("a2 = %d, b2 = %d\n", a2, b2);
    swap(&A1, &B1);
    printf("a1 = %d, b1 = %d\n", A1, B1);

    return 0;
}
