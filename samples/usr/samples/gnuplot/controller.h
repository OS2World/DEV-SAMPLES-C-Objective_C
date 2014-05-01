#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <pm/pm.h>
#include <stdio.h>

@interface Controller : Object
{
  FILE *gnuplot;
}

- init;
- free;
- plot: sender;

@end

#endif
