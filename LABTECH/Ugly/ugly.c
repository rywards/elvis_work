/* 

ugly.c appended and edited by Ryan Edwards

For Ugly Code assignment Jacob Levy
*/


#include <stdio.h>
#include <ctype.h>

struct charStruct {
    char ch;    /* ch is a character */
    int frequency;     /* a number */
};

int procesortChar_data(char input, struct charStruct charArray[], int s);
void sortChar(struct charStruct charArray[], int s);

int main()
{
    int s = 0;
    struct charStruct charArray[200];
    char input;
    int i, l;

    /* Loop until end of file */
    while ((input = getchar()) != EOF) {
        l = procesortChar_data(input, charArray, s);

        if (l >= 0) {
            charArray[l].ch = input;
            charArray[l].frequency++; /* Increment fr */
        } else {
            charArray[s].ch = input;
            charArray[s].frequency = 1;
            s++;
        }
    }

    /* Call sortChar function */
    sortChar(charArray, s);

    /* Print answer */
    return 0;
}

int procesortChar_data(char input, struct charStruct charArray[], int s)
{
    int i;

    for (i = 0; i < s; i++) {
        if (charArray[i].ch  == input) {  /* Compare charArray[i].ch to lc */
            return i;
        }
    }

    return -1;
}

void sortChar(struct charStruct charArray[], int s)
{
    int f, i, x, digitCount = 0, letterCount = 0;
    struct charStruct sortedArray;

    // This sorts the characters from greatest to least
    for (f = 0; f < s - 1; f++) {
        /* Get next x */
        x = f;

        for (i = f + 1; i < s; i++) {
            if (charArray[i].frequency > charArray[x].frequency) {
                x = i;
            }
        }

        /* Swap values */
        sortedArray = charArray[f];
        charArray[f] = charArray[x];
        charArray[x] = sortedArray;



    }

    // Go through sorted array and grab first occurrence of each

    for (f = 0; f < s - 1; f++) {

        if (isdigit(charArray[f].ch) && digitCount == 0) {
            printf("Most frequent digit: %c\n", charArray[f].ch);
            digitCount++;
        }

        if (isalpha(charArray[f].ch) && letterCount == 0) {
            printf("Most frequent letter: %c\n", charArray[f].ch);
            letterCount++;
        }
    }

}



