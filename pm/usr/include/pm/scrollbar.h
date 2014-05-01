#ifndef _SCROLLBAR_H_
#define _SCROLLBAR_H_

#ifndef _FACTORYWINDOW_H_
#include <pm/FactoryWindow.h>
#endif

#define SBWIDTH WinQuerySysValue (HWND_DESKTOP,SV_CXVSCROLL)
#define SBHEIGHT WinQuerySysValue (HWND_DESKTOP,SV_CYHSCROLL)

@interface ScrollBar : FactoryWindow <Archiving>
{
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;

- (SHORT) position;
- (SHORT) lowerBound;
- (SHORT) upperBound;

- setPosition: (SHORT) position;
- setScrollbar: (SHORT) position withBounds: (SHORT) lower : (SHORT) upper;
- setThumbSizeForVisible: (SHORT) visible of: (SHORT) all;

/*
 * Methods for protocol "Archiving"
 */

- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
- awake;

- createInPMWindow: (HWND) hwnd;

@end

#endif
