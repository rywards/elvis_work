/* bufferOverflow.c
 * Jake Levy
 * Jan 2020


 * Another example of what can happen when you use functions
 * that do not implement bounds checking.  This is a simple,
 * trivial example of a "buffer overflow attack".  The idea is
 * simple.  Remember that method calls (including the call to
 * main) are organized into "frames" on a "stack". The
 * actual organization of a frame is beyond the scope of this
 * class but, understand that all variables in a frame are
 * located in (physically) contiguous memory addresses. Since
 * the gets function performs no bounds checking, overflowing
 * both of the buffers by at least 1 char each guarantees
 * some data being written into the "pass" variable. Thus, 
 * making it evaluate as true, no matter what. Attackers can
 * exploit this vulernability to "inject" code into programs,
 * and hijack permissions or perform other nefarious actions.

 * This is yet ANOTHER reason why you should be grabbing user data
 * with fgets and sscanf.  
 * The compiler even tells you: "the `gets' function is dangerous 
 * and should not be used."
 * Look at stats_safest.c for more info.

 * This code is adapted from an example found at:
 * https://www.thegeekstuff.com/2013/06/buffer-overflow/
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int checkUserData(char * name, char * pwrd);
int main(int argc, char * argv)
{

    char enteredName[10];
    char enteredPass[15];
    int pass = 0;

    if (argc > 1) {
        printf("Error! Usage: ./checkPwrd2");
        exit(1);
    }

    printf("Please enter User Name:");
    gets(enteredName);
    printf("Please enter password:");
    gets(enteredPass);



    if (checkUserData(enteredName, enteredPass)) {
        printf("\nYour userName and password do not match our records\n");
    } else {
      printf("\n\nWelcome %s!\n", enteredName);
        pass = 1;
    }

    if (pass) {
        printf("\n\nRoot Privileges Granted\n");
    }

    return 0;
}
int checkUserData(char * name, char * pwrd)
{


    char stored[] = "NotAGoodPwrd";
    char user[] = "levyj63";


    //A better comparison to make would be with strncmp
    //But that won't fix this program's issues
    
    int n =  strcmp(name, user); 
    int p = strcmp(pwrd, stored);  

    if ((n == 0) && (p == 0)) {
        return 0;
    } else {
        return 1;
    }
}
