/* tangent.c - part of the "trig" project
 *
 * DFP
 */

#include <stdio.h>
#include <math.h>

static const char rcsid[] = "$Id: tangent.c,v 1.2 2020/04/07 13:00:07 edward74 Exp edward74 $";
void tangent(double angle)
{
  double angleRad=(angle * M_PI)/180;
  printf("tan(%lf) = %lf\n", angle, tan(angle));
}
