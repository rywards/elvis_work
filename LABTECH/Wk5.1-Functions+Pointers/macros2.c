/*
macros2.c
Jake Levy

A short program to demonstrate one of the several possible issues with 
over-relying on Macro Expansion instead of well written code.

*/
#include <stdio.h>
#define sq(a) a*a

int square(int);

int main(){

  double side;
  printf("Enter a side of the square: ");
  scanf("%lf", &side);
  double result = side*side/sq(side);  //What do you THINK the result will be?
  printf("\n\nResult is: %lf\n\n", result);

  double answer = side*side/square(5);
    printf("\n\nAnswer is: %lf\n\n", answer);
}
int square(int x){
  return x*x;
}
