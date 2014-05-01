#ifndef _COMBOBOX_H_
#define _COMBOBOX_H_

#ifndef _LISTBOX_H_
#include <pm/ListBox.h>
#endif

@interface ComboBox : ListBox <Archiving>
{
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;

- (HWND) entryField;
- (HWND) listBox;

/*
 * Methods for protocol "Archiving"
 */

- awake;
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;

- createInPMWindow: (HWND) hwnd;

@end

#endif
