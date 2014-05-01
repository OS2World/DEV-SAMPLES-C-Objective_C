#ifndef _WINDOW_H_
#define _WINDOW_H_

#define INCL_PM
#define INCL_SPLDOSPRINT
#include <objc/os2.h>
#include <objc/Object.h>

#ifndef _ARCHIVING_H_
#include <pm/Archiving.h>
#endif

#define WINDOW_CLASS "ObjcWindow"

@interface Window : Object <Archiving>
{
  HWND    window;

  Window *child;
  Window *sibling;
  int     tag;

  SWP     windowSwp;
  char   *windowText;
  ULONG   pmId;
  ULONG   windowFlags;

  char   *presParam_font;
}

// initializers and destructors
- init;
- associate: (HWND) hwnd;
- free;

- destroy;

// user defined integer data: tag
- (int) tag;
- setTag: (int) aTag;

// methods concerning window hierarchy
- createObjects;
- insertChild: aChild;
- insertSibling: aSibling;
- deleteChild: aChild;
- deleteSibling: aSibling;

- findFromID: (ULONG) anId;
- findFromHWND: (HWND) aHwnd;

- setChild: (Window *) aChild;
- (Window *) child;
- setSibling: (Window *) aSibling;
- (Window *) sibling;

// methods for access to window words
- (char *) text: (char *) buffer;
- (int) textLength;
- setText: (const char *) buffer;
- setSize: (LONG) x : (LONG) y : (LONG) w : (LONG) h;
- setRect: (LONG) w : (LONG) h;
- size: (PSWP) aSize;
- (LONG) width;   // width of window
- (LONG) height;  // height of window
- (LONG) xoffset; // horizontal offset of lower left corner
- (LONG) yoffset; // vertical offset of lower left corner

- (PFNWP) windowProcedure; // address of window procedure
- (HMQ) messageQueue;      // handle of message queue
- (ULONG) windowStyle;     // window Style flags

- setWindowStyle: (ULONG) styleFlags; // set window style flags

// methods for access to instance variables
- (HWND) window;
- (ULONG) pmId;
- setPmId: (ULONG) anId;

// methods for access to PM messages
- enable;     // enable window
- disable;    // disable window
- activate;   // activate window
- deactivate; // deactivate window

// methods for controlling display behaviour of windows
- invalidate; // invalidate whole window rect
- show;       // show window
- hide;       // hide window

/*
 * Methods for protocol "Archiving"
 */

- awake;
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;

- createInPMWindow: (HWND) hwnd;

// message loop
- (MRESULT) handleMessage: (ULONG) msg
            withParams: (MPARAM) mp1 and: (MPARAM) mp2;

@end

MRESULT EXPENTRY __windowFunction (HWND hwnd,ULONG msg,MPARAM mp1,MPARAM mp2);

#endif
