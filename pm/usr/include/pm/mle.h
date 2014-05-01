#ifndef _MLE_H_
#define _MLE_H_

#ifndef _FACTORYWINDOW_H_
#include <pm/FactoryWindow.h>
#endif

@interface MultiLineEntryField : FactoryWindow <Archiving>
{
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;

/*
 * Methods for protocol "Archiving"
 */

- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
- awake;

- createInPMWindow: (HWND) window;

@end

#endif
