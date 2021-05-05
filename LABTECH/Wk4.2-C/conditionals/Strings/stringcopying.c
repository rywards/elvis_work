/** copy.c
 * An Example file to demonstrate some of the pitfalls
 * of String copying in C.
 * Jake Levy
 * Jan 2020

 * One of the biggest source of problems with beginning
 * C programmers, like with most beginners,  is that they
 * often do not fully read the documentation for functions
 * that they are using.  This is a huge source of errors because
 * C gives you just the right tools to allow you to "shoot yourself
 * in the foot".  

 * Therefore, there are several C library functions that will allow
 * programmers to perform what would otherwise should be
 * blatantly incorrect operations. String and IO methods such as 
 * strcpy, strcat, gets, sprintf, and others are perfect examples.
 * None the aforementioned methods perform bounds-checking and thus
 * can easily cause array overflow errors.

  FROM THE MAN PAGE:
    **If the destination string of a strcpy() is not large enough, 
    then any thing  might  happen.**
 **/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char buf1[] = "Goodbye!"; //Source String
    char buf2[3];//Destination Stringx



    /* The behavior of strcpy(and strcat) is "undefined"
     * when copying from a source string that is larger than
     * the destination string.  Despite this, doing so DOES NOT result in
     * a compilation error. In other words, it is allowed.
     */
    strcpy(buf2, buf1);

    //Instead you end up with what may be "weird" results.
    printf("%s and %s\n", buf1, buf2);
    printf("Size of buf1: %d \n Size of buf2: %d\n\n", sizeof(buf1),
           sizeof(buf2)); //Array sizes are correct
    printf("Length of buf1: %d \n Length of buf2: %d\n\n", strlen(buf1),
           strlen(buf2)); //but they don't match up with string sizes

    /*Its worth noting that different Unix flavors may have different responses
     * Running this program in BSD Unix results in a runtime error:
     * Abort trap: 6
     * Which means that the compiler still allows it.
     */

    /*Additionally, strcat & sprintf are susceptible to the same issue.
     * You must make sure that your destination array is large enough to
     * receive the information you want to place into it.
     */

    char good[5] = "Good"; // str length of 4  +'\n'  = 5 length char array

    //The string below is large enough to generate a run time error in most
    //instances.  However, smaller strings may not always generate a run-
    //time error immediately, instead introducing "weird bugs" into code
    char morn[] =
        "Morning and if I don't see ya, Good Afternoon, Good Evening, and Good Night!";
    //uncomment the following 2 lines of code for class demo
    //    strcat(good, morn); //copies from source (morn) to destination (good)
    //    printf("Result: %s", good);  //causes segfault error

    /*
     * Instead you should use the bounds-checked versions of these methods:
     * strncpy, strncat, etc whenever possible  and ensure there is enough
     * room in the destination array.
     */
    char buf3[9];
    char buf4[] = "Goodbye!";
    strncpy(buf3, buf4, 8);
    buf3[8] = '\0';
    
    printf("\n\nBuff3 says %s and is %d long\n", &buf3, strlen(buf3));
    /*However, there is still an issue.  the n-length versions of these
     methods DO NOT guarantee that the result will be null-terminated.
     
     In other words, strncpy (above) copied 8 characters from the source
     array and thats it.  It did not add a '\0' at the end of buf3. We
     may get lucky and one might already exist in that memory address
     but it should not be left to chance, so a null terminator was added.
    */
    
    /*
       If there is no guarantee there will be enough room in the destination
       (and if getting the full source is not critical) then to copy as 
       much as you can, do the following.

       If there's not enough room in the destination and all of the copied
       data is critical then the program has an inherent flaw.
     */
    char goodDest[100] = "Good"; //try changing the length to 50 
    int destLen = strlen(goodDest);
    int destSize = sizeof(goodDest);
    strncat(goodDest, morn, abs(destSize - destLen));
    goodDest[destLen + strlen(morn)] = '\0';

    printf("Result: %s \n Length: %d\n", &goodDest, strlen(goodDest));

    /*
      Note that on some systems(not Elvis), strlcpy, strlcat, and snprintf
      exist.  These methods  work like their analogs (that we have used)
      but like fgets they "know" about the null terminating char.  So
      they copy up to size-1 chars and then add '\0'.  If available,
      these are preferred.
     */
    return (0);
}
