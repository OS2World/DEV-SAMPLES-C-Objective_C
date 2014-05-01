#include <pm/pm.h>


#include "gnuplot.h"
#include "controller.h"

main()
{
  StdApp     *application = [[StdApp alloc] init];
  StdDialog  *mainDialog = [[StdDialog alloc] initWithId: IDD_MAIN];
  Controller *controller = [[Controller alloc] init];

  [mainDialog createObjects];

  [mainDialog bindCommand: DID_OK withObject: controller
                 selector: @selector(plot:)];

  [mainDialog runModalFor: nil];

  [controller free];
  [mainDialog free];
  [application free];
}
