
#include <stdio.h>
#include <stdlib.h>
/***************************
StrctPtr.c 
Apr 2020
Jake Levy

A file to demonstrate how we would use 
struct pointer syntax to reduce confusion
***************************/
typedef struct{
  int xValue;
  int yValue;
} point;


typedef struct{
  double radius;
  point origin;
} circle;

void setCenter( circle * entered);

int main(int argc, char * argv){

  circle newCircle;
  
  setCenter(&newCircle);

  printf("\n\nX Origin: %d", newCircle.origin.xValue);
  printf("\nY Origin: %d\n\n", newCircle.origin.yValue);
  return 0;
  
}

//A simple function to demonstrate how to use arrow syntax
void setCenter(circle * entered){
  int x;
  int y;
  printf("Please enter a number for x: ");
  scanf("%d", &x);
  //if we want to access member/attribute of a struct pointer
  //things can get confusing.

  //Wrong: "The address pointed at by entered's member, the xOrigin pointer"
  //*entered.xOrigin = x;
  //The . operator has higher precedence than *
  
  //Right: "The member xOrigin of the structure pointed at by entered"
  (*entered).origin.xValue = x;
   printf("Please enter a number for y: ");
  scanf("%d", &y);

  //An easier way to access members of sturcture pointers is with Arrow syntax

  entered->origin.yValue = y;

  //Think of the arrow as "going through" entered (a pointer) to get the
  //value of the structure that is being pointed at
}
