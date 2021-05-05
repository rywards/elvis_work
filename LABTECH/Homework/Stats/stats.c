/*
 * Original file stats_safest appended
 * by Ryan Edwards for Stats in C
 * assignment
 */


#include <stdio.h>

#define BUFSIZE 256

int main()
{
    int itemsread = 0;
    double item = -1;
    int howmany = 0;
    double max;
    double min;
    double sum = 0;
    double mean = 0;
    char line[BUFSIZE];

    // check last item wasn't zero; if not
    // read the line from input and copy it to memory as a string
    while ( item != 0 && fgets(line, BUFSIZE, stdin) != NULL) {

        // Note for Ryan: scanf is not sscanf -_-
        itemsread = sscanf(line, "%lf", &item);

        if (itemsread == 1 && item != 0) {
            if (howmany == 0) {
                min = item;
                max = item;
            }

            howmany++;

        }

        // min and max checking
        if (item > max && item != 0) {
            max = item;
        }

        if (item < min && item != 0) {
            min = item;
        }

        // tallying sum and mean
        sum = sum + item;
        mean = sum / howmany;

        if (itemsread == 0) {
            printf("badinput\n");
        }
    }

    if (howmany != 0) {
        printf("# items: %d\n", howmany);
        printf("Sum: %lf\n", sum);
        printf("Maximum: %lf\n", max);
        printf("Minimum: %lf\n", min);
        printf("Mean: %lf\n", mean);

    }else {
      printf("# items: %d\n", howmany);
    }

    return 0;
}
