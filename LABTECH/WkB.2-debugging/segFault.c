#include <stdio.h>


int main(int argc, char * argv[]){

  // brings a seg fault because you are trying to print an int as char 
  printf("The number of args is %s", argc);

  return 0;
}

  
