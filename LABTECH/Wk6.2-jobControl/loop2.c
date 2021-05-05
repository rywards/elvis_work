/*
loop2.c 
An example of how to NOT write a loop

Jake Levy
*/
#include <stdio.h>

int main(){
 

  int item;
  int x = 10;
 
  while ( x > 0){

    if (x % 3 == 0){
      printf("%d is divisible by 3!");
    }
    printf("This is gonna get messy!\n");

    if (x == 200000){
      scanf("%d", &item);
    }
    x+=1;
  }
  
}
