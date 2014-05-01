#include <pm/pm.h>

main ()
{
  StdApp    *myApp = [[StdApp alloc] init];
  id         interface;
  StdDialog *dialog;
  /*
   * If using interface files, ALWAYS REGISTER the PM classes first!
   */
  registerClasses ();

  /*
   * load the interface file!
   */
  interface = [myApp loadIBFile: "ifsample.oib"];

  /*
   * now search for an object called "main dialog" in the interface file!
   * The keys are case-sensitive!
   */
  dialog = [interface objectForKey: "main dialog"];

  /*
   * bind the command of the pushbutton to the second dialog window, issuing
   * a runModalFor: call. Try both alternatives and see the difference!
   */

  /* 1. bind the command globally! This should be done when binding directly
   *    to runModalFor: The sending object is the dialog window itself!
   */
  [dialog bindCommand: 1000 withObject: [interface objectForKey: "anotherdlg"]
                              selector: @selector(runModalFor:)];

  /* 2. bind the button directly! This should be done in all other cases! It's
   *    much more cleaner! The sending object is the button! Just comment the
   *    lines above and uncomment the statement below to see the difference!
   */

/*
   [[dialog findFromID: 1000] bindWith: [interface objectForKey: "anotherdlg"]
                               selector: @selector(runModalFor:)];
 */

  /*
   * run the dialog, then exit!
   */
  [dialog runModalFor: nil];

  /*
   * free all resources
   */
  [interface free];
  [myApp free];
}
