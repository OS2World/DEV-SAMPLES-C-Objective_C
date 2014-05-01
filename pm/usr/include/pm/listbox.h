#ifndef _LISTBOX_H_
#define _LISTBOX_H_

#ifndef _FACTORYWINDOW_H_
#include <pm/FactoryWindow.h>
#endif

@interface ListBox : FactoryWindow <Archiving>
{
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;
- insertItem: (SHORT) pos text: (const char *) buffer;
- (SHORT) count;
- (SHORT) selected;
- (SHORT) itemTextLength: (SHORT) pos;
- (char *) item: (SHORT) pos text: (char *) buffer;
- selectItem: (SHORT) pos;
- deleteItem: (SHORT) pos;
- deleteAll;

/*
 * Methods for protocol "Archiving"
 */

- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
- awake;

- createInPMWindow: (HWND) hwnd;

@end

#endif
