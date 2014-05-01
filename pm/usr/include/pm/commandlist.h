#ifndef _COMMANDLIST_H_
#define _COMMANDLIST_H_

#include <objc/os2.h>
#include <objc/Object.h>

typedef struct {
  id  target;
  SEL action;
} Command;

@interface CommandList : Object
{
  ULONG        key;
  void        *data;
  CommandList *next;
}

- init: (ULONG) aKey data: (void *) aData;
- free;

- insert: (CommandList *) element;
- (int) compare: (CommandList *) elem1 with: (CommandList *) elem2;

- find: (ULONG) aKey;

- setKey: (ULONG) aKey;
- setData: (void *) aData;
- setNext: (CommandList *) element;
- (ULONG) key;
- (void *) data;
- next;

/*
 * Methods for protocol "Archiving"
 */

- awake;
- read: (TypedStream *) aStream;
- write: (TypedStream *) aStream;

@end

#endif
