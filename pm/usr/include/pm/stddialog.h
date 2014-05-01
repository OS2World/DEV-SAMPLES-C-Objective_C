#ifndef _STDDIALOG_H_
#define _STDDIALOG_H_

#ifndef _ACTIONWINDOW_H_
#include <pm/ActionWindow.h>
#endif

@interface StdDialog : ActionWindow <Archiving>
{
  ULONG   result;
  BOOL    running;

  ULONG   createFlags;
}

- initWithId: (ULONG) anId;
- initWithId: (ULONG) anId andFlags: (ULONG) flags;
- loadMenu;
- free;

- (ULONG) createFlags;
- setCreateFlags: (ULONG) flags;

- updateFrame;

- (ULONG) result;

- setTitle: (char *) aTitle;

- makeKeyAndOrderFront: sender;
- runModalFor: sender;
- dismiss: sender;
- (BOOL) running;

- centerOnScreen: sender;

/*
 * Methods for protocol "Archiving"
 */

- awake;
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;

- createInPMWindow: (HWND) hwnd;

- (MRESULT) handleMessage: (ULONG) msg
            withParams: (MPARAM) mp1 and: (MPARAM) mp2;

@end

MRESULT EXPENTRY __dialogFunction (HWND hwnd,ULONG msg,MPARAM mp1,MPARAM mp2);

#endif
