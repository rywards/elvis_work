/* tangent.c - part of the "trig" project
 *
 * DFP
 */

#include <stdio.h>
#include <math.h>

static const char rcsid[] = "$Id: tangent.c,v 1.3 2020/04/07 13:32:17 edward74 Exp $";
void tangent(double angle)
{
  double angleRad=(angle * M_PI)/180;
  printf("tan(%lf) = %lf\n", angle, tan(angleRad));
}
