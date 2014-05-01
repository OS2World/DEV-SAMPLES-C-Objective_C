#ifndef _HELP_H_
#define _HELP_H_

#include <pm/StdApp.h>

#define DEFAULT_HELPTABLE 1000

@interface Help : Object
{
  BOOL helpEnabled;
  HWND helpInstance;
}

- initForApp: (StdApp *) anApp helpFile: (char *) fileName;
- initForApp: (StdApp *) anApp helpFile: (char *) fileName
   withTitle: (char *) helpTitle;
- initForApp: (StdApp *) anApp helpFile: (char *) fileName
   withTitle: (char *) helpTitle helpTable: (ULONG) helpTableID;

- free;

- associateWith: aWindow;

- helpForHelp: sender;
- helpExtended: sender;
- helpIndex: sender;
- helpFor: sender;
- helpForTopic: (int) topic;

@end

#endif
