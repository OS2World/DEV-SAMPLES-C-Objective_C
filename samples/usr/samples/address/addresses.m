#include <pm/pm.h>

#include "Controller.h"
#include "address.h"

main()
{
  StdApp *addresses = [[StdApp alloc] init];
  MainWindow *mainWindow = [[MainWindow alloc] initWithId: IDD_MAIN
			 andFlags: (FCF_MENU | FCF_ACCELTABLE |
				    FCF_SIZEBORDER)];
  Controller *controller = [[Controller alloc] init];

  [mainWindow setTitle: "Addresses"];

  [mainWindow setDelegate: controller];
  [mainWindow bindCommand: IDM_EXIT withObject: controller 
                 selector: @selector(closeApp:)];
  [mainWindow bindCommand: IDM_NEWAD withObject: controller 
                 selector: @selector(insert:)];
  [mainWindow bindCommand: IDM_EDITAD withObject: controller 
                 selector: @selector(replace:)];
  [mainWindow bindCommand: IDM_INFOAD withObject: controller 
                 selector: @selector(info:)];
  [mainWindow bindCommand: IDM_DELETEAD withObject: controller 
                 selector: @selector(delete:)];

  [mainWindow createObjects];

  [mainWindow insertChild: [[ListBox alloc] initWithId: IDD_PUSHBUTTON1
			  andFlags: WS_VISIBLE | WS_TABSTOP
			  in: mainWindow]];

  [controller readList: mainWindow];

  [mainWindow makeKeyAndOrderFront: nil];

  [addresses run];

  [mainWindow free];
  [addresses free];
}
