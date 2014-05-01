#ifndef _ENTRYFIELD_H_
#define _ENTRYFIELD_H_

#ifndef _FACTORYWINDOW_H_
#include <pm/FactoryWindow.h>
#endif

#ifndef _SELECTION_H_
#include <pm/Selection.h>
#endif

#ifndef _VALUE_H_
#include <pm/Value.h>
#endif

@interface EntryField : FactoryWindow <Selection,Archiving,Value>
{
  int textLimit;
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;

// protocol Selection
- clearSelection;
- copySelection;
- cutSelection;
- pasteSelection;

// methods for access to PM messages
- (BOOL) changed;
- (BOOL) readOnly;
- setReadOnly;
- setReadWrite;
- setTextLimit: (int) limit;
- (int) textLimit;

/*
 * Methods for querying and setting contents of Entryfield (protocol "Value")
 */

- (char *) stringValue;
- (int) intValue;
- (long) longValue;
- (float) floatValue;

- setStringValue: (char *) aValue;
- setIntValue: (int) aValue;
- setLongValue: (long) aValue;
- setFloatValue: (float) aValue;

/*
 * Methods for protocol "Archiving"
 */

- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
- awake;

- createInPMWindow: (HWND) hwnd;

- (MRESULT) handleMessage: (ULONG) msg
            withParams: (MPARAM) mp1 and: (MPARAM) mp2;

@end

#endif
