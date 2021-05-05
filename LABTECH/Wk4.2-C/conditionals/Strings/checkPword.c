/*checkPword.c
 * Jake Levy
 * Jan 2020
 
 * This is an example of a weird but subtle error
 * that can occur if you are not careful and make
 * your destination buffer too small. Like bufferOverflow.c
 * this issue has to do with overflowing a buffer.  
 * In this case, in the stack frame, the password 
 * buffer sits in front of the name buffer.  Watch
 * what happens when you enter the correct user name
 * and correct password. 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int checkPword(char * name, char * pwrd);
int main(int argc, char * argv[]){

  if (argc <= 2 || argc > 3){
    printf ("ERROR!  Usage: ./checkPwrd name password");
    exit(1);
  }
  
  int result;
  char nbuff[10];
  char pbuff[12];

  //strcpy will copy everything in the source until it
  //encounters a '\0'
  strcpy(nbuff, argv[1]);
  strcpy(pbuff, argv[2]);

  result = checkPword(nbuff, pbuff);
  
  if (result){
         printf("you entered\n name: %s \n pword: %s", &nbuff , &pbuff);
  }else {
    printf("Granted Root Access");
  }
	 
  return 0;
}

int checkPword(char * name, char * pwrd){
 

  char stored[] = "NotAGoodPwrd";
  char user[] = "levyj63";



  int n =  strcmp(name, user);
  int p = strcmp(pwrd, stored);
 
  if ((n == 0) && (p == 0)){
    return 0;
  } else{
    return 1;
  }
}
