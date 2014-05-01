#include "Controller.h"
#include "gnuplot.h"

@implementation Controller

- init
{
  [super init];
  gnuplot = popen ("gnuplot.exe","w");
  return self;
}

- free
{
  pclose (gnuplot);
  return [super free];
}

- plot: sender
{
  char   *string;
  char   *leftX,*rightX;
  double  left,right;

  string = [[sender findFromID: IDD_PLOTSTRING] text: NULL];

  if ([[sender findFromID: IDD_RANGECHECK] checked]) {
    leftX = [[sender findFromID: IDD_LEFTX] text: NULL];
    rightX = [[sender findFromID: IDD_RIGHTX] text: NULL];

    if ((sscanf (leftX,"%lf",&left) == 1) &&
	(sscanf (rightX,"%lf",&right) == 1) &&
	(right > left)) {
      fprintf (gnuplot,"plot [%lf:%lf] %s\n",left,right,string);
    } else
      fprintf (gnuplot,"plot %s\n",string);

    free (leftX);
    free (rightX);
  } else
    fprintf (gnuplot,"plot %s\n",string);

  fflush (gnuplot);

  free (string);

  return self;
}

@end
