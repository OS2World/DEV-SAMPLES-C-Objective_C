#ifndef _STDWINDOW_H_
#define _STDWINDOW_H_

#ifndef _ACTIONWINDOW_H_
#include <pm/ActionWindow.h>
#endif

@interface StdWindow : ActionWindow
{
  HWND       frame;
}

- initWithId: (ULONG) anId;
- initWithId: (ULONG) anId andFlags: (ULONG) flags;
- free;

- (char *) text: (char *) buffer;
- (int) textLength;
- setText: (const char *) buffer;
- setSize: (LONG) x : (LONG) y : (LONG) w : (LONG) h;
- setRect: (LONG) w : (LONG) h;

- (PFNWP) windowProcedure; // address of window procedure
- (HMQ) messageQueue;      // handle of message queue
- (ULONG) windowStyle;     // window Style flags

- setWindowStyle: (ULONG) styleFlags; // set window style flags

// methods for access to instance variables
- (ULONG) pmId;
- setPmId: (ULONG) anId;

// methods for access to PM messages
- enable;     // enable window
- disable;    // disable window
- activate;   // activate window
- deactivate; // deactivate window

// methods for controlling display behaviour of windows
- invalidate; // invalidate whole window rect
- show;
- hide;

- (LONG) framexoffset; // horizontal offset of lower left corner
- (LONG) frameyoffset; // vertical offset of lower left corner
- (LONG) framewidth;   // width of window
- (LONG) frameheight;  // height of window

- (HWND) frame;

- setTitle: (char *) aTitle;

- makeKeyAndOrderFront: sender;
- performClose: sender;
- performQuit: sender;

- centerOnScreen: sender;

/*
 * Methods for protocol "Archiving"
 */

- awake;
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;

- (MRESULT) handleMessage: (ULONG) msg
            withParams: (MPARAM) mp1 and: (MPARAM) mp2;

@end

#endif
