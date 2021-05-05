/* main.c - main section of "trig" project
 *
 * DFP
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static const char rcsid[]= "$Id: main.c,v 1.11 2020/04/07 14:40:32 edward74 Exp $";
int main(int argc, char *argv[])
{
  double angle;
  void sine(double), cosine(double), tangent(double);
  
  if (argc < 2) {
      angle = 45.0;
  } else {
      //angle = (double) atof(argv[1]);
      angle = strtod(argv[1], NULL);
  }

  double radians=(angle * M_PI)/180;
  printf("Angle in degrees: %lf\n", angle);
  printf("Angle in radians: %lf\n", radians);
  
  sine(angle);
  cosine(angle);
  tangent(angle);

  return 0;
}
