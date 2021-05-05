#include <stdlib.h>
#include <stdio.h>
/*
ptr.c
Demos the basic use of pointers and how they work.
jake Levy

Jan 2020
*/
int main(){

  int x = 5;
  int * y = &x;

  printf("y points to address: %d\n ", y);
  printf("the address y points at holds the value: %d\n\n", *y); 
}
