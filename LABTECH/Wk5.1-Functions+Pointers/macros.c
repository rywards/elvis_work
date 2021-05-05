/*macros.c
Jake Levy
September 2019

A short program demonstrating how macros can be used within C programs.
Note that macros have some caveats:

Arguments to macros are frowned upon because Macros are not evaluated
in the same way inline functions are.  It can be confusing for readers (and
writers) of the code
   -A macro is loosely typed and therefore can introduce bugs if not handled
with care.
   -Macros are expanded FIRST *without* evaluating the arguments. See macros2.c

The arguments  passed to a macro can be concatenated with operator ##. 
(E.G. #define  CAT(a, b) a##b -  CAT(cat, dog) RETURNS catdog)

# operator can convert to a string literal
(E.G. #define TOSTRING(a) #a - TOSTRING(543) RETURNS "543" )

*/
#include <stdio.h>
#define min(a, b)  ((a) < (b)) ? (a) : (b)  //A macro for min values

int main(){
 double x;
 double y;
 printf("Please enter two values:");
   
  scanf("%lf", &x);
  printf("\n");
  scanf("%lf", &y);
  //The macro (despite not being typed) works for float values
  printf("The smaller value is, %lf\n", min(x, y));

  char q;
  char r;
  printf("Please enter two values:");
   
  scanf(" %c", &q);  //Note the preceding space in this scanf
  printf("\n");     // When scanning characters %c does not skip whitespace
  scanf(" %c", &r); //so when it scans the buffer it "sees" the \n character
  //immediately and thinks it is done scanning.  The preceding space "burns"
  //that character.

  //The thing to note is that the macro still works for characer values
  printf("The smaller value is, %c\n", min(q, r));
}
