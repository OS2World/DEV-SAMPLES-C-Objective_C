#ifndef _SPINBUTTON_H_
#define _SPINBUTTON_H_

#ifndef _FACTORYWINDOW_H_
#include <pm/FactoryWindow.h>
#endif

@interface SpinButton : FactoryWindow <Archiving>
{
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;

/*
 * Methods for protocol "Archiving"
 */

- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
- awake;

- createInPMWindow: (HWND) hwnd;

@end

#endif
