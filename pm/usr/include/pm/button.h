#ifndef _BUTTON_H_
#define _BUTTON_H_

#ifndef _FACTORYWINDOW_H_
#include <pm/FactoryWindow.h>
#endif

#ifndef _COMMANDLIST_H_
#include <pm/CommandList.h>
#endif

@interface Button : FactoryWindow <Archiving>
{
  Command command;
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;

// methods for access to PM messages
- clickdown;
- clickup;
- (USHORT) checked;
- (BOOL) highlighted;
- check;
- checkIndeterminate;
- uncheck;

- setTarget: aTarget;
- setAction: (SEL) anAction;

- bindWith: anObject selector: (SEL) aSel;

- (MRESULT) handleMessage: (ULONG) msg
            withParams: (MPARAM) mp1 and: (MPARAM) mp2;

/*
 * Methods for protocol "Archiving"
 */

- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
- awake;

- createInPMWindow: (HWND) hwnd;

@end

#endif
