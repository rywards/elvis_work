/* cosine.c - part of the "trig" project
 *
 * DFP
 */

#include <stdio.h>
#include <math.h>

// This gets rcs information
static const char rcsid[] = "$Id: cosine.c,v 1.5 2020/04/07 13:40:39 edward74 Exp $";
void cosine(double angle)
{
  double angleRad=(angle * M_PI)/180;
  printf("cos(%lf) = %lf\n", angle, cos(angleRad));
}
