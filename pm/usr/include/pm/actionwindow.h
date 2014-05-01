#ifndef _ACTIONWINDOW_H_
#define _ACTIONWINDOW_H_

#ifndef _DELEGATEWINDOW_H_
#include <pm/DelegateWindow.h>
#endif

#ifndef _COMMANDLIST_H_
#include <pm/CommandList.h>
#endif

@interface ActionWindow : DelegateWindow <Archiving>
{
  CommandList *commandBindings;
}

- init;
- free;

- bindCommand: (ULONG) command withObject: anObject selector: (SEL) aSel;
- findCommandBinding: (ULONG) command;
- (MRESULT) execCommand: (ULONG) command;

/*
 * Methods for protocol "Archiving"
 */

- awake;
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;

@end

#endif
