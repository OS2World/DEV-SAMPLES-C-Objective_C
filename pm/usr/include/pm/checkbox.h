#ifndef _CHECKBOX_H_
#define _CHECKBOX_H_

#ifndef _BUTTON_H_
#include <pm/Button.h>
#endif

@interface CheckBox : Button <Archiving>
{
}

- initWithId: (ULONG) anId andFlags: (ULONG) flags in: (Window *) parent;

/*
 * Methods for protocol "Archiving"
 */

- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;
- awake;

@end

#endif
