#ifndef _FILEDLG_H_
#define _FILEDLG_H_

#ifndef _WINDOW_H_
#include <pm/Window.h>
#endif

@interface FileDlg : Object
{
  FILEDLG  fileDlg;
}

- init;
- initForOpen: (const char *) aTitle withFilter: (char *) aFilter;
- initForSaveAs: (const char *) aTitle withFilter: (char *) aFilter;
- setTitle: (char *) aTitle;
- setFilter: (char *) aFilter;
- setFlags: (ULONG) aFlags;
- setOKTitle: (const char *) aTitle;
- runModalFor: sender;
- (char *) fileName;
- (ULONG) result;

@end

#endif
