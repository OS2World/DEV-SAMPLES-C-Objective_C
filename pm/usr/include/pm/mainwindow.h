#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#ifndef _STDWINDOW_H_
#include <pm/StdWindow.h>
#endif

@interface MainWindow : StdWindow
{
}

- initWithId: (ULONG) anId;
- initWithId: (ULONG) anId andFlags: (ULONG) flags;

- (MRESULT) handleMessage: (ULONG) msg
            withParams: (MPARAM) mp1 and: (MPARAM) mp2;

@end

#endif
