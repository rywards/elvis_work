/* sine.c - part of the "trig" project
 *
 * DFP
 */

#include <stdio.h>
#include <math.h>

void sine(double angle)
{
  double angleRad=(angle * M_PI)/180;
  printf("sin(%lf) = %lf\n", angle, sin(angleRad));
}
